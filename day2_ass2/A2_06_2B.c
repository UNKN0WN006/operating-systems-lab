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
#include <string.h>
#include <errno.h>

#define BUF 4096

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

    mkfifo(fifo1, 0666);
    mkfifo(fifo2, 0666);

    struct timeval start, end;
    gettimeofday(&start, NULL);

    if (fork() == 0) {
        char buf[BUF];
        int in = open(fifo1, O_RDONLY);
        int out = open(fifo2, O_WRONLY);
        ssize_t n;

        while ((n = read(in, buf, BUF)) > 0)
            write(out, buf, n);

        close(in); close(out);
        exit(0);
    }

    char buf[BUF];
    int src_fd = open(src, O_RDONLY);
    int to_child = open(fifo1, O_WRONLY);
    ssize_t n;

    while ((n = read(src_fd, buf, BUF)) > 0)
        write(to_child, buf, n);

    close(src_fd); close(to_child);

    int from_child = open(fifo2, O_RDONLY);
    int dest_fd = open(dest, O_CREAT | O_WRONLY | O_TRUNC, 0666);

    while ((n = read(from_child, buf, BUF)) > 0)
        write(dest_fd, buf, n);

    close(from_child); close(dest_fd);

    wait(NULL);

    gettimeofday(&end, NULL);
    double time = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec)/1e6;

    printf("Time taken: %.2f sec\n", time);

    if (system("cmp bigfile.dat received.dat") == 0)
        printf("File returned successfully\n");
    else
        printf("File mismatch\n");

    return 0;
}


