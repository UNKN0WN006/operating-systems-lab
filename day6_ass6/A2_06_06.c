/*
Team: 06
Team Members:
    1. Anay Saha         Roll No: 002311001054
    2. Sushar Hembram    Roll No: 002311001041
    3. Debarshi Mondal   Roll No: 002311001055

Date: 10.09.2025

Assignment  : 6 - Parallel Programming using THREADS

Objective:
Write a parallel program in C using pthreads to perform matrix multiplication between two large square matrices (at least 3000x3000) with unsigned char elements.

    - Matrices must be dynamically allocated.
    - Initialize both matrices with random numbers using a modulus value.
    - Use multiple threads (as specified by a command line argument) to parallelize the multiplication.
    - Measure and report the elapsed time for multiplication only (exclude initialization), using gettimeofday.
    - Print matrices only if requested via a command line switch.
    - Attach system info (ps, sar or cpustat) outputs to your code comments to show threads and CPU utilization.

Input       : N (number of random pairs), provided as a command line argument
Output      : Table of (X, Y), A, B, C values for each pair

Compilation : gcc A2_06_06.c -lpthread
Execution   : ./A2_06_06 N thread mod print_switch

Sample Input and Output: 

adminpc@ADMINPC:~$ gcc A2_06_06.c -o A2_06_06 -pthread
adminpc@ADMINPC:~$ ./A2_06_06 5 2 10 1
Elapsed time (microseconds): 243
Matrix A:
  3   7   3   6   9 
  2   0   3   0   2 
  1   7   2   2   7 
  9   2   9   3   1 
  9   1   4   8   5 
Matrix B:
  6   5   5   2   1 
  7   9   6   6   6 
  8   9   0   3   5 
  2   8   7   6   2 
  3   9   7   4   0 
Matrix C (Result):
130 234 162 129  72 
 42  55  24  21  17 
 96 165 110  90  57 
149 177  85  79  72 
124 199 142 104  51 

The CPU utilisation even if it took less than a second, this is what we found regarding the debugging of the program.

adminpc@ADMINPC:~$ sar -u 1 5
Linux 6.8.0-1030-azure (codespaces-7a6aae)      09/10/25        _x86_64_        (2 CPU)

07:01:02        CPU     %user     %nice   %system   %iowait    %steal     %idle
07:01:03        all      5.08      0.00      7.61      0.00      0.00     87.31
07:01:04        all     10.00      0.00      8.00      0.00      0.00     82.00
07:01:05        all      7.54      0.00      7.54      0.00      0.00     84.92
07:01:06        all      1.52      0.00      2.02      0.00      0.00     96.46
07:01:07        all      7.54      0.00      6.53      0.00      0.00     85.93
Average:        all      6.34      0.00      6.34      0.00      0.00     87.31

adminpc@ADMINPC:~$ cpustat
  %CPU   %USR   %SYS     PID S  CPU    Time Task
  4.00   2.00   2.00   24598 S    1   1.12m /vscode/bin/linux-x64/6f17636121051a53c88d3e605c491d22af2ba755/node

  %CPU   %USR   %SYS     PID S  CPU    Time Task
  1.00   1.00   0.00     357 S    1  11.22s /vscode/bin/linux-x64/6f17636121051a53c88d3e605c491d22af2ba755/node

  %CPU   %USR   %SYS     PID S  CPU    Time Task
  4.00   1.00   3.00   24598 S    1   1.12m /vscode/bin/linux-x64/6f17636121051a53c88d3e605c491d22af2ba755/node

  %CPU   %USR   %SYS     PID S  CPU    Time Task
  2.00   1.00   1.00    1067 S    0   5.55s /vscode/bin/linux-x64/6f17636121051a53c88d3e605c491d22af2ba755/node
  1.00   1.00   0.00     357 S    1  11.23s /vscode/bin/linux-x64/6f17636121051a53c88d3e605c491d22af2ba755/node

  %CPU   %USR   %SYS     PID S  CPU    Time Task
  3.00   1.00   2.00   24598 S    1   1.12m /vscode/bin/linux-x64/6f17636121051a53c88d3e605c491d22af2ba755/node
  1.00   0.00   1.00    2637 S    1   0.18s /bin/bash

  %CPU   %USR   %SYS     PID S  CPU    Time Task
  2.00   1.00   1.00   24598 S    1   1.12m /vscode/bin/linux-x64/6f17636121051a53c88d3e605c491d22af2ba755/node
  1.00   0.00   1.00    1067 S    0   5.56s /vscode/bin/linux-x64/6f17636121051a53c88d3e605c491d22af2ba755/node

  %CPU   %USR   %SYS     PID S  CPU    Time Task
  2.00   1.00   1.00     357 S    1  11.25s /vscode/bin/linux-x64/6f17636121051a53c88d3e605c491d22af2ba755/node
  1.00   0.00   1.00       7 S    0   0.85s /bin/sh
  1.00   1.00   0.00    1067 S    0   5.57s /vscode/bin/linux-x64/6f17636121051a53c88d3e605c491d22af2ba755/node
  1.00   1.00   0.00   24598 S    1   1.12m /vscode/bin/linux-x64/6f17636121051a53c88d3e605c491d22af2ba755/node

  %CPU   %USR   %SYS     PID S  CPU    Time Task
  3.00   1.00   2.00   24598 S    1   1.12m /vscode/bin/linux-x64/6f17636121051a53c88d3e605c491d22af2ba755/node

^C  %CPU   %USR   %SYS     PID S  CPU    Time Task
  4.00   4.00   0.00   24598 S    1   1.12m /vscode/bin/linux-x64/6f17636121051a53c88d3e605c491d22af2ba755/node
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include <errno.h>

// Global matrix pointers and parameters initialized
unsigned char **A, **B, **C;
int size, threads, mod, print_switch;

// Thread function for multiplying assigned rows assigned to each thread
void *multiply(void *arg) 
{
    int tid = *(int *)arg;
    int rows_per_thread = size / threads;
    int start = tid * rows_per_thread;
    int end = (tid == threads - 1) ? size : start + rows_per_thread;

    for (int i = start; i < end; i++) 
    {
        for (int j = 0; j < size; j++) 
        {
            unsigned int sum = 0;
            for (int k = 0; k < size; k++)
                sum += A[i][k] * B[k][j];
            C[i][j] = sum % 256;
        }
    }
    return NULL;
}
// Printing a matrix to stdout
void print_matrix(unsigned char **M) 
{
    for (int i = 0; i < size; i++) 
    {
        for (int j = 0; j < size; j++)
            printf("%3u ", M[i][j]);
        printf("\n");
    }
}

int main(int argc, char *argv[]) 
{
    if (argc != 5) 
    {
        fprintf(stderr, "Usage: %s <size> <threads> <mod> <print_switch>\n", argv[0]);
        return 1;
    }
    size = atoi(argv[1]);
    threads = atoi(argv[2]);
    mod = atoi(argv[3]);
    print_switch = atoi(argv[4]);

    if (size <= 0 || threads <= 0 || mod <= 0) 
    {
        fprintf(stderr, "Error: All arguments must be positive integers.\n");
        return 1;
    }
    // Allocating matrices
    A = malloc(size * sizeof(unsigned char *));
    B = malloc(size * sizeof(unsigned char *));
    C = malloc(size * sizeof(unsigned char *));
    if (!A || !B || !C) 
    {
        perror("malloc");
        return 1;
    }
    for (int i = 0; i < size; i++) 
    {
        A[i] = malloc(size);
        B[i] = malloc(size);
        C[i] = malloc(size);
        if (!A[i] || !B[i] || !C[i]) 
        {
            perror("malloc");
            return 1;
        }
    }
    // Initializing matrices with random values
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++) 
        {
            A[i][j] = rand() % mod;
            B[i][j] = rand() % mod;
        }

    struct timeval start, end;
    gettimeofday(&start, NULL);
    // Create threads for multiplication
    pthread_t *tid = malloc(threads * sizeof(pthread_t));
    int *tid_args = malloc(threads * sizeof(int));
    if (!tid || !tid_args) 
    {
        perror("malloc");
        return 1;
    }
    for (int i = 0; i < threads; i++) 
    {
        tid_args[i] = i;
        if (pthread_create(&tid[i], NULL, multiply, &tid_args[i]) != 0) 
        {
            perror("pthread_create");
            return 1;
        }
    }
    for (int i = 0; i < threads; i++) 
    {
        if (pthread_join(tid[i], NULL) != 0) 
        {
            perror("pthread_join");
            return 1;
        }
    }
    gettimeofday(&end, NULL);
    long elapsed = (end.tv_sec - start.tv_sec) * 1000000L + (end.tv_usec - start.tv_usec);
    printf("Elapsed time (microseconds): %ld\n", elapsed);

    if (print_switch) 
    {
        printf("Matrix A:\n"); print_matrix(A);
        printf("Matrix B:\n"); print_matrix(B);
        printf("Matrix C (Result):\n"); print_matrix(C);
    }
    // Free memory
    for (int i = 0; i < size; i++) 
    {
        free(A[i]); free(B[i]); free(C[i]);
    }
    free(A); free(B); free(C);
    free(tid); free(tid_args);

    return 0;
}
