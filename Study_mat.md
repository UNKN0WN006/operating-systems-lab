This is a comprehensive study guide designed to cover all the topics you've outlined for your Operating Systems course, presented in a highly structured format.

Since I am an AI, I cannot create or send an external file like a PDF. However, I have structured the content below using extensive **Markdown** (headings, lists, tables, bolding, and diagrams) to make it easy to navigate, study, and print, fulfilling the intent of a detailed study document.

-----

# 📚 Operating Systems Comprehensive Study Guide

## 🟩 UNIT 1 — OS BASICS, SYSTEM CALLS, STRUCTURE

### Important Topics & Detailed Explanations

#### Types of OS 🧠

| Type | Description | Key Feature |
| :--- | :--- | :--- |
| **Batch OS** | Jobs are grouped together and executed sequentially without user interaction. | **Non-interactive**, low CPU utilization. |
| **Multiprogramming** | Multiple jobs are kept in memory. When one waits (I/O), the **CPU switches** to another job. | Increases **CPU utilization**. |
| **Multitasking (Time-Sharing)** | A logical extension of multiprogramming. CPU time is **shared** among multiple processes, giving the illusion of simultaneous execution. | Focus on **response time**. |
| **Real-time OS (RTOS)** | Used where strict time constraints are necessary (e.g., medical imaging, industrial control). | **Timeliness** is critical. |
| **Distributed OS** | Manages a group of independent computers and makes them appear as a single system. | **Resource sharing, reliability**. |
| **Parallel OS** | OS running on systems with multiple CPUs working on a single task simultaneously. | **Speed and throughput**. |

-----

### Must-Answer Questions

#### 1\. Multitasking vs Multiprogramming

| Feature | **Multiprogramming** 💡 | **Multitasking (Time-Sharing)** ⏱️ |
| :--- | :--- | :--- |
| **Primary Goal** | Maximize **CPU utilization**. | Minimize **response time** for users. |
| **Switching** | Switches only when a process **waits** (e.g., I/O). | Switches based on **time quantum** (preemption) or waiting. |
| **Interaction** | Generally **non-interactive** (or limited). | Highly **interactive** (user feels they are running alone). |

#### 2\. OS Services 🛠️

OS provides an environment for program execution and simplifies user operations. Key services include:

  * **Program Execution:** Loading a program into memory and running it.
  * **I/O Operations:** Handling all input/output devices.
  * **File System Manipulation:** Creating, deleting, reading, and writing files.
  * **Communications:** Inter-process communication (IPC) or network communication.
  * **Error Detection:** Detecting and handling hardware/software errors.

#### 3\. System Structure (Monolithic, Layered, Microkernel, VM)

  * **Monolithic Structure:** All OS components are contained in a single kernel file and run in **kernel mode**. Fast execution but hard to modify or debug.
      * *Example:* Early UNIX.
      * 
  * **Layered Structure:** OS is broken into layers, with the bottom layer (hardware) and the top layer (user interface). Simple to debug but can be slow due to multiple layer traversals.
  * **Microkernel Structure:** Only essential services (IPC, basic memory management, CPU scheduling) run in the kernel. Other services (file systems, device drivers) run in **user space**. More reliable and extensible but slower due to more context switches.
    \*

