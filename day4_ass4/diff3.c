#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdint.h>
#include <inttypes.h> // For printing offset in hexadecimal format

#define FILE_SIZE (8L * 1024L * 1024L * 1024L)  // 8GB file size

int main() {
    const char *filename = "bigfile.bin";   // The 8GB file we created earlier
    int fd = open(filename, O_RDWR);        // Open file for read/write access
    if (fd == -1) {
        perror("Failed to open file");
        return 1;
    }

    // Step 1: Generate a random offset (F) between 0 and 8GB
    off_t F = rand() % FILE_SIZE;  // Random offset in the file (0 <= F < 8GB)

    // Step 2: Generate a random byte value (X) between 0 and 255
    uint8_t X = rand() % 256;  // Random byte value (0 <= X <= 255)

    // Step 3: Allocate space in the file using fallocate (pre-allocate the file if not done already)
    fallocate(fd, 0, 0, FILE_SIZE);

    // Step 4: Use dd to write the byte X at the specific offset F (same as your earlier script)
    if (lseek(fd, F, SEEK_SET) == -1) {
        perror("Failed to seek to offset F");
        close(fd);
        return 1;
    }
    if (write(fd, &X, 1) != 1) {
        perror("Failed to write byte to file");
        close(fd);
        return 1;
    }

    // Step 5: Map the file into memory using mmap()
    uint8_t *mapped_file = mmap(NULL, FILE_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (mapped_file == MAP_FAILED) {
        perror("Failed to mmap the file");
        close(fd);
        return 1;
    }

    // Step 6: Read the byte at the specific offset F from the mapped memory
    uint8_t X_prime = mapped_file[F];

    // Step 7: Verify that X and X' are the same
    if (X == X_prime) {
        printf("Verification successful: byte value at offset 0x%" PRIx64 " is correct.\n", (uint64_t)F);
    } else {
        // Print error message with the offset in hexadecimal format and terminate the program
        printf("ERROR: Verification failed at offset 0x%" PRIx64 ". Expected byte 0x%02x, but found byte 0x%02x.\n", 
               (uint64_t)F, X, X_prime);
        munmap(mapped_file, FILE_SIZE);
        close(fd);
        return 1;
    }

    // Step 8: Cleanup
    munmap(mapped_file, FILE_SIZE);  // Unmap the file from memory
    close(fd);  // Close the file descriptor

    return 0;
}
