#####################################################################################################
# Team : 06
# Team Members:
#  - Team Member 1: Anay Saha (002311001054)
#  - Team Member 2: Debarshi Mondal (002311001055)
#  - Team Member 3: Sushar Hembram (002311001041)
# 
#  Date: 13.08.2025
#  Assignment 3: Parallel Programming in Python
# 
#  Description: 
#  This program performs parallel matrix multiplication using Python's multiprocessing module. It generates two random square matrices of a specified size, multiplies them in parallel by dividing the computation across multiple processes, and measures the execution time. The number of processes, matrix size, random value range, and output verbosity are configurable via command-line arguments.
#    
#   Execution:
#   python A2_06_03.py <matrix_size> <num_processes> <mod> <print_switch>
#   
#   Sample Run:
#   adminpc@adminpc-HP-Pro-Tower-280-G9-PCI-Desktop-PC:~/Desktop$ python3 pmatricmul.py  3000 4 100 1
# Matrix A:
# [[87 47 43 ... 54  4 93]
#  [93 22 14 ... 72 57  3]
#  [66 15  3 ... 95 50 78]
#  ...
#  [77 80 77 ... 53 92 62]
#  [76 21 97 ... 70 81 12]
#  [82 75 30 ...  6 14 72]]
# 
# Matrix B:
# [[40 34 40 ... 14 28 51]
#  [ 4 37 83 ... 81 74 50]
#  [50 77 84 ... 32  5 37]
#  ...
#  [80 99 73 ... 41 66 71]
#  [34 41  8 ... 46 54  3]
#  [71 83 66 ... 75 55  0]]
# 
# Matrix multiplication complete using 4 processes.
# Time taken (multiplication only): 20.57 seconds
#
#
#   On Running mpstat -p All 1 on another terminal, the CPU statistics:
#   01:31:39 PM IST  CPU    %usr   %nice    %sys %iowait    %irq   %soft  %steal  %guest  %gnice   %idle
# 01:31:40 PM IST  all   50.08    0.00    0.42    0.00    0.00    0.00    0.00    0.00    0.00   49.50
# 01:31:40 PM IST    0    0.00    0.00    1.01    0.00    0.00    0.00    0.00    0.00    0.00   98.99
# 01:31:40 PM IST    1  100.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00
# 01:31:40 PM IST    2   27.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00   73.00
# 01:31:40 PM IST    3   72.28    0.00    0.99    0.00    0.00    0.00    0.00    0.00    0.00   26.73
# 01:31:40 PM IST    4    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00  100.00
# 01:31:40 PM IST    5  100.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00
# 01:31:40 PM IST    6   99.01    0.00    0.99    0.00    0.00    0.00    0.00    0.00    0.00    0.00
# 01:31:40 PM IST    7    1.98    0.00    0.99    0.00    0.00    0.00    0.00    0.00    0.00   97.03
# 01:31:40 PM IST    8   87.13    0.00    0.99    0.00    0.00    0.00    0.00    0.00    0.00   11.88
# 01:31:40 PM IST    9   12.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00   88.00
# 01:31:40 PM IST   10    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00  100.00
# 01:31:40 PM IST   11  100.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00

# 01:31:40 PM IST  CPU    %usr   %nice    %sys %iowait    %irq   %soft  %steal  %guest  %gnice   %idle
# 01:31:41 PM IST  all   50.04    0.00    0.17    0.08    0.00    0.00    0.00    0.00    0.00   49.71
# 01:31:41 PM IST    0   11.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00   89.00
# 01:31:41 PM IST    1   90.00    0.00    1.00    0.00    0.00    0.00    0.00    0.00    0.00    9.00
# 01:31:41 PM IST    2  100.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00
# 01:31:41 PM IST    3    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00  100.00
# 01:31:41 PM IST    4    4.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00   96.00
# 01:31:41 PM IST    5   96.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00    4.00
# 01:31:41 PM IST    6   81.00    0.00    1.00    0.00    0.00    0.00    0.00    0.00    0.00   18.00
# 01:31:41 PM IST    7   18.18    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00   81.82
# 01:31:41 PM IST    8  100.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00
# 01:31:41 PM IST    9    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00  100.00
# 01:31:41 PM IST   10   40.00    0.00    0.00    1.00    0.00    0.00    0.00    0.00    0.00   59.00
# 01:31:41 PM IST   11   60.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00   40.00

