/*
Team: 06
Team Members:
    1. Anay Saha         Roll No: 002311001054
    2. Sushar Hembram    Roll No: 002311001041
    3. Debarshi Mondal   Roll No: 002311001055

Date: 05.09.2025

Assignment  : 5 - Thread, Synchronization & Shared Memory

Objective:
    - Create a main process that generates N random pairs (X, Y).
    - Use System V shared memory to share data between threads.
    - Spawn three threads:
        - Thread 1 computes A = X * Y
        - Thread 2 computes B = 2 * X + 2 * Y + 1
        - Thread 3 computes C = B / A
    - Synchronize threads so each phase completes before moving to the next pair.
    - Display results in a tabular format.
    - Allow time to observe the shared memory segment using ipcs -m before cleanup.

Input       : N (number of random pairs), provided as a command line argument
Output      : Table of (X, Y), A, B, C values for each pair

Compilation : gcc question.c -lpthread
Execution   : ./question N

Sample Input and Output: 

@UNKN0WN006 ➜ /workspaces/operating-systems-lab/day5_ass5 (main) $ gcc question.c -lpthread
@UNKN0WN006 ➜ /workspaces/operating-systems-lab/day5_ass5 (main) $ ./a.out
Usage: ./a.out N
N = number of random pairs (1-10)
@UNKN0WN006 ➜ /workspaces/operating-systems-lab/day5_ass5 (main) $ ./a.out 5
Pairs(X,Y) |  A  |  B  |   C
-------------------------------
(6, 9)    | 54 | 31 | 0.57
(1, 4)    |  4 | 11 | 2.75
(3, 0)    |  0 |  7 | 0.00
(7, 5)    | 35 | 25 | 0.71
(4, 4)    | 16 | 17 | 1.06

For the shared memory implementation:
@UNKN0WN006 ➜ /workspaces/operating-systems-lab/day5_ass5 (main) $ ipcs -m

------ Shared Memory Segments --------
key        shmid      owner      perms      bytes      nattch     status      

@UNKN0WN006 ➜ /workspaces/operating-systems-lab/day5_ass5 (main) $ ipcs -m

------ Shared Memory Segments --------
key        shmid      owner      perms      bytes      nattch     status      
0x000004d2 4          codespace  666        320        1                       



System Calls Used:
    shmget, shmat, shmdt, shmctl - for shared memory (man shmget)
    pthread_create, pthread_mutex, pthread_cond - for threads & sync (man pthread_create)
    perror - for error reporting (man perror)
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <time.h>

/* Maximum number of pairs */
#define MAX_PAIRS 10

/* Structure to hold computation for each pair */
typedef struct {
    int x, y, a, b;
    float c;
} Pair;

/* Shared memory structure */
typedef struct {
    Pair pairs[MAX_PAIRS];
    int n;          // Number of pairs
    int idx;        // Current index
    int phase;      // 0: A, 1: B, 2: C
    int done[3];    // Flags for thread completion
    int exit_flag;  // Signal threads to exit
    pthread_mutex_t mutex;
    pthread_cond_t cond;
} Shared;

/* Pointer to shared memory */
Shared *sh;

/* Thread to compute A = X * Y */
void* thread_a(void* arg) {
    while (1) {
        pthread_mutex_lock(&sh->mutex);

        while (sh->phase != 0 && !sh->exit_flag)
            pthread_cond_wait(&sh->cond, &sh->mutex);

        if (sh->exit_flag) {
            pthread_mutex_unlock(&sh->mutex);
            break;
        }

        int i = sh->idx;
        sh->pairs[i].a = sh->pairs[i].x * sh->pairs[i].y;
        sh->done[0] = 1;

        pthread_cond_broadcast(&sh->cond);
        pthread_mutex_unlock(&sh->mutex);
    }
    return NULL;
}

/* Thread to compute B = 2*X + 2*Y + 1 */
void* thread_b(void* arg) {
    while (1) {
        pthread_mutex_lock(&sh->mutex);

        while (sh->phase != 1 && !sh->exit_flag)
            pthread_cond_wait(&sh->cond, &sh->mutex);

        if (sh->exit_flag) {
            pthread_mutex_unlock(&sh->mutex);
            break;
        }

        int i = sh->idx;
        sh->pairs[i].b = 2 * sh->pairs[i].x + 2 * sh->pairs[i].y + 1;
        sh->done[1] = 1;

        pthread_cond_broadcast(&sh->cond);
        pthread_mutex_unlock(&sh->mutex);
    }
    return NULL;
}

