/*
Team: 06
Team Members:
    1. Anay Saha        Roll No: 002311001054
    2. Sushar Hembram   Roll No: 002311001041
    3. Debarshi Mondal  Roll No: 002311001055

Date: 18.09.2025

Assignment 7: Avoiding DEADLOCK using Thread Programming

Objective:
    - Avoid deadlock using threads and mutexes.
    - Three global totals (t1, t2, t3) protected by three mutexes (m1, m2, m3).
    - Four threads: Th1, Th2, Th3, Th4.
    - Th1, Th2, Th3 randomly transfer values between totals, locking relevant mutexes.
    - Th4 displays all totals and grand total, ensuring consistency.
    - Program runs forever.

Input:
    No input required. (Program runs with fixed initial values.)
    Usage: ./A2_06_07

Output:
    - Shows transfers and totals, demonstrating no deadlock.

Compilation:
    gcc A2_06_07.c -o A2_06_07 -lpthread

Execution:
    ./A2_06_07

Sample Input and Output:

@UNKN0WN006 ➜ /workspaces/operating-systems-lab/day7_ass7 (main) $ ls
@UNKN0WN006 ➜ /workspaces/operating-systems-lab/day7_ass7 (main) $ touch A2_06_07.c
@UNKN0WN006 ➜ /workspaces/operating-systems-lab/day7_ass7 (main) $ gcc A2_06_07.c -o A2_06_07 -lpthread
@UNKN0WN006 ➜ /workspaces/operating-systems-lab/day7_ass7 (main) $ ./A2_06_07
Starting program...
Initial: t1=100000, t2=100000, t3=100000

Th1: Moving 5 from t1
Th1: t1=99995, t3=100005
All threads started
Th3: Moving 8 from t3
Th3: t3=99997, t1=100003

--- Display Thread ---
t1=100003, t2=100000, t3=99997
Total=300000
--- End Display ---

Th2: Moving 10 from t2
Th2: t2=99990, t1=100013
Th1: Moving 9 from t1
Th1: t1=100004, t2=99999
Th2: Moving 10 from t2
Th2: t2=99989, t3=100007
Th3: Moving 26 from t3
Th3: t3=99981, t1=100030
Th1: Moving 9 from t1
Th1: t1=100021, t2=99998
Th2: Moving 4 from t2
Th2: t2=99994, t1=100025
Th1: Moving 9 from t1
Th1: t1=100016, t2=100003

--- Display Thread ---
t1=100016, t2=100003, t3=99981
Total=300000
--- End Display ---

Th3: Moving 13 from t3
Th3: t3=99968, t1=100029
Th1: Moving 1 from t1
Th1: t1=100028, t3=99969
Th2: Moving 15 from t2
Th2: t2=99988, t3=99984
Th1: Moving 7 from t1
Th1: t1=100021, t3=99991
Th3: Moving 6 from t3
Th3: t3=99985, t1=100027
Th2: Moving 6 from t2
Th2: t2=99982, t1=100033
Th1: Moving 2 from t1
Th1: t1=100031, t2=99984

--- Display Thread ---
t1=100031, t2=99984, t3=99985
Total=300000
--- End Display ---

Th3: Moving 22 from t3
Th3: t3=99963, t2=100006
Th2: Moving 13 from t2
Th2: t2=99993, t3=99976
Th1: Moving 10 from t1
Th1: t1=100021, t2=100003
Th1: Moving 6 from t1
Th1: t1=100015, t3=99982
Th2: Moving 12 from t2
Th2: t2=99991, t1=100027
Th3: Moving 4 from t3
Th3: t3=99978, t2=99995
Th1: Moving 8 from t1
Th1: t1=100019, t2=100003
Th2: Moving 16 from t2
Th2: t2=99987, t3=99994

--- Display Thread ---
t1=100019, t2=99987, t3=99994
Total=300000
--- End Display ---

Th1: Moving 9 from t1
Th1: t1=100010, t2=99996
Th3: Moving 6 from t3
Th3: t3=99988, t1=100016
Th2: Moving 14 from t2
Th2: t2=99982, t3=100002
Th1: Moving 1 from t1
Th1: t1=100015, t2=99983
Th3: Moving 24 from t3
Th3: t3=99978, t2=100007
Th1: Moving 7 from t1
Th1: t1=100008, t2=100014
Th2: Moving 4 from t2
Th2: t2=100010, t1=100012
Th1: Moving 1 from t1
Th1: t1=100011, t3=99979

--- Display Thread ---
t1=100011, t2=100010, t3=99979
Total=300000
--- End Display ---

Th3: Moving 2 from t3
Th3: t3=99977, t1=100013
Th2: Moving 1 from t2
Th2: t2=100009, t1=100014
^C


System Calls and Functions Used:
    pthread_create, pthread_join – for thread management
    pthread_mutex_lock, pthread_mutex_unlock – for mutex operations
    rand, srand – for random number generation
    perror – for error reporting
    printf – for output
    usleep, sleep – for delays

Deadlock Avoidance:
    - All threads lock mutexes in ascending address order (m1, m2, m3) when multiple are needed.
    - This consistent order prevents circular wait and avoids deadlock.
    - To create deadlock, lock mutexes in different orders in different threads (e.g., Th1: m1->m2, Th2: m2->m1).

For system/library call descriptions, use: man pthread_create, man pthread_mutex_lock, man perror, man rand, man printf, man usleep, man sleep
*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

int t1 = 100000;
int t2 = 100000; 
int t3 = 100000;

pthread_mutex_t m1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t m2 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t m3 = PTHREAD_MUTEX_INITIALIZER;

void* th1_func(void* arg) {
    int amt, choice;
    
    while(1) {
        amt = (rand() % 10) + 1;
        choice = rand() % 2;
        
        printf("Th1: Moving %d from t1\n", amt);
        
        if(choice == 0) {
            pthread_mutex_lock(&m1);
            pthread_mutex_lock(&m2);
            
            if(t1 >= amt) {
                t1 -= amt;
                t2 += amt;
                printf("Th1: t1=%d, t2=%d\n", t1, t2);
            }
            
            pthread_mutex_unlock(&m2);
            pthread_mutex_unlock(&m1);
        } else {
            pthread_mutex_lock(&m1);
            pthread_mutex_lock(&m3);
            
            if(t1 >= amt) {
                t1 -= amt;
                t3 += amt;
                printf("Th1: t1=%d, t3=%d\n", t1, t3);
            }
            
            pthread_mutex_unlock(&m3);
            pthread_mutex_unlock(&m1);
        }
        
        usleep(300000);
    }
    return NULL;
}

void* th2_func(void* arg) {
    int amt, choice;
    
    while(1) {
        amt = (rand() % 20) + 1;
        choice = rand() % 2;
        
        printf("Th2: Moving %d from t2\n", amt);
        
        if(choice == 0) {
            pthread_mutex_lock(&m1);
            pthread_mutex_lock(&m2);
            
            if(t2 >= amt) {
                t2 -= amt;
                t1 += amt;
                printf("Th2: t2=%d, t1=%d\n", t2, t1);
            }
            
            pthread_mutex_unlock(&m2);
            pthread_mutex_unlock(&m1);
        } else {
            pthread_mutex_lock(&m2);
            pthread_mutex_lock(&m3);
            
            if(t2 >= amt) {
                t2 -= amt;
                t3 += amt;
                printf("Th2: t2=%d, t3=%d\n", t2, t3);
            }
            
            pthread_mutex_unlock(&m3);
            pthread_mutex_unlock(&m2);
        }
        
        usleep(400000);
    }
    return NULL;
}

void* th3_func(void* arg) {
    int amt, choice;
    
    while(1) {
        amt = (rand() % 30) + 1;
        choice = rand() % 2;
        
        printf("Th3: Moving %d from t3\n", amt);
        
        if(choice == 0) {
            pthread_mutex_lock(&m1);
            pthread_mutex_lock(&m3);
            
            if(t3 >= amt) {
                t3 -= amt;
                t1 += amt;
                printf("Th3: t3=%d, t1=%d\n", t3, t1);
            }
            
            pthread_mutex_unlock(&m3);
            pthread_mutex_unlock(&m1);
        } else {
            pthread_mutex_lock(&m2);
            pthread_mutex_lock(&m3);
            
            if(t3 >= amt) {
                t3 -= amt;
                t2 += amt;
                printf("Th3: t3=%d, t2=%d\n", t3, t2);
            }
            
            pthread_mutex_unlock(&m3);
            pthread_mutex_unlock(&m2);
        }
        
        usleep(500000);
    }
    return NULL;
}

void* th4_func(void* arg) {
    int a, b, c, sum;
    
    while(1) {
        printf("\n--- Display Thread ---\n");
        
        pthread_mutex_lock(&m1);
        pthread_mutex_lock(&m2);
        pthread_mutex_lock(&m3);
        
        a = t1;
        b = t2;
        c = t3;
        sum = a + b + c;
        
        pthread_mutex_unlock(&m3);
        pthread_mutex_unlock(&m2);
        pthread_mutex_unlock(&m1);
        
        printf("t1=%d, t2=%d, t3=%d\n", a, b, c);
        printf("Total=%d\n", sum);
        printf("--- End Display ---\n\n");
        
        sleep(1);
    }
    return NULL;
}

int main(int argc, char* argv[]) {
    if(argc != 1) {
        printf("Usage: %s\n", argv[0]);
        return 1;
    }
    
    pthread_t thread1, thread2, thread3, thread4;
    
    srand(time(NULL));
    
    printf("Starting program...\n");
    printf("Initial: t1=%d, t2=%d, t3=%d\n\n", t1, t2, t3);
    
    if(pthread_create(&thread1, NULL, th1_func, NULL) != 0) {
        perror("Thread 1 create failed");
        return 1;
    }
    
    if(pthread_create(&thread2, NULL, th2_func, NULL) != 0) {
        perror("Thread 2 create failed");
        return 1;
    }
    
    if(pthread_create(&thread3, NULL, th3_func, NULL) != 0) {
        perror("Thread 3 create failed");
        return 1;
    }
    
    if(pthread_create(&thread4, NULL, th4_func, NULL) != 0) {
        perror("Thread 4 create failed");
        return 1;
    }
    
    printf("All threads started\n");
    
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);
    pthread_join(thread4, NULL);
    
    return 0;
}