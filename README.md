# operating-systems-lab
OS lab of 3.1 Semester


## Assignment 1A: OS Commands

### Conceptual Questions:
- What is the difference between who and whoami?
- How do you check your current working directory in Linux?
- What does the ls command do? How do you list files in another directory?
- How do you create and remove directories from the command line?
- What is the purpose of the df command?
- How do you display the contents of a file? How do you copy or move files?
- What is the difference between cat, more, and less?
- How do you check file permissions and change them?
- What does the chmod 777 file1 command do?
- How do you search for a pattern in a file?
- What is the use of find and grep?
- How do you check system information and running processes?
- What is the use of umask?
- How do you redirect output to a file? What is the difference between > and >>?
- What does the | (pipe) operator do in Linux?

### Code/Script Questions:
- In A2_06_1A.sh, how are the commands and their outputs documented?
- How did your team divide the questions among members in the script?

## Assignment 1B: Environment Variables

### Conceptual Questions:
- What are environment variables? How are they different from shell variables?
- How do you get the value of an environment variable in C?
- How do you set a new environment variable in C?
- What is the syntax and use of getenv() and setenv()?
- Why should you avoid modifying system environment variables like HOME or PATH?

### Code Questions:
- In A2_06_1B.c, how do you fetch and print environment variables?
- How do you set and retrieve a custom environment variable in your code?
- What happens if you try to set an environment variable that already exists and overwrite is set to 0?

## Assignment 2A: Signal Handling

### Conceptual Questions:
- What is a signal in Unix/Linux? What is SIGINT?
- How do you catch a signal in C?
- What is the purpose of the signal() system call?
- What happens if you press Ctrl+C while your program is running?
- Why is perror used after system calls?

### Code Questions:
- In A2_06_2A.c, what does the signal handler do?
- Why do you use an infinite loop with pause() in your code?
- What would happen if you didn't register a signal handler for SIGINT?

## Assignment 2B: IPC using Named Pipe (FIFO)

### Conceptual Questions:
- What is IPC? What are FIFOs (named pipes)?
- How do you create a FIFO in Linux?
- How does the parent-child communication happen in your program?
- Why do you use two FIFOs for the round-trip file transfer?
- How do you measure the time taken for the transfer?
- How do you verify that the file returned is identical to the original?

### Code Questions:
- In A2_06_2B.c, what is the role of mkfifo()?
- How does the child process read and write data?
- Why do you use wait(NULL) in the parent process?
- What is the buffer size used for reading and writing?
- How is error handling done in your code?

## Assignment 3: Parallel Matrix Multiplication in Python

### Conceptual Questions:
- Why is parallelism useful for matrix multiplication?
- What is the difference between threading and multiprocessing in Python?
- How do you split the workload among processes?
- Why do you use multiprocessing.Queue?
- How do you measure only the multiplication time (excluding initialization)?
- What is the effect of increasing the number of processes?

### Code Questions:
- In A2_06_03,py.py, how do you divide the matrix rows among processes?
- How do you collect results from each process?
- What happens if the number of processes does not divide the matrix size evenly?
- How do you print matrices conditionally?
- How do you ensure that the result matrix is assembled in the correct order?

## Assignment 4: mmap and Page Faults

### Conceptual Questions:
- What is mmap() and why is it used?
- What is a page fault? How can you observe page faults in Linux?
- How do you create a large file in Linux?
- What is the purpose of writing a random byte at a random offset?
- Why do you verify the value read from the mapped memory?
- What is the difference between major and minor page faults?
- How does sar -B 1 help in observing page faults?

### Code Questions:
- In A2_06_04.c, how do you create and allocate space for the big file?
- How do you map the file into memory?
- How do you generate random offsets and values?
- How do you verify correctness after writing and reading?
- What happens if verification fails?
- Why do you use an infinite loop in your program?
- What is the difference between your implementations in actual.c, diff.c, and diff3.c?

#### General/Integration Questions:
- How did you divide the work among team members?
- What challenges did you face in implementing or testing these assignments?
- How would you improve the efficiency or robustness of any of your programs?
- How do you ensure your code is portable and robust?

## Possible Viva Questions for Assignments 1–4

### **Assignment 1A: OS Commands**
- What is the difference between `who` and `whoami`?
- How do you check your current working directory in Linux?
- What does the `ls` command do? How do you list files in another directory?
- How do you create and remove directories from the command line?
- What is the purpose of the `df` command?
- How do you display the contents of a file? How do you copy or move files?
- What is the difference between `cat`, `more`, and `less`?
- How do you check file permissions and change them?
- What does the `chmod 777 file1` command do?
- How do you search for a pattern in a file?
- What is the use of `find` and `grep`?
- How do you check system information and running processes?
- What is the use of `umask`?
- How do you redirect output to a file? What is the difference between `>` and `>>`?
- What does the `|` (pipe) operator do in Linux?

### **Assignment 1B: Environment Variables**
- What are environment variables? How are they different from shell variables?
- How do you get the value of an environment variable in C?
- How do you set a new environment variable in C?
- What is the syntax and use of `getenv()` and `setenv()`?
- Why should you avoid modifying system environment variables like `HOME` or `PATH`?

### **Assignment 2A: Signal Handling**
- What is a signal in Unix/Linux? What is `SIGINT`?
- How do you catch a signal in C?
- What is the purpose of the `signal()` system call?
- What happens if you press Ctrl+C while your program is running?
- Why is `perror` used after system calls?

### **Assignment 2B: IPC using Named Pipe (FIFO)**
- What is IPC? What are FIFOs (named pipes)?
- How do you create a FIFO in Linux?
- How does the parent-child communication happen in your program?
- Why do you use two FIFOs for the round-trip file transfer?
- How do you measure the time taken for the transfer?
- How do you verify that the file returned is identical to the original?

### **Assignment 3: Parallel Matrix Multiplication in Python**
- Why is parallelism useful for matrix multiplication?
- What is the difference between threading and multiprocessing in Python?
- How do you split the workload among processes?
- Why do you use the `multiprocessing` module?
- How do you measure only the multiplication time (excluding initialization)?
- What is the effect of increasing the number of processes?

### **Assignment 4: mmap and Page Faults**
- What is `mmap()` and why is it used?
- What is a page fault? How can you observe page faults in Linux?
- How do you create a large file in Linux?
- What is the purpose of writing a random byte at a random offset?
- Why do you verify the value read from the mapped memory?
- What is the difference between major and minor page faults?
- How does `sar -B 1` help in observing page faults?

### **General/Integration Questions**
- How did you divide the work among team members?
- What challenges did you face in implementing or testing these assignments?
- How would you improve the efficiency or robustness of any of your programs?
- How do you ensure your code is portable and robust?

~~~# End of README.md