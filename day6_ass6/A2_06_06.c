/*
Team: 06
Team Members:
    1. Anay Saha         Roll No: 002311001054
    2. Sushar Hembram   Roll No: 002311001041
    3. Debarshi Mondal   Roll No: 002311001055

Date: 10.09.2025

Assignment 6: Parallel Programming with Threads

Objective:
    - Implement parallel matrix multiplication using POSIX threads.
    - Dynamically allocate and initialize two square matrices (A and B) of size N×N with random values.
    - Divide the computation of the result matrix (C = A × B) among multiple threads for improved performance.
    - Each thread computes a subset of rows of the result matrix.
    - Allow the user to control matrix size, number of threads, value range, and whether to display matrices via command-line arguments.
    - Measure and display the time taken for the multiplication.
    - Display matrices if requested, with compact output for large matrices.

Input:

Four command-line arguments:
Matrix size (N)  
Number of threads  
Modulo value for random initialization  
Print switch (1 to display matrices, 0 to suppress output)

Output:

Matrix size, thread count, modulo value, and elapsed time.
Matrices A, B, and C (if print switch is 1).

Compilation:
gcc A2_06_06.c -o A2_06_06 -lpthread -lm

Execution:
./A2_06_06 <matrix_size> <num_threads> <mod_value> <print_switch>

Sample INput and Output:
@UNKN0WN006 ➜ /workspaces/operating-systems-lab/day6_ass6 (main) $ gcc A2_06_06.c -o A2_06_06 -lpthread -lm
@UNKN0WN006 ➜ /workspaces/operating-systems-lab/day6_ass6 (main) $ ./A2_06_06 3000 4 100 1
Matrix size: 3000x3000, Threads: 4, Mod: 100

Input A Matrix:
[  6  20  48 . . .  66  32  28]
  .
  .
  .
[ 43   0  60 . . .  74  65  62]

Input B Matrix:
[  6  20  48 . . .  66  32  28]
  .
  .
  .
[ 43   0  60 . . .  74  65  62]
Time elapsed: 96.886 seconds

Result Matrix:
[202 175 229 . . .  45 244   6]
  .
  .
  .
[189  20 117 . . . 136 163  53]

The Process Listing:

@UNKN0WN006 ➜ /workspaces/operating-systems-lab (main) $ ps aux | grep A2_06_06
codespa+   18043  175  0.3  61884 28032 pts/0    Sl+  12:23   0:03 ./A2_06_06 3000 4 100 1
codespa+   18067  0.0  0.0   7084  2048 pts/1    S+   12:23   0:00 grep --color=auto A2_06_06
@UNKN0WN006 ➜ /workspaces/operating-systems-lab (main) $ ps aux | grep A2_06_06
codespa+   18043  174  0.3  61884 28032 pts/0    Sl+  12:23   0:07 ./A2_06_06 3000 4 100 1
codespa+   18128  0.0  0.0   7084  2048 pts/1    S+   12:23   0:00 grep --color=auto A2_06_06
@UNKN0WN006 ➜ /workspaces/operating-systems-lab (main) $ ps aux | grep A2_06_06
codespa+   19220  0.0  0.0   7084  2048 pts/1    S+   12:25   0:00 grep --color=auto A2_06_06
@UNKN0WN006 ➜ /workspaces/operating-systems-lab (main) $ ps aux | grep A2_06_06.c
codespa+   19266  0.0  0.0   7088  2176 pts/1    S+   12:25   0:00 grep --color=auto A2_06_06.c

CPU Utilisation:

@UNKN0WN006 ➜ /workspaces/operating-systems-lab (main) $ sar -u 1 60 
Linux 6.8.0-1030-azure (codespaces-c2b406)      09/11/25        _x86_64_        (2 CPU)

12:23:26        CPU     %user     %nice   %system   %iowait    %steal     %idle
12:23:27        all      4.98      0.00      4.98      0.00      0.00     90.05
12:23:28        all      7.14      0.00      8.67      0.00      0.00     84.18
12:23:29        all      6.57      0.00      8.59      0.00      0.00     84.85
12:23:30        all      1.49      0.00      1.00      0.00      0.00     97.51
12:23:31        all     80.50      0.00      4.50      0.00      0.00     15.00
12:23:32        all     97.00      0.00      3.00      0.00      0.00      0.00
12:23:33        all     93.03      0.00      6.97      0.00      0.00      0.00
12:23:34        all     94.53      0.00      5.47      0.00      0.00      0.00
12:23:35        all     93.03      0.00      6.97      0.00      0.00      0.00
12:23:36        all     97.49      0.00      2.51      0.00      0.00      0.00
12:23:37        all     93.00      0.00      7.00      0.00      0.00      0.00
12:23:38        all     91.04      0.00      8.96      0.00      0.00      0.00

12:23:38        CPU     %user     %nice   %system   %iowait    %steal     %idle
12:23:39        all     95.98      0.00      4.02      0.00      0.00      0.00
12:23:40        all     95.00      0.00      5.00      0.00      0.00      0.00
12:23:41        all     98.51      0.00      1.49      0.00      0.00      0.00
12:23:42        all     95.98      0.00      4.02      0.00      0.00      0.00
12:23:44        all     98.00      0.00      2.00      0.00      0.00      0.00
12:23:45        all     96.02      0.00      3.98      0.00      0.00      0.00
12:23:46        all     98.51      0.00      1.49      0.00      0.00      0.00
12:23:47        all     94.47      0.00      5.53      0.00      0.00      0.00
12:23:48        all     97.50      0.00      2.50      0.00      0.00      0.00
12:23:49        all     89.55      0.00     10.45      0.00      0.00      0.00
12:23:50        all     97.00      0.00      3.00      0.00      0.00      0.00
12:23:51        all     97.99      0.00      2.01      0.00      0.00      0.00

12:23:51        CPU     %user     %nice   %system   %iowait    %steal     %idle
12:23:52        all     96.50      0.00      3.50      0.00      0.00      0.00
12:23:53        all     98.01      0.00      1.99      0.00      0.00      0.00
12:23:54        all     94.95      0.00      5.05      0.00      0.00      0.00
12:23:55        all     98.02      0.00      1.98      0.00      0.00      0.00
12:23:56        all     95.50      0.00      4.50      0.00      0.00      0.00
12:23:57        all     99.00      0.00      1.00      0.00      0.00      0.00
12:23:58        all     94.00      0.00      6.00      0.00      0.00      0.00
12:23:59        all     97.00      0.00      3.00      0.00      0.00      0.00
12:24:00        all     89.05      0.00     10.95      0.00      0.00      0.00
12:24:01        all     98.49      0.00      1.51      0.00      0.00      0.00
12:24:02        all     97.01      0.00      2.99      0.00      0.00      0.00
12:24:03        all     96.53      0.00      3.47      0.00      0.00      0.00

12:24:03        CPU     %user     %nice   %system   %iowait    %steal     %idle
12:24:04        all     94.03      0.00      5.97      0.00      0.00      0.00
12:24:05        all     98.99      0.00      1.01      0.00      0.00      0.00
12:24:06        all     98.51      0.00      1.49      0.00      0.00      0.00
12:24:07        all     97.50      0.00      2.50      0.00      0.00      0.00
12:24:08        all     99.50      0.00      0.50      0.00      0.00      0.00
12:24:09        all     91.50      0.00      8.50      0.00      0.00      0.00
12:24:10        all     91.04      0.00      8.96      0.00      0.00      0.00
12:24:11        all     95.00      0.00      5.00      0.00      0.00      0.00
12:24:12        all     99.00      0.00      1.00      0.00      0.00      0.00
12:24:13        all     95.98      0.00      4.02      0.00      0.00      0.00
12:24:14        all     97.01      0.00      2.99      0.00      0.00      0.00
12:24:15        all     92.04      0.00      7.96      0.00      0.00      0.00

12:24:15        CPU     %user     %nice   %system   %iowait    %steal     %idle
12:24:16        all     98.50      0.00      1.50      0.00      0.00      0.00
12:24:17        all     98.50      0.00      1.50      0.00      0.00      0.00
12:24:18        all     88.94      0.00     11.06      0.00      0.00      0.00
12:24:19        all     94.53      0.00      5.47      0.00      0.00      0.00
12:24:20        all     93.97      0.00      6.03      0.00      0.00      0.00
12:24:21        all     87.50      0.00     12.50      0.00      0.00      0.00
12:24:22        all     96.53      0.00      3.47      0.00      0.00      0.00
12:24:23        all     99.50      0.00      0.50      0.00      0.00      0.00
12:24:24        all     95.00      0.00      5.00      0.00      0.00      0.00
12:24:25        all     99.01      0.00      0.99      0.00      0.00      0.00
12:24:26        all     93.47      0.00      6.53      0.00      0.00      0.00
12:24:27        all     98.50      0.00      1.50      0.00      0.00      0.00
Average:        all     89.41      0.00      4.43      0.00      0.00      6.16

System Calls and Functions Used:
    pthread_create, pthread_join – for thread management
    malloc, free – for dynamic memory allocation
    gettimeofday – for timing
    printf – for output
    rand, srand – for random number generation
*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include <unistd.h>

typedef struct {
    int start_row;
    int end_row;
    int n;
} thread_data;

unsigned char **a, **b, **c;
int num_threads;

void* multiply(void* arg) {
    thread_data* data = (thread_data*)arg;
    int i, j, k;
    int sum;
    
    for (i = data->start_row; i < data->end_row; i++) {
        for (j = 0; j < data->n; j++) {
            sum = 0;
            for (k = 0; k < data->n; k++) {
                sum += a[i][k] * b[k][j];
            }
            c[i][j] = sum % 256;
        }
    }
    return NULL;
}

unsigned char** allocate_matrix(int n) {
    unsigned char **matrix;
    int i;
    
    matrix = (unsigned char**)malloc(n * sizeof(unsigned char*));
    for (i = 0; i < n; i++) {
        matrix[i] = (unsigned char*)malloc(n * sizeof(unsigned char));
    }
    return matrix;
}

void free_matrix(unsigned char** matrix, int n) {
    int i;
    for (i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void init_matrix(unsigned char** matrix, int n, int mod_val) {
    int i, j;
    srand(time(NULL));
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            matrix[i][j] = rand() % mod_val;
        }
    }
}

void print_matrix(unsigned char** matrix, int n, char* name) {
    int i, j;
    printf("\n%s Matrix:\n", name);
    
    if (n <= 10) {
        for (i = 0; i < n; i++) {
            printf("[");
            for (j = 0; j < n; j++) {
                printf("%3d", matrix[i][j]);
                if (j < n-1) printf(" ");
            }
            printf("]\n");
        }
    } else {
        printf("[");
        for (i = 0; i < 3; i++) {
            printf("%3d ", matrix[0][i]);
        }
        printf(". . . ");
        for (i = n-3; i < n; i++) {
            printf("%3d", matrix[0][i]);
            if (i < n-1) printf(" ");
        }
        printf("]\n");
        printf("  .\n  .\n  .\n");
        printf("[");
        for (i = 0; i < 3; i++) {
            printf("%3d ", matrix[n-1][i]);
        }
        printf(". . . ");
        for (i = n-3; i < n; i++) {
            printf("%3d", matrix[n-1][i]);
            if (i < n-1) printf(" ");
        }
        printf("]\n");
    }
}

double get_time_diff(struct timeval start, struct timeval end) {
    return (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
}

int main(int argc, char* argv[]) {
    int n, mod_val, print_switch;
    struct timeval start_time, end_time;
    pthread_t* threads;
    thread_data* td;
    int i, rows_per_thread, remaining_rows;
    int ret;
    
    if (argc != 5) {
        printf("Usage: %s <matrix_size> <num_threads> <mod_value> <print_switch>\n", argv[0]);
        return 1;
    }
    
    n = atoi(argv[1]);
    num_threads = atoi(argv[2]);
    mod_val = atoi(argv[3]);
    print_switch = atoi(argv[4]);
    
    printf("Matrix size: %dx%d, Threads: %d, Mod: %d\n", n, n, num_threads, mod_val);
    
    // Allocate matrices
    a = allocate_matrix(n);
    b = allocate_matrix(n);
    c = allocate_matrix(n);
    
    // Initialize matrices
    init_matrix(a, n, mod_val);
    init_matrix(b, n, mod_val);
    
    if (print_switch == 1) {
        print_matrix(a, n, "Input A");
        print_matrix(b, n, "Input B");
    }
    
    // Start timing
    ret = gettimeofday(&start_time, NULL);
    if (ret != 0) {
        perror("gettimeofday failed");
        exit(1);
    }
    
    // Create threads
    threads = (pthread_t*)malloc(num_threads * sizeof(pthread_t));
    if (threads == NULL) {
        perror("malloc failed for threads");
        exit(1);
    }
    
    td = (thread_data*)malloc(num_threads * sizeof(thread_data));
    if (td == NULL) {
        perror("malloc failed for thread data");
        exit(1);
    }
    
    rows_per_thread = n / num_threads;
    remaining_rows = n % num_threads;
    
    for (i = 0; i < num_threads; i++) {
        td[i].start_row = i * rows_per_thread;
        td[i].end_row = (i + 1) * rows_per_thread;
        if (i == num_threads - 1) {
            td[i].end_row += remaining_rows;
        }
        td[i].n = n;
        
        ret = pthread_create(&threads[i], NULL, multiply, &td[i]);
        if (ret != 0) {
            perror("pthread_create failed");
            exit(1);
        }
    }
    
    // Wait for threads to complete
    for (i = 0; i < num_threads; i++) {
        ret = pthread_join(threads[i], NULL);
        if (ret != 0) {
            perror("pthread_join failed");
            exit(1);
        }
    }
    
    // End timing
    ret = gettimeofday(&end_time, NULL);
    if (ret != 0) {
        perror("gettimeofday failed");
        exit(1);
    }
    
    double elapsed = get_time_diff(start_time, end_time);
    printf("Time elapsed: %.3f seconds\n", elapsed);
    
    if (print_switch == 1) {
        print_matrix(c, n, "Result");
    }
    
    // Cleanup
    free_matrix(a, n);
    free_matrix(b, n);
    free_matrix(c, n);
    free(threads);
    free(td);
    
    return 0;
}