#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdint.h>
#include <time.h>

#define FILE_SIZE (8L * 1024 * 1024 * 1024) // 8 GB

int main() {
    // Random seed initialization
    srand(time(NULL));

    // Step 1: Create a large file using fallocate
    int fd = open("bigfile.bin", O_CREAT | O_RDWR, 0666);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }
    
    // Allocate 8GB of space
    if (fallocate(fd, 0, 0, FILE_SIZE) == -1) {
        perror("Error allocating file space");
        return 1;
    }

    // Step 2: Memory map the file to the virtual address space
    uint8_t *mapped_file = mmap(NULL, FILE_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (mapped_file == MAP_FAILED) {
        perror("Error mapping file to memory");
        return 1;
    }

    // Step 3: Infinite loop for write-read-verify cycle
    while (1) {
        // Step 3a: Randomly generate the offset (F) and byte value (X)
        off_t offset = rand() % FILE_SIZE;  // Offset between 0 and 8GB
        uint8_t X = rand() % 256;           // Random byte value between 0 and 255

        // Step 3b: Write the byte X at the random offset
        if (lseek(fd, offset, SEEK_SET) == -1) {
            perror("Error seeking file");
            return 1;
        }
        if (write(fd, &X, 1) != 1) {
            perror("Error writing to file");
            return 1;
        }

        // Step 3c: Read the byte X' from the mapped memory at the same offset
        uint8_t X_prime = mapped_file[offset];

        // Step 3d: Verification - Check if X' matches X
        if (X != X_prime) {
            // Verification failed, print error and exit
            printf("ERROR: Verification failed! Expected 0x%02x, got 0x%02x at offset 0x%lx\n", X, X_prime, offset);
            break;
        }

        // Step 3e: (Optional) You can log the verification success for debugging purposes
        // printf("Verification successful: X = 0x%02x at offset 0x%lx\n", X, offset);

        // Continue loop with the next random offset and value
        // The process repeats indefinitely, hence no break from the loop unless failure occurs
    }

    // Clean up
    if (munmap(mapped_file, FILE_SIZE) == -1) {
        perror("Error unmapping file");
    }
    close(fd);

    return 0;
}
