/***********************************************************************
 * Team No       : 06
 * Team Members  :
 *   - Anay Saha (002311001054)
 *   - Debarshi Mondal (002311001055)
 *   - Sushar Hembram (002311001041)
 *
 *   Date: 30/07/2025
 * Assignment 2B : IPC using named pipe (FIFO)
 *
 * Objective     :
 *   This program demonstrates Inter-Process Communication (IPC) between a parent and child process using two Named Pipes (FIFOs). The steps are:
 *
 *     1. The parent process reads a 1GB file (`bigfile.dat`) and sends it to the child through FIFO1.
 *     2. The child process receives this data from FIFO1 and sends it back to the parent through FIFO2.
 *     3. The parent writes the received data to a new file (`received.dat`).
 *     4. The two files are compared using the `cmp` command to confirm data integrity.
 *     5. The total time taken for this round-trip transfer is measured and displayed.
 *
 * Compilation   :
 *     gcc A2_06_2B.c
 * 
 * Execution     :
 *     ./a.out
 *
 * Sample Output :
 *     Time taken: 7.38 sec
 *     File returned successfully
 *
 * Notes         :
 *     - Ensure FIFO files (`fifo1` and `fifo2`) and `bigfile.dat` exist.
 *     - You may generate a 1GB file using:
 *         dd if=/dev/zero of=bigfile.dat bs=1M count=1024
 ***********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>   //For open() flags like we have used o_RDONLY
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/types.h>
#include <string.h>
#include <errno.h>

#define BUF 65536

void check(int result, const char *msg) {
    if (result == -1) {
        perror(msg);
        exit(1);
    }
}

int main() {
    char *fifo1 = "fifo1";
    char *fifo2 = "fifo2";
    char *src = "bigfile.dat";
    char *dest = "received.dat";

    if (mkfifo(fifo1, 0666) == -1 && errno != EEXIST) {
        perror("mkfifo fifo1");
        return 1;
    }
    if (mkfifo(fifo2, 0666) == -1 && errno != EEXIST) {
        perror("mkfifo fifo2");
        /* cleanup fifo1 if we created it */
        unlink(fifo1);
        return 1;
    }

    struct timeval start, end;
    gettimeofday(&start, NULL);

    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        unlink(fifo1); unlink(fifo2);
        return 1;
    }

    if (pid == 0) {
        /* Child: read from fifo1 and write to fifo2 */
        char buf[BUF];
        int in = open(fifo1, O_RDONLY);
        if (in == -1) {
            perror("child: open fifo1");
            exit(1);
        }
        int out = open(fifo2, O_WRONLY);
        if (out == -1) {
            perror("child: open fifo2");
            close(in);
            exit(1);
        }

        ssize_t n;
        while ((n = read(in, buf, BUF)) > 0) {
            ssize_t written = 0;
            while (written < n) {
                ssize_t w = write(out, buf + written, n - written);
                if (w == -1) {
                    if (errno == EINTR) continue;
                    perror("child: write to fifo2");
                    close(in); close(out);
                    exit(1);
                }
                written += w;
            }
        }
        if (n == -1) perror("child: read from fifo1");

        close(in); close(out);
        exit(0);
    }

    /* Parent: open fifo2 (read end) BEFORE opening fifo1 (write end) to avoid deadlock */
    char buf[BUF];

    int from_child = open(fifo2, O_RDONLY);
    if (from_child == -1) {
        perror("parent: open fifo2");
        /* cleanup and kill child */
        kill(pid, SIGTERM);
        waitpid(pid, NULL, 0);
        unlink(fifo1); unlink(fifo2);
        return 1;
    }

    int src_fd = open(src, O_RDONLY);
    if (src_fd == -1) {
        perror("open src");
        close(from_child);
        kill(pid, SIGTERM);
        waitpid(pid, NULL, 0);
        unlink(fifo1); unlink(fifo2);
        return 1;
    }

    int to_child = open(fifo1, O_WRONLY);
    if (to_child == -1) {
        perror("parent: open fifo1");
        close(src_fd); close(from_child);
        kill(pid, SIGTERM);
        waitpid(pid, NULL, 0);
        unlink(fifo1); unlink(fifo2);
        return 1;
    }

    ssize_t n;
    while ((n = read(src_fd, buf, BUF)) > 0) {
        ssize_t written = 0;
        while (written < n) {
            ssize_t w = write(to_child, buf + written, n - written);
            if (w == -1) {
                if (errno == EINTR) continue;
                perror("parent: write to fifo1");
                close(src_fd); close(to_child); close(from_child);
                kill(pid, SIGTERM);
                waitpid(pid, NULL, 0);
                unlink(fifo1); unlink(fifo2);
                return 1;
            }
            written += w;
        }
    }
    if (n == -1) perror("parent: read src");

    close(src_fd);
    /* finished writing to child */
    close(to_child);

    int dest_fd = open(dest, O_CREAT | O_WRONLY | O_TRUNC, 0666);
    if (dest_fd == -1) {
        perror("open dest");
        close(from_child);
        waitpid(pid, NULL, 0);
        unlink(fifo1); unlink(fifo2);
        return 1;
    }

    while ((n = read(from_child, buf, BUF)) > 0) {
        ssize_t written = 0;
        while (written < n) {
            ssize_t w = write(dest_fd, buf + written, n - written);
            if (w == -1) {
                if (errno == EINTR) continue;
                perror("parent: write dest");
                close(dest_fd); close(from_child);
                waitpid(pid, NULL, 0);
                unlink(fifo1); unlink(fifo2);
                return 1;
            }
            written += w;
        }
    }
    if (n == -1) perror("parent: read from fifo2");

    /* ensure data is on disk before cmp */
    if (fsync(dest_fd) == -1) perror("fsync dest");

    close(from_child); close(dest_fd);

    int status = 0;
    waitpid(pid, &status, 0);
    if (!WIFEXITED(status) || WEXITSTATUS(status) != 0) {
        fprintf(stderr, "child exited abnormally\n");
    }

    gettimeofday(&end, NULL);
    double time = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec)/1e6;

    printf("Time taken: %.2f sec\n", time);

    if (system("cmp bigfile.dat received.dat") == 0)
        printf("File returned successfully\n");
    else
        printf("File mismatch\n");
    /* cleanup FIFOs */
    unlink(fifo1);
    unlink(fifo2);

    return 0;
}


