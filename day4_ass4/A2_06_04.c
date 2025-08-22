/*
Team: 06
Team Members:
    1. Anay Saha         Roll No: 002311001054
    2. Sushar Hembram    Roll No: 002311001041
    3. Debarshi Mondal   Roll No: 002311001055

Date: 20.08.2025

Assignment 4: Memory Mapping

Objective:
    - Use mmap() to map a large file (8GB) into memory.
    - Write a random byte at a random offset using file descriptor.
    - Read the byte from the mapped memory and verify correctness.
    - Observe page faults (including major faults) using the 'sar -B 1' command in another terminal.

Input Required:
    - No command line arguments required.
    - The program creates and operates on "bigfile.bin" in the current directory.

Output Generated:
    - Prints "Verified: 0xXX at offset 0xXXXXXXXX" for each successful verification.
    - Prints an error message and exits if verification fails.

Compilation:
    gcc A2_06_04.c
    
    An error will appear for allocate, just need to ignore that.
Execution:
    ./a.out

To observe page faults, run in another terminal before execution:
    sar -B 1


Sample Run: 
@UNKN0WN006 ➜ /workspaces/operating-systems-lab/day4_ass4 (main) $ gcc actual.c
Here an error will show sicne we ran the allocation from within the program and the file needs to exist to run the program efficiently.
@UNKN0WN006 ➜ /workspaces/operating-systems-lab/day4_ass4 (main) $ ./a.out
Verified: 0x38 at offset 0x2c8d5afc
Verified: 0xd4 at offset 0x163425d3
Verified: 0x49 at offset 0x652f125
Verified: 0x7c at offset 0xa5d2a9b
Verified: 0x9a at offset 0x6090d9e3
Verified: 0xc4 at offset 0x4ce4cc2a
Verified: 0xb2 at offset 0x40c2bd49
Verified: 0xf7 at offset 0x6b4fcef9
Verified: 0x84 at offset 0x116a4b0c
Verified: 0xbe at offset 0x525b0768
Verified: 0x9b at offset 0x658d8cc3
Verified: 0x18 at offset 0x37700a62
Verified: 0xc2 at offset 0x135d8c80
Verified: 0x58 at offset 0x41097952

And while executing this in one terminal, executing the sar -B 1 command in another terminal before executing the program, here's how it went:
@UNKN0WN006 ➜ /workspaces/operating-systems-lab (main) $ sar -B 1
Linux 6.8.0-1030-azure (codespaces-fc5340)      08/22/25        _x86_64_        (2 CPU)

12:46:54     pgpgin/s pgpgout/s   fault/s  majflt/s  pgfree/s pgscank/s pgscand/s pgsteal/s    %vmeff
12:46:55         0.00  20480.00   7725.00      0.00   8812.00      0.00      0.00      0.00      0.00
12:46:56         0.00  22576.00   5813.00      0.00   2824.00      0.00      0.00      0.00      0.00
12:46:57         0.00  20480.00   1757.00      0.00   1005.00      0.00      0.00      0.00      0.00
12:46:58         0.00  20556.00  13336.00      0.00   1544.00      0.00      0.00      0.00      0.00
12:46:59         0.00  22592.00   1562.00      0.00    679.00      0.00      0.00      0.00      0.00
12:47:00      2668.00  20564.00  13459.00      0.00  10306.00      0.00      0.00      0.00      0.00
12:47:01       352.00  22620.00   3155.00      0.00   4562.00      0.00      0.00      0.00      0.00
12:47:02         0.00  20536.00  23573.00      0.00  25516.00      0.00      0.00      0.00      0.00
12:47:03         0.00  20564.00    196.00      0.00    159.00      0.00      0.00      0.00      0.00
12:47:04         0.00  22564.00   4920.00      0.00   2195.00      0.00      0.00      0.00      0.00
12:47:05         0.00  20520.00   5386.00      0.00    500.00      0.00      0.00      0.00      0.00
12:47:06      7828.00  22744.00  16449.00     18.00  16132.00      0.00      0.00      0.00      0.00

12:47:06     pgpgin/s pgpgout/s   fault/s  majflt/s  pgfree/s pgscank/s pgscand/s pgsteal/s    %vmeff
12:47:07      5104.00  20480.00   5663.00     14.00   6543.00      0.00      0.00      0.00      0.00
12:47:08     16204.00  20912.00   9930.00     45.00  14147.00      0.00      0.00      0.00      0.00
12:47:09     23992.00  64688.00   8401.00     92.00  13378.00      0.00      0.00      0.00      0.00
12:47:10     12400.00  20484.00   9118.00     25.00  12396.00      0.00      0.00      0.00      0.00
12:47:11      1116.00  22976.00  14836.00      0.00  16294.00      0.00      0.00      0.00      0.00
.....
.....
12:47:42     pgpgin/s pgpgout/s   fault/s  majflt/s  pgfree/s pgscank/s pgscand/s pgsteal/s    %vmeff
12:47:43        24.00  46360.00  17460.00      3.00  33604.00  17152.00      0.00  34302.00    199.99
12:47:44         4.00  44784.00   5058.00      0.00  10509.00      0.00      0.00      0.00      0.00
12:47:45         0.00  44476.00   9665.00      0.00  26819.00  16000.00      0.00  32000.00    200.00
12:47:46         8.00  42752.00   6164.00      0.00   4680.00      0.00      0.00      0.00      0.00
12:47:47         0.00  41988.00  19566.00      0.00  23388.00  19968.00      0.00  39936.00    200.00
12:47:48        16.00  58872.00  12232.00      0.00   5559.00      0.00      0.00      0.00      0.00
^C

Average:      1345.50  52527.36  11961.55      3.81  20420.96  11976.14      0.81  23638.25    197.36
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdint.h>
#include <time.h>

#define FILE_SIZE (8L * 1024 * 1024 * 1024) // 8 GB
int main() {
    srand(time(NULL));
    // File creation using allocate
    int fd = open("bigfile.bin", O_CREAT | O_RDWR, 0666);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }
    
    // Allocating 8GB of space
    if (fallocate(fd, 0, 0, FILE_SIZE) == -1) {
        perror("Error allocating file space");
        close(fd);
        return 1;
    }

    // Memory maping the file to the virtual address space
    uint8_t *mapped_file = mmap(NULL, FILE_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (mapped_file == MAP_FAILED) {
        perror("Error mapping file to memory");
        close(fd);
        return 1;
    }

    // Infinite looping for write-read-verify cycle
    while (1) {
        // Randomly generating the offset (F) and byte value (X)
        off_t offset = rand() % FILE_SIZE;  // Offset between 0 and 8GB
        uint8_t X = rand() % 256;           // Random byte value between 0 and 255

        // Or, writing the byte X at the random offset
        if (lseek(fd, offset, SEEK_SET) == -1) {
            perror("Error seeking file");
            break;
        }
        if (write(fd, &X, 1) != 1) {
            perror("Error writing to file");
            break;
        }

        // or else reading the byte X' from the mapped memory at the same offset
        uint8_t X_prime = mapped_file[offset];

        // Verifiying if X' matches X
        if (X != X_prime) {
            // Verification failed, print error and exit
            printf("ERROR: Verification failed! Expected 0x%02x, got 0x%02x at offset 0x%lx\n", X, X_prime, offset);
            break;
        }

        // Print verification success for each iteration
        printf("Verified: 0x%02x at offset 0x%lx\n", X, offset);
    }
    // Clean up
    if (munmap(mapped_file, FILE_SIZE) == -1) {
        perror("Error unmapping file");
    }
    close(fd);
    return 0;
}