# 01:31:41 PM IST  CPU    %usr   %nice    %sys %iowait    %irq   %soft  %steal  %guest  %gnice   %idle
# 01:31:42 PM IST  all   50.63    0.00    0.08    0.00    0.00    0.00    0.00    0.00    0.00   49.29
# 01:31:42 PM IST    0    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00  100.00
# 01:31:42 PM IST    1  100.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00
# 01:31:42 PM IST    2  100.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00
# 01:31:42 PM IST    3    1.01    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00   98.99
# 01:31:42 PM IST    4    2.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00   98.00
# 01:31:42 PM IST    5  100.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00
# 01:31:42 PM IST    6  100.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00
# 01:31:42 PM IST    7    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00  100.00
# 01:31:42 PM IST    8   95.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00    5.00
# 01:31:42 PM IST    9    5.10    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00   94.90
# 01:31:42 PM IST   10   59.41    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00   40.59
# 01:31:42 PM IST   11   42.00    0.00    1.00    0.00    0.00    0.00    0.00    0.00    0.00   57.00

# 01:31:42 PM IST  CPU    %usr   %nice    %sys %iowait    %irq   %soft  %steal  %guest  %gnice   %idle
# 01:31:43 PM IST  all   23.03    0.00    0.50    0.00    0.00    0.00    0.00    0.00    0.00   76.47
# 01:31:43 PM IST    0   28.28    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00   71.72
# 01:31:43 PM IST    1   17.17    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00   82.83
# 01:31:43 PM IST    2   31.68    0.00    0.99    0.00    0.00    0.00    0.00    0.00    0.00   67.33
# 01:31:43 PM IST    3   14.29    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00   85.71
# 01:31:43 PM IST    4   29.29    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00   70.71
# 01:31:43 PM IST    5   15.84    0.00    1.98    0.00    0.00    0.00    0.00    0.00    0.00   82.18
# 01:31:43 PM IST    6   45.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00   55.00
####################################################################################################
import numpy as np
import multiprocessing as mp
import time
import sys

def multiply_rows(start_row, end_row, A, B, result_queue):
    partial = np.dot(A[start_row:end_row], B)
    result_queue.put((start_row, partial))

def main():
    if len(sys.argv) != 5:
        print("Usage: python A2_06_03.py <matrix_size> <num_processes> <mod> <print_switch>")
        sys.exit(1)
    else:
        size = int(sys.argv[1])  # Matrix size
        num_procs = int(sys.argv[2])  # Number of parallel processes
        mod = int(sys.argv[3])  # Modulo value for random int generation
        print_switch = int(sys.argv[4])  # Print matrices? 1 = yes, 0 = no

    # Initializing matrices A and B with random values
    A = np.random.randint(0, mod, (size, size)).astype(np.uint32)
    B = np.random.randint(0, mod, (size, size)).astype(np.uint32)

    # Print matrices A and B if needed
    if print_switch:
        print("Matrix A:")
        print(A)
        print("\nMatrix B:")
        print(B)

    # Calculating the chunk size for each process
    step = size // num_procs
    processes = []
    result_queue = mp.Queue()

    # Recording the start time of the process
    start_time = time.time()

    # Start the parallel processes
    for i in range(num_procs):
        start = i * step
        if i == num_procs - 1:
            end = size
        else:
            end = (i + 1) * step
        p = mp.Process(target=multiply_rows, args=(start, end, A, B, result_queue))
        processes.append(p)
        p.start()

    # Initializing an empty result matrix
    result = np.zeros((size, size)).astype(np.uint32)

    # Collecting the partial results from the result_queue
    for _ in range(num_procs):
        start_idx, partial = result_queue.get()
        result[start_idx:start_idx + partial.shape[0]] = partial

    # Waiting for all processes to finish
    for p in processes:
        p.join()

    # Recording the end time
    end_time = time.time()
    elapsed = end_time - start_time

    # Printing results and elapsed time
    print("\nMatrix multiplication complete using %d processes." % num_procs)
    print("Time taken (multiplication only): %.2f seconds" % elapsed)

    # Printing the resulting matrix if needed
    if print_switch:
        print("\nResult Matrix:")
        print(result)

if __name__ == "__main__":
    main()