/* Thread to compute C = B / A */
void* thread_c(void* arg) {
    while (1) {
        pthread_mutex_lock(&sh->mutex);

        while (sh->phase != 2 && !sh->exit_flag)
            pthread_cond_wait(&sh->cond, &sh->mutex);

        if (sh->exit_flag) {
            pthread_mutex_unlock(&sh->mutex);
            break;
        }

        int i = sh->idx;
        if (sh->pairs[i].a != 0)
            sh->pairs[i].c = (float)sh->pairs[i].b / sh->pairs[i].a;
        else
            sh->pairs[i].c = 0.0;
        sh->done[2] = 1;

        pthread_cond_broadcast(&sh->cond);
        pthread_mutex_unlock(&sh->mutex);
    }
    return NULL;
}

int main(int argc, char* argv[]) {
    /* Command line argument handling */
    if (argc != 2) {
        printf("Usage: %s N\n", argv[0]);
        printf("N = number of random pairs (1-%d)\n", MAX_PAIRS);
        return 1;
    }

    int n = atoi(argv[1]);
    if (n < 1 || n > MAX_PAIRS) {
        printf("N must be between 1 and %d\n", MAX_PAIRS);
        return 1;
    }

    /* Creating shared memory */
    int shmid = shmget(1234, sizeof(Shared), IPC_CREAT | 0666);
    if (shmid < 0) {
        perror("shmget");
        exit(1);
    }

    sh = (Shared*)shmat(shmid, NULL, 0);
    if (sh == (void*)-1) {
        perror("shmat");
        exit(1);
    }

    /* Initializing shared memory */
    sh->n = n;
    sh->idx = 0;
    sh->phase = 0;
    sh->exit_flag = 0;
    for (int i = 0; i < 3; i++)
        sh->done[i] = 0;

    pthread_mutex_init(&sh->mutex, NULL);
    pthread_cond_init(&sh->cond, NULL);

    /* Generating random pairs */
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        sh->pairs[i].x = rand() % 10;
        sh->pairs[i].y = rand() % 10;
    }

    /* Creating threads */
    pthread_t ta, tb, tc;
    pthread_create(&ta, NULL, thread_a, NULL);
    pthread_create(&tb, NULL, thread_b, NULL);
    pthread_create(&tc, NULL, thread_c, NULL);

    /* Main threading controls computation phases */
    for (int i = 0; i < n; i++) {
        pthread_mutex_lock(&sh->mutex);

        sh->idx = i;
        sh->phase = 0;
        for (int j = 0; j < 3; j++)
            sh->done[j] = 0;

        pthread_cond_broadcast(&sh->cond);
        while (!sh->done[0])
            pthread_cond_wait(&sh->cond, &sh->mutex);

        sh->phase = 1;
        pthread_cond_broadcast(&sh->cond);
        while (!sh->done[1])
            pthread_cond_wait(&sh->cond, &sh->mutex);

        sh->phase = 2;
        pthread_cond_broadcast(&sh->cond);
        while (!sh->done[2])
            pthread_cond_wait(&sh->cond, &sh->mutex);

        pthread_mutex_unlock(&sh->mutex);
    }

    /* Signal threading to exit */
    pthread_mutex_lock(&sh->mutex);
    sh->exit_flag = 1;
    pthread_cond_broadcast(&sh->cond);
    pthread_mutex_unlock(&sh->mutex);

    pthread_join(ta, NULL);
    pthread_join(tb, NULL);
    pthread_join(tc, NULL);

    /* Results displayed*/
    printf("Pairs(X,Y) |  A  |  B  |   C\n");
    printf("-------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("(%d, %d)    | %2d | %2d | %.2f\n",
            sh->pairs[i].x, sh->pairs[i].y,
            sh->pairs[i].a, sh->pairs[i].b, sh->pairs[i].c);
    }

    /* Pause to allow checking shared memory */
    sleep(10);

    /* Cleanup */
    pthread_mutex_destroy(&sh->mutex);
    pthread_cond_destroy(&sh->cond);

    shmdt(sh);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}