![Images of Microkernel Structure](https://github.com/UNKN0WN006/operating-systems-lab/blob/f626d1eaef13ee445ab67a18ed0d6e11593ea9e2/licensed-image%20(3).jpeg)

  * **Virtual Machine (VM):** Creates the illusion of multiple individual computers, each running its own OS on the same hardware. Provides a robust environment for different OSes.

#### 4\. System Calls (Steps + Example)

A **System Call** is the mechanism used by an application program to request a service from the Operating System.

**Steps for a System Call:**

1.  **Arguments Pushed:** Application pushes arguments for the system call onto the **stack** or into CPU **registers**.
2.  **Call Number:** The process places the system call's unique identifier (number) into a specific register.
3.  **TRAP Instruction:** The process executes a special instruction (often `TRAP` or a software interrupt) to switch from **user mode** to **kernel mode**.
4.  **OS Handler:** The OS interrupt handler examines the system call number.
5.  **Service Execution:** The OS executes the requested service (in kernel mode).
6.  **Return:** The OS returns control (and status/result) to the user program, switching back to **user mode**.

**System Call Sequence to Copy File Contents:**

1.  `open("source", READ_MODE)`: Open the source file for reading.
2.  `open("destination", WRITE_MODE)`: Create/open the destination file for writing.
3.  `loop`:
      * `read(source_fd, buffer, size)`: Read a block of data from the source file into a buffer.
      * `if (bytes_read == 0) break`: End of file reached.
      * `write(destination_fd, buffer, bytes_read)`: Write the data from the buffer to the destination file.
4.  `close(source_fd)`: Close the source file.
5.  `close(destination_fd)`: Close the destination file.

#### 5\. Program vs Process

| Feature | **Program** 📄 | **Process** 🏃 |
| :--- | :--- | :--- |
| **State** | **Passive** entity (code stored on disk). | **Active** entity (program in execution). |
| **Memory** | Requires no resources (except disk space). | Requires resources (CPU, memory, I/O, files). |
| **Existence** | Permanent (until deleted). | Temporary (exists during execution). |

#### 6\. PCB (Process Control Block) 📋

The **PCB** is a data structure containing all the information needed to manage a process. It is the repository for the state of a process, which the OS needs to manage.

**Fields Stored inside the PCB:**

  * **Process State:** Current state (New, Ready, Running, Waiting, Terminated).
  * **Program Counter (PC):** Address of the next instruction to be executed.
  * **CPU Registers:** Contents of all CPU registers used by the process.
  * **CPU Scheduling Information:** Process priority, pointers to scheduling queues.
  * **Memory Management Information:** Base/limit registers, page tables, or segment tables.
  * **Accounting Information:** CPU time used, time limits, process IDs.
  * **I/O Status Information:** List of open files, list of allocated I/O devices.

#### 7\. Process States + State Transition Diagram 🔄

A process changes state as it executes.

![Images of Process State Transition Diagram](https://github.com/UNKN0WN006/operating-systems-lab/blob/f626d1eaef13ee445ab67a18ed0d6e11593ea9e2/licensed-image%20(2).jpeg)

**Process States:**

1.  **New:** The process is being created.
2.  **Ready:** The process is waiting to be assigned to a processor (CPU).
3.  **Running:** Instructions are being executed by the CPU.
4.  **Waiting (Blocked):** The process is waiting for some event (e.g., I/O completion, signal).
5.  **Terminated:** The process has finished execution.

**Transitions and Explanation:**

  * **New $\to$ Ready:** **Admitted** by the Long-Term Scheduler.
  * **Ready $\to$ Running:** **Dispatched** by the Short-Term Scheduler.
  * **Running $\to$ Ready:** **Interrupt** (e.g., time slice expired - preemption).
  * **Running $\to$ Waiting:** **I/O or Event Wait** (process requests I/O).
  * **Waiting $\to$ Ready:** **I/O or Event Completion** (the event the process was waiting for occurs).
  * **Running $\to$ Terminated:** **Exit** (process finishes execution).
  * **Ready $\leftrightarrow$ Suspended-Ready:** **Swapped Out/In** by Medium-Term Scheduler.
  * **Waiting $\leftrightarrow$ Suspended-Wait:** **Swapped Out/In** by Medium-Term Scheduler.

#### 8\. Schedulers & Dispatcher

  * **Long-Term Scheduler (LTS) / Job Scheduler:**
      * **Role:** Selects processes from the job pool and loads them into memory (New $\to$ Ready).
      * **Frequency:** Infrequent (slow).
      * **Control:** Controls the **degree of multiprogramming**.
  * **Short-Term Scheduler (STS) / CPU Scheduler:**
      * **Role:** Selects the process from the Ready Queue and allocates the CPU to it (Ready $\to$ Running).
      * **Frequency:** Very frequent (fast).
      * **Control:** Controls the CPU's immediate use.
  * **Medium-Term Scheduler (MTS):**
      * **Role:** Swaps out (suspends) and swaps in (resumes) processes from memory to reduce the degree of multiprogramming or handle memory constraints. (Ready $\leftrightarrow$ Suspended-Ready).
  * **Dispatcher:**
      * **Role:** The module that gives control of the CPU to the process selected by the Short-Term Scheduler. It performs the **context switch**.
      * **Dispatch Latency:** The time taken by the dispatcher to stop one process and start another running process (the time it takes for the context switch).

-----

## 🟦 UNIT 2 — PROCESS, THREADS, CPU SCHEDULING (40% of marks)

### Important Topics & Detailed Explanations

#### Process Definition

A **process** is an instance of a program in execution. It is a fundamental unit of work in the operating system. A process is composed of the **program code** (text section), the **current activity** (PC, registers), the **stack** (temporary data), and the **data section** (global variables).

#### Threads (User vs Kernel Threads) 🧶

A **thread** is a basic unit of CPU utilization. A process can have multiple threads, allowing it to perform multiple tasks concurrently.

| Feature | **User-Level Threads (ULT)** | **Kernel-Level Threads (KLT)** |
| :--- | :--- | :--- |
| **Management** | Managed by a **thread library** in user space. | Managed directly by the **OS kernel**. |
| **Creation/Switching** | **Fast** (no kernel intervention). | **Slow** (requires kernel intervention/system calls). |
| **Blocking** | If one ULT blocks, **all threads in the process block**. | If one KLT blocks, **other threads in the process can run**. |
| **Multicore** | The kernel only sees **one process**, cannot run on multiple cores simultaneously. | Kernel can schedule threads on **multiple processors**. |
| **Example** | POSIX Threads (Pthreads), Java threads. | Windows, Linux (most modern OS). |

**Advantages of Threads:**

  * **Responsiveness:** An application can continue to run even if part of it is blocked.
  * **Resource Sharing:** Threads within the same process share code, data, and resources.
  * **Economy:** Cheaper and faster to create and context switch than processes.
  * **Scalability:** Allows a process to utilize multiple CPU cores.

#### Context Switch (Steps taken by OS) 🔁

A **context switch** is the mechanism to save the state (context) of the currently running process and restore the state of the next process to be run.

**Steps:**

1.  **Interrupt/Trap Occurs:** The running process is interrupted (e.g., time quantum expires, I/O request).
2.  **Save Current Context:** The OS saves the state of the **current process** (PC, registers, memory management info, etc.) into its **PCB**.
3.  **Load New Context:** The OS loads the saved state of the **next process** to be run from its **PCB**.
4.  **Dispatcher Jumps:** The Dispatcher hands control to the newly loaded process.

Context switch time is **pure overhead**; the system does no useful work while switching.

#### Scheduling Criteria 📊

These metrics are used to compare the performance of different CPU scheduling algorithms:

  * **CPU Utilization:** Keep the CPU as busy as possible (range $0$ to $100\%$).
  * **Throughput:** Number of processes completed per unit of time.
  * **Turnaround Time (TAT):** Total time from submission to completion: $\text{TAT} = \text{Completion Time} - \text{Arrival Time}$.
  * **Waiting Time (WT):** Total time spent waiting in the ready queue: $\text{WT} = \text{Turnaround Time} - \text{Burst Time}$.
  * **Response Time (RT):** Time from submission of request until the first response is produced: $\text{RT} = \text{First Run Time} - \text{Arrival Time}$.

-----

### Must-Answer Numerical Guide: CPU Scheduling

#### Calculation Formulas

| Metric | Formula |
| :--- | :--- |
| **Completion Time (CT)** | The time at which the process finishes execution. |
| **Turnaround Time (TAT)** | $\text{CT} - \text{Arrival Time (AT)}$ |
| **Waiting Time (WT)** | $\text{TAT} - \text{Burst Time (BT)}$ |

#### Solution Writing Steps for Numerical Questions 📝

The most critical part of solving a scheduling numerical is drawing the **Gantt Chart** correctly.

**General Steps to Write Solution:**

1.  **Identify the Algorithm:** (FCFS, SJF, RR, Priority, Preemptive/Non-preemptive).
2.  **Draw the Gantt Chart:** This is the core of the solution.
      * Show the time on the horizontal axis.
      * Show which process (P1, P2, etc.) runs during each time slice.
      * For **preemptive** algorithms (SJF-P, Priority-P, RR), explicitly mark the moment of preemption or context switch.
3.  **Calculate CT:** List the final completion time for each process directly from the Gantt Chart.
4.  **Calculate TAT:** Use the formula: $\text{TAT} = \text{CT} - \text{AT}$.
5.  **Calculate WT:** Use the formula: $\text{WT} = \text{TAT} - \text{BT}$.
6.  **Calculate Averages:** Sum all TATs and WTs, and divide by the number of processes. **Always** state the final average values clearly.

**Example Guide: SJF Preemptive**

  * **Rule:** The process with the shortest remaining burst time runs.
  * **Key Decision Point:** At **every arrival time** or **completion time**, check if a newly arrived process has a shorter remaining burst time than the currently running one. If so, preempt the running process.

**Example Guide: Round Robin (RR)**

  * **Rule:** Processes are executed in FCFS order, but each is allowed to run for a maximum time slice, the **Time Quantum ($q$)**.
  * **Key Decision Point:** A running process is preempted when its time quantum expires. It is then moved to the **end of the Ready Queue**. A process can run for less than $q$ if its burst finishes early.

-----

### Must-Answer Theory

#### Differences between Preemptive vs Non-preemptive Scheduling

| Feature | **Preemptive** 🔪 | **Non-preemptive** 🤝 |
| :--- | :--- | :--- |
| **Mechanism** | A running process can be **interrupted** and forced to yield the CPU (e.g., RR, SJF-P). | A running process must **finish** its burst or **voluntarily yield** (e.g., FCFS, SJF-Non). |
| **Response Time** | Generally **better** for short jobs. | Can lead to the **convoy effect** (short jobs stuck behind long ones). |
| **Examples** | RR, Preemptive Priority, Preemptive SJF. | FCFS, Non-preemptive Priority, Non-preemptive SJF. |

#### Why concurrent processing increases OS complexity? 🤯

Concurrent processing (multiple processes/threads running logically at the same time) significantly increases complexity due to:

1.  **Synchronization:** Need to ensure multiple processes accessing shared resources (like variables, files) do so in an orderly way to maintain data consistency (e.g., using locks, semaphores).
2.  **Deadlock:** The potential for a set of processes to get stuck indefinitely, each waiting for a resource held by another.
3.  **Resource Management:** More complex management of CPU time, memory, and I/O devices to ensure fairness and efficiency.
4.  **Inter-process Communication (IPC):** Providing reliable and efficient mechanisms for processes to exchange information.

#### Multilevel Queue vs Multilevel Feedback Queue

  * **Multilevel Queue:** Partitions the ready queue into separate queues (e.g., Foreground/Interactive, Background/Batch). **Processes are permanently assigned** to a queue based on their type. *Problem: Rigid and can lead to starvation.*
  * **Multilevel Feedback Queue:** Allows processes to **move between queues** based on their CPU burst behavior.
      * A process that uses too much CPU time is moved to a lower-priority queue.
      * A process that has waited too long in a low-priority queue can be moved to a higher-priority queue (**aging**).
      * *Advantage: Most flexible; can be tuned to favor different job types (e.g., I/O bound jobs get higher priority).*

-----

## 🟧 UNIT 3 — SYNCHRONIZATION + DEADLOCK (30% guaranteed)

### Important Topics & Detailed Explanations

#### Critical Section Problem 🛑

The **critical section** is a segment of code where the process may be changing common variables, updating a table, or writing a file. The **Critical Section Problem** is to design a protocol ensuring that when one process is executing in its critical section, no other process is allowed to execute in its critical section.

**Three Conditions for a Solution:**

1.  **Mutual Exclusion:** If process $P_i$ is executing in its critical section, then no other processes can be executing in their critical sections. (**MUST BE MET**)
2.  **Progress:** If no process is in its critical section and some processes want to enter their critical sections, then only those processes not executing in their remainder section can participate in the decision of which will enter next, and this decision cannot be postponed indefinitely.
3.  **Bounded Waiting:** There exists a limit on the number of times that other processes are allowed to enter their critical sections after a process has made a request to enter its critical section and before that request is granted.

#### Peterson’s Algorithm (Two-Process Solution)

A classic software-based solution for two processes ($P_0$ and $P_1$) to the critical section problem.

**Variables:**

1.  `int turn;` (Indicates whose turn it is to enter the critical section. `turn = i` means $P_i$ is allowed).
2.  `boolean flag[2];` (`flag[i] = true` means $P_i$ wants to enter the critical section).

**Structure for Process $P_i$:**

```
do {
    flag[i] = TRUE;
    turn = j; // Give preference to the other process
    while (flag[j] && turn == j); // Busy wait
    
    // CRITICAL SECTION
    
    flag[i] = FALSE; // Indicate exit
    
    // REMAINDER SECTION
} while (TRUE);
```

**Does it ensure Progress?** Yes. If $P_i$ wants to enter, and $P_j$ is not interested (`flag[j] = false`), $P_i$ will proceed. If $P_j$ is interested, $P_i$ waits until $\text{turn} \neq j$. If $P_j$ exits, it sets $\text{flag}[j] = \text{FALSE}$, allowing $P_i$ to proceed, thus progress is guaranteed.

#### Producer-Consumer Problem (Semaphore Solution) 🍽️

**Scenario:** A **producer** process generates data/items and places them in a buffer, and a **consumer** process removes items from the buffer.
**Shared Resources:**

  * `buffer[N]` (a fixed-size buffer).
  * `mutex` (Binary Semaphore, initialized to 1, for mutual exclusion access to the buffer).
  * `empty` (Counting Semaphore, initialized to **N**, counts empty slots).
  * `full` (Counting Semaphore, initialized to **0**, counts full slots/items).

| Process | Code Snippet | Explanation |
| :--- | :--- | :--- |
| **Producer** | `wait(empty);` <br> `wait(mutex);` <br> *// add item to buffer* <br> `signal(mutex);` <br> `signal(full);` | Must wait for an **empty** slot. <br> Must acquire **mutex** for buffer access. <br> Releases mutex. <br> Signals that a slot is **full**. |
| **Consumer** | `wait(full);` <br> `wait(mutex);` <br> *// remove item from buffer* <br> `signal(mutex);` <br> `signal(empty);` | Must wait for a **full** slot (item). <br> Must acquire **mutex** for buffer access. <br> Releases mutex. <br> Signals that a slot is **empty**. |

#### Readers-Writers Problem (Semaphore Solution)

**Scenario:** Allows multiple **readers** to read a shared object simultaneously, but only one **writer** can modify the object at a time. If a writer is writing, no reader can read.

**Shared Resources:**

  * `rw_mutex` (Semaphore, initialized to 1, for mutual exclusion on **writers** and the **first/last reader**).
  * `mutex` (Semaphore, initialized to 1, for mutual exclusion on **read\_count** updates).
  * `read_count` (Integer, initialized to 0, tracks the number of reading processes).

**Writer Process:**

```
wait(rw_mutex);
// WRITING IS PERFORMED
signal(rw_mutex);
```

**Reader Process:**

```
wait(mutex); // Lock read_count update
read_count = read_count + 1;
if (read_count == 1) {
    wait(rw_mutex); // First reader locks out writers
}
signal(mutex); // Unlock read_count update

// READING IS PERFORMED

wait(mutex); // Lock read_count update
read_count = read_count - 1;
if (read_count == 0) {
    signal(rw_mutex); // Last reader unlocks writers
}
signal(mutex); // Unlock read_count update
```

#### Mutex vs Semaphore

| Feature | **Mutex** (Binary Lock) 🔒 | **Semaphore** (Signaling Mechanism) 🚦 |
| :--- | :--- | :--- |
| **Purpose** | Provides **Mutual Exclusion** (acts as a lock). | A counter used for both **Mutual Exclusion** and **Synchronization** (signaling). |
| **Value** | Logically $0$ (locked) or $1$ (unlocked). | Integer value ($0, 1, 2, \dots$) |
| **Ownership** | Must be released by the **process that acquired it**. | Can be signaled (released) by a process **other than the one that waited on it**. |

#### Deadlock Conditions (Coffman Conditions) 💀

Deadlock can occur if and only if **all four** conditions hold simultaneously:

1.  **Mutual Exclusion:** At least one resource must be held in a non-sharable mode.
2.  **Hold and Wait:** A process must be holding at least one resource and waiting to acquire additional resources held by other processes.
3.  **No Preemption:** Resources cannot be preempted; they can only be released voluntarily by the process holding them.
4.  **Circular Wait:** A set of processes $\{P_0, P_1, \dots, P_n\}$ must exist such that $P_0$ is waiting for a resource held by $P_1$, $P_1$ is waiting for a resource held by $P_2$, $\dots$, and $P_n$ is waiting for a resource held by $P_0$.

#### Deadlock Handling Strategies

  * **Prevention:** Ensures that **at least one** of the four Coffman conditions **cannot** hold. (Least efficient but guaranteed no deadlock).
  * **Avoidance:** Requires processes to provide advance information about their resource needs. The OS dynamically decides if granting a request would lead to an **unsafe state** (e.g., **Banker's Algorithm**). (Most efficient at runtime).
  * **Detection:** Allows the system to enter a deadlocked state, then runs an algorithm periodically to detect if a deadlock has occurred.
  * **Recovery:** Once detected, the system must recover by either **process termination** (aborting processes involved) or **resource preemption** (taking resources from processes).

-----

### Must-Answer Numerical Guide: Banker's Algorithm

The **Banker's Algorithm** is a deadlock avoidance algorithm. It checks whether a state is **safe** (i.e., whether there exists a safe sequence of processes).

#### Solution Writing Steps for Banker's Algorithm 📝

**Part A: Finding a Safe Sequence**

1.  **State the Goal:** The goal is to find a sequence of processes $\langle P_1, P_2, \dots, P_n \rangle$ such that for each $P_i$, the resources that $P_i$ can still request (**Need**) can be satisfied by the currently **Available** resources.
2.  **Define Need:** Calculate the **Need** matrix: $\text{Need}[i][j] = \text{Max}[i][j] - \text{Allocation}[i][j]$.
3.  **Initialize Work and Finish:**
      * $\text{Work} = \text{Available}$.
      * $\text{Finish}[i] = \text{false}$ for all processes.
4.  **Iteration Loop:** Find an index $i$ such that:
      * $\text{Finish}[i] = \text{false}$, **AND**
      * $\text{Need}_i \le \text{Work}$.
5.  **If Found:**
      * $\text{Work} = \text{Work} + \text{Allocation}_i$.
      * $\text{Finish}[i] = \text{true}$.
      * Add $P_i$ to the safe sequence.
      * Go to step 4.
6.  **If Not Found:**
      * If all $\text{Finish}[i] = \text{true}$, then the system is in a **safe state**, and the sequence is the result.
      * Otherwise, the system is in an **unsafe state** (deadlock may occur).

**Part B: Request Granting**

1.  **Check 1 (Request $\le$ Need):** The requested resources must be less than or equal to the process's declared **Need**. If not, it's an error.
2.  **Check 2 (Request $\le$ Available):** The requested resources must be less than or equal to the currently **Available** resources. If not, the process must wait.
3.  **Pretend Grant:** If both checks pass, **pretend to grant** the resources:
      * $\text{Available}' = \text{Available} - \text{Request}$.
      * $\text{Allocation}' = \text{Allocation} + \text{Request}$.
      * $\text{Need}' = \text{Need} - \text{Request}$.
4.  **Run Safety Algorithm:** Run the **safety algorithm (Part A)** on the new (primed) state.
5.  **Final Decision:**
      * If the new state is **safe**, the request is **granted** immediately.
      * If the new state is **unsafe**, the request is **denied**, and the process must wait (restore old state).

#### Deadlock Detection Algorithm Steps 🔎

Used when a system allows for deadlock to occur (unlike Banker's).

1.  **Initialization:**
      * $\text{Work} = \text{Available}$.
      * $\text{Finish}[i] = \text{true}$ if $\text{Allocation}_i = 0$ (no resources allocated), else $\text{false}$.
2.  **Search:** Find an index $i$ such that:
      * $\text{Finish}[i] = \text{false}$, **AND**
      * $\text{Request}_i \le \text{Work}$.
3.  **Update:** If such an $i$ is found:
      * $\text{Work} = \text{Work} + \text{Allocation}_i$.
      * $\text{Finish}[i] = \text{true}$.
      * Go to step 2.
4.  **Conclusion:** If no such $i$ is found:
      * If any $\text{Finish}[i] = \text{false}$, then process $P_i$ is **deadlocked**.

#### Spinlock

A **spinlock** is a type of lock that causes a process to simply **busy-wait** in a loop (repeatedly checking if the lock is available) while waiting for the lock to become available.

**When is it used?**

  * In **multiprocessor systems** (where another process can quickly release the lock on a different CPU core).
  * When the expected lock holding time is **very short**. This avoids the overhead of a context switch that would occur if the waiting process was put to sleep (blocked).

-----

## 🟨 UNIT 4 — MEMORY MANAGEMENT + VIRTUAL MEMORY

### Important Topics & Detailed Explanations

#### Fragmentation (Internal vs External) 🧩

Fragmentation is wasted memory space within or between memory partitions.

| Type | **Internal Fragmentation** | **External Fragmentation** |
| :--- | :--- | :--- |
| **Definition** | Wasted space **within** a memory partition/page. | Wasted space **between** memory partitions/segments. |
| **Cause** | Fixed-size allocation (e.g., paging) where the allocated space is slightly larger than the process need. | Dynamic allocation (e.g., segmentation) where memory is divided into many small, non-contiguous free holes. |
| **Fix** | Can only be reduced by adjusting page size. | Can be solved by **Compaction** (shuffling memory contents). |
| **Example** | A 4KB page is allocated for a process needing only 3KB. 1KB is wasted inside the page. | Total free space is 10KB, but it's split into 3KB + 2KB + 5KB holes, and an 8KB request cannot be satisfied. |

#### Paging vs Segmentation

  * **Paging:** Divides **physical memory** into fixed-size **frames** and **logical memory** into fixed-size **pages**. Aims to solve **external fragmentation**. *Unit of address space is a page.*
  * **Segmentation:** Divides **logical memory** into variable-size **segments** (logical units like code, stack, heap). Aims to simplify programming and protect logical units. *Unit of address space is a segment.*

#### Logical vs Physical Address

  * **Logical Address (Virtual Address):** Address generated by the **CPU**. The user program only sees this address.
  * **Physical Address (Real Address):** Address seen by the **memory unit**. The actual location in main memory.
  * **Mapping:** The **Memory Management Unit (MMU)** translates the logical address to the physical address using page/segment tables.

#### Page Table (Structure + Multi-level + Inverted) 📖

The **Page Table** maps a logical page number to a physical frame number.

  * **Structure:** Stores the base address of each page in physical memory, along with protection bits (read/write), valid/invalid bits, etc.
  * **Multi-Level Paging (Hierarchical):** Used to reduce the size of the page table (which can be very large). The page table is itself paged. This requires **multiple memory accesses** to find a single page.
  * **Inverted Page Table:** Stores one entry **per physical frame** (not per page). Each entry records which process/page occupies that frame. Greatly reduces memory needed for the page table but increases search time.

#### TLB & TLB Reach

  * **Translation Look-aside Buffer (TLB):** A small, fast, hardware cache that stores recent logical-to-physical address translations.
  * **TLB Hit:** The page number is found in the TLB (fast access).
  * **TLB Miss:** The page number is not found; the OS must access the Page Table (slow access).
  * **TLB Reach:** The total amount of memory a single TLB can cover without a miss.
    $$\text{TLB Reach} = \text{TLB entries} \times \text{page size}$$

#### Page Fault Handling Steps 💥

A **page fault** occurs when a process tries to access a page that is not currently in physical memory (the valid/invalid bit in the page table is 'invalid').

**Steps taken by the OS:**

1.  **Trap to OS:** The memory management hardware detects the invalid bit and traps to the OS.
2.  **Save State:** The OS saves the state of the process (context switch).
3.  **Check Validity:** The OS checks an internal table to see if the reference was valid (the page is on disk) or invalid (a segmentation fault).
4.  **Find Free Frame:** If valid, the OS finds a free physical frame (if none, a **page replacement algorithm** like LRU is run to free one).
5.  **Disk I/O:** A disk operation is scheduled to read the required page from the swap space into the new free frame.
6.  **Update Table:** The page table is updated to reflect the new physical frame number, and the valid/invalid bit is set to 'valid'.
7.  **Restart Instruction:** The instruction that caused the page fault is restarted.

-----

### Must-Answer Numerical Guide: Memory & Page Replacement

#### Effective Memory Access Time (EAT) ⏱️

**Scenario:** In systems using a TLB, memory access can take one of two paths:

1.  **TLB Hit:** Fast, single access time.
2.  **TLB Miss:** Slow, requires an extra memory access to read the Page Table.

**Formula:**
$$\text{EAT} = (\text{TLB Hit Ratio} \times \text{Hit Access Time}) + (\text{TLB Miss Ratio} \times \text{Miss Access Time})$$

Where:

  * **TLB Hit Ratio ($\alpha$):** The probability of finding the page in the TLB (e.g., $98\%$).
  * **TLB Miss Ratio ($1 - \alpha$):** The probability of a miss.
  * **Hit Access Time:** Time to access the TLB + Time to access memory (e.g., $1 \text{ TLB} + 1 \text{ Memory} = 10 \text{ns} + 100 \text{ns}$).
  * **Miss Access Time:** Time to access the TLB + Time to access the Page Table + Time to access memory (e.g., $1 \text{ TLB} + 2 \text{ Memory}$ accesses for Page Table and data).

**Solution Writing Steps for EAT:**

1.  **Identify Components:** Clearly list the given values for Hit Ratio ($\alpha$), TLB access time ($t_{\text{TLB}}$), and Memory access time ($t_{\text{MEM}}$).
2.  **Define Hit/Miss Times:** Calculate $T_{\text{Hit}}$ and $T_{\text{Miss}}$ based on the system's structure.
      * Example for a **single-level page table** with TLB:
          * $T_{\text{Hit}} = t_{\text{TLB}} + t_{\text{MEM}}$
          * $T_{\text{Miss}} = t_{\text{TLB}} + t_{\text{MEM}} + t_{\text{MEM}}$ (since a miss requires 1 TLB check, 1 PT lookup, and 1 data access).
3.  **Substitute and Calculate:** Plug the values into the main EAT formula.

#### Page Replacement Algorithms: FIFO and LRU

**Goal:** Minimize the number of **Page Faults** for a given page reference string and a fixed number of available physical frames.

**1. FIFO (First-In, First-Out)**

  * **Rule:** Replace the page that has been in memory the **longest**.
  * **Belady’s Anomaly:** This is the phenomenon where **increasing the number of physical frames** can paradoxically **increase the number of page faults**. FIFO is one of the algorithms susceptible to this.

**2. LRU (Least Recently Used)**

  * **Rule:** Replace the page that has **not been used for the longest period of time**. LRU is a **Stack Algorithm** (it doesn't suffer from Belady's Anomaly).

**Solution Writing Steps for Page Faults:**

1.  **State Parameters:** List the Page Reference String and the number of **available frames**.
2.  **Create a Trace Table:** Draw a table where columns represent time steps (reference string pages) and rows represent the available frames.
3.  **Trace Execution:**
      * For each page reference:
          * **Hit:** If the page is in memory, mark it as a Hit and proceed.
          * **Fault:** If the page is not in memory (Fault):
              * If there are **free frames**, insert the page into the first free frame.
              * If **no free frames**, identify the victim page based on the algorithm's rule (Oldest for FIFO; Least Recently Used for LRU). Replace the victim.
      * **LRU Tracking:** For LRU, you must look **backward** in the reference string from the current time to find the page that hasn't appeared for the longest time.
4.  **Count and Conclude:** Count the total number of $\text{Page Faults}$ and state the final number clearly.

-----

## 🟫 UNIT 5 — FILE SYSTEM + DISK

### Important Topics & Detailed Explanations

#### Directory Structures 📂

The directory provides a mapping between file names and the files themselves.

  * **Single-Level Directory:** All files are in one directory. Simple, but suffers from **naming conflicts** and is difficult to manage for multiple users.
  * **Two-Level Directory:** Each user has their own separate user file directory (UFD). Files are isolated, solving naming conflicts. **Problem:** Users cannot share files easily.
  * **Tree-Structured Directory (Acyclic Graph is also possible):** The most common structure. Allows users to create their own subdirectories. Efficient searching and grouping. **Problem:** File sharing is possible, but complex.
    \*

![Images of Tree-Structured Directory](https://github.com/UNKN0WN006/operating-systems-lab/blob/f626d1eaef13ee445ab67a18ed0d6e11593ea9e2/licensed-image%20(1).jpeg)

  * **Directed-Acyclic Graph (DAG):** Allows subdirectories to be shared, enabling a file to be in multiple directories (through **links**). **Problem:** Potential for **dangling pointers** if a shared file is deleted.
  * **Hash Table Directory:** Directories are implemented as a hash table for fast lookups.

#### File Attributes

Information associated with a file, stored in the directory structure:

  * **Name:** The symbolic name (human-readable).
  * **Identifier:** Unique tag (non-human-readable) that identifies the file to the file system.
  * **Type:** The file format (e.g., text, executable, archive).
  * **Location:** Pointer to the file's location on the disk.
  * **Size:** Current size of the file.
  * **Time, Date, User ID:** For creation, last modification, and last use.
  * **Protection:** Access control information (who can read, write, execute).

#### File Operations

  * `create()`: Creates a new file.
  * `write(offset, data)`: Writes data to a file starting at a specific offset.
  * `read(offset, buffer)`: Reads data from a file starting at a specific offset.
  * `reposition(offset)`: Moves the current-file-pointer (a pointer to the next read/write location).
  * `delete()`: Removes a file.
  * `truncate(length)`: Erases file content and resets its length to a specified value.
  * `open(name)`: **Crucial:** Moves file metadata from disk to memory (the **Open File Table**). Returns a file handle (descriptor).
  * `close(fd)`: Moves file metadata back to disk (if modified). Removes the entry from the Open File Table.

**Purpose of `open()` and `close()`:**

  * **`open()`:** Efficiency. Loads frequently needed file attributes/metadata into main memory to avoid constant disk I/O for every read/write operation.
  * **`close()`:** Cleanup. Frees the entry in the Open File Table and saves any modified metadata back to the disk, ensuring file integrity.

#### Problems in File Sharing

  * **Consistency:** If multiple users modify a single copy of a file simultaneously, updates must be synchronized.
  * **Protection:** Access rights must be consistent across all sharing users.
  * **Dangling Pointers (with DAG):** If a file is shared using a link and the original file is deleted, the link becomes a **dangling pointer** (it points to a non-existent file).

**Solutions:**

  * **Reference Count:** Track how many directories point to a file. Delete the file only when the count drops to zero. This solves the dangling pointer problem.
  * **Session Semantics:** Access is restricted. When a user opens a file, no one else can write to it until the first user closes it.

#### Allocation Strategies

Determines how a file's blocks are stored on the disk.

  * **Contiguous Allocation:** Each file occupies a set of **contiguous blocks** on the disk. **Pros:** Simple, excellent for sequential and direct access. **Cons:** Leads to severe **External Fragmentation**.
  * **Linked Allocation:** Each block contains a pointer to the next block. **Pros:** No external fragmentation, easy to grow. **Cons:** Poor direct access (must traverse the chain), space overhead for pointers.
  * **Indexed Allocation:** All pointers to a file's blocks are gathered into an **Index Block**. **Pros:** Excellent for direct access. **Cons:** Wasted space if the file is very small, and handling large files requires multi-level indexing.

#### Free Space Management

Methods to keep track of available disk blocks.

  * **Bit Vector (Bit Map):** An array of bits where each bit corresponds to a disk block. $1 = \text{free}$, $0 = \text{occupied}$ (or vice versa). **Pros:** Simple, easy to find contiguous space.
  * **Linked List:** Free disk blocks are linked together. Only the head of the list is stored in a special location. **Cons:** Difficult to find contiguous free blocks.

-----

## 🔥 SUPER IMPORTANT 10-MARK QUESTIONS (ALMOST CERTAIN TO APPEAR)

| Topic | Focus Area | Key Elements to Include |
| :--- | :--- | :--- |
| **⭐ 1. Gantt chart + WT + TAT** | SJF Preemptive, Priority Preemptive, RR | **Gantt Chart** (must show preemption/quantum cuts), **Formulas**, and the final table of **CT, TAT, WT** values. |
| **⭐ 2. Banker's Algorithm** | Safe sequence & Request granting | **Need Matrix** calculation, **5-step safety algorithm** logic, and the **4-step request check** logic. |
| **⭐ 3. Readers-Writers** | Semaphore solution | **Goal** (multiple readers, one writer), **Shared variables** (`rw_mutex`, `mutex`, `read_count`), and the detailed **Reader/Writer code** (especially how the first/last reader interact with `rw_mutex`). |
| **⭐ 4. Producer-Consumer** | Semaphore solution | **Goal** (synchronizing data transfer), **Shared variables** (`mutex`, `full`, `empty`), and the detailed **Producer/Consumer code** (showing the correct `wait`/`signal` order). |
| **⭐ 5. Memory Management Numerical** | LRU, EAT, TLB Reach | **LRU Trace Table** (showing reference string and frames), **EAT Formula** and the components of Hit/Miss time, and the **TLB Reach Formula**. |
| **⭐ 6. Fragmentation** | Internal vs External | **Definitions**, clear **Examples** (e.g., small file in large page vs. scattered free blocks), and the **Solution** (Paging for External; Compaction/better fit for Internal). |
| **⭐ 7. File system directory structures** | Advantages, Disadvantages | **Diagrams** (Mental or explicit

![Images of Tree-Structured Directory](https://github.com/UNKN0WN006/operating-systems-lab/blob/f626d1eaef13ee445ab67a18ed0d6e11593ea9e2/licensed-image.jpeg)
), clear **Advantages/Disadvantages** for Single, Two-Level, and Tree structures, and the **Dangling Pointer** problem in DAG. |

-----

## ✨ QUICK SUPER-COMPRESSED REVISION TOPICS (10 minutes sheet)

  * **Process states diagram:** New $\to$ Ready $\to$ Running $\to$ Waiting $\to$ Ready $\to$ Terminated.
  * **Scheduling formulas:** $\text{TAT} = \text{CT} - \text{AT}$; $\text{WT} = \text{TAT} - \text{BT}$.
  * **Safe vs unsafe state:** **Safe** state means there exists a sequence of processes that can finish without deadlock.
  * **Deadlock 4 conditions (Coffman):** **Mutual Exclusion**, **Hold and Wait**, **No Preemption**, **Circular Wait**.
  * **Banker's 3 steps:** 1. **Check Request** $\le$ **Need**. 2. **Check Request** $\le$ **Available**. 3. **Run Safety Algorithm**.
  * **Critical section 3 requirements:** **Mutual Exclusion**, **Progress**, **Bounded Waiting**.
  * **Peterson’s algorithm summary:** Uses `flag` (wants to enter) and `turn` (gives preference) to enforce mutual exclusion between two processes.
  * **Page fault sequence:** **Trap** $\to$ **Check Validity** $\to$ **Find Frame/Page Replacement** $\to$ **Disk Read** $\to$ **Update PT** $\to$ **Restart Instruction**.
  * **Fragmentation:** **Internal** (wasted space **in** partition, fixed-size), **External** (wasted space **between** partitions, variable-size).
  * **Directory structure differences:** Single (simple, naming conflict) $\to$ Two-Level (isolation, no sharing) $\to$ Tree (hierarchy, complex sharing).
  * **Dispatch latency:** Time taken by the **Dispatcher** to perform a **context switch**.
  * **CPU burst:** Time a process needs to run on the CPU before waiting for I/O.
  * **Throughput:** Number of jobs completed per unit of time.
  * **Response time:** Time from submission until the **first response** is produced.

-----

I've provided a detailed breakdown covering all your requested topics, numerical steps, and theory.

What part of this guide would you like to explore first with some practice questions? We could start with a **Banker's Algorithm** numerical, or perhaps a deep dive into **Threads**\!
