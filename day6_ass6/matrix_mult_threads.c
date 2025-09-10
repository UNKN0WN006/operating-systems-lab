#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include <errno.h>

// Global matrix pointers and parameters
unsigned char **A, **B, **C;
int size, threads, mod, print_switch;

// Thread function for multiplying assigned rows
void *multiply(void *arg) {
    int tid = *(int *)arg;
    int rows_per_thread = size / threads;
    int start = tid * rows_per_thread;
    int end = (tid == threads - 1) ? size : start + rows_per_thread;

    for (int i = start; i < end; i++) {
        for (int j = 0; j < size; j++) {
            unsigned int sum = 0;
            for (int k = 0; k < size; k++)
                sum += A[i][k] * B[k][j];
            C[i][j] = sum % 256;
        }
    }
    return NULL;
}

// Print a matrix to stdout
void print_matrix(unsigned char **M) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
            printf("%3u ", M[i][j]);
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <size> <threads> <mod> <print_switch>\n", argv[0]);
        return 1;
    }

    size = atoi(argv[1]);
    threads = atoi(argv[2]);
    mod = atoi(argv[3]);
    print_switch = atoi(argv[4]);

    if (size <= 0 || threads <= 0 || mod <= 0) {
        fprintf(stderr, "Error: All arguments must be positive integers.\n");
        return 1;
    }

    // Allocate matrices
    A = malloc(size * sizeof(unsigned char *));
    B = malloc(size * sizeof(unsigned char *));
    C = malloc(size * sizeof(unsigned char *));
    if (!A || !B || !C) {
        perror("malloc");
        return 1;
    }
    for (int i = 0; i < size; i++) {
        A[i] = malloc(size);
        B[i] = malloc(size);
        C[i] = malloc(size);
        if (!A[i] || !B[i] || !C[i]) {
            perror("malloc");
            return 1;
        }
    }

    // Initialize matrices with random values
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++) {
            A[i][j] = rand() % mod;
            B[i][j] = rand() % mod;
        }

    struct timeval start, end;
    gettimeofday(&start, NULL);

    // Create threads for multiplication
    pthread_t *tid = malloc(threads * sizeof(pthread_t));
    int *tid_args = malloc(threads * sizeof(int));
    if (!tid || !tid_args) {
        perror("malloc");
        return 1;
    }

    for (int i = 0; i < threads; i++) {
        tid_args[i] = i;
        if (pthread_create(&tid[i], NULL, multiply, &tid_args[i]) != 0) {
            perror("pthread_create");
            return 1;
        }
    }
    for (int i = 0; i < threads; i++) {
        if (pthread_join(tid[i], NULL) != 0) {
            perror("pthread_join");
            return 1;
        }
    }

    gettimeofday(&end, NULL);
    long elapsed = (end.tv_sec - start.tv_sec) * 1000000L + (end.tv_usec - start.tv_usec);
    printf("Elapsed time (microseconds): %ld\n", elapsed);

    if (print_switch) {
        printf("Matrix A:\n"); print_matrix(A);
        printf("Matrix B:\n"); print_matrix(B);
        printf("Matrix C (Result):\n"); print_matrix(C);
    }

    // Free memory
    for (int i = 0; i < size; i++) {
        free(A[i]); free(B[i]); free(C[i]);
    }
    free(A); free(B); free(C);
    free(tid); free(tid_args);

    return 0;
}
