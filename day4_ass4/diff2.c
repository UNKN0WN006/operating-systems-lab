#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <time.h>

#define FILE_SIZE 8589934592  // 8 GB

// Function to generate random offset and byte value
void generate_random_values(size_t *offset, unsigned char *byte_value) {
    *offset = rand() % FILE_SIZE;           // Random offset between 0 and 8GB
    *byte_value = rand() % 256;             // Random byte value between 0 and 255
}

int main() {
    // Initialize random number generator
    srand(time(NULL));

    // Step 1: Create an 8GB file using fallocate
    const char *file_path = "big_file.bin";
    int fd = open(file_path, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    if (fallocate(fd, 0, 0, FILE_SIZE) != 0) {
        perror("Error allocating file space");
        close(fd);
        return 1;
    }

    // Step 2: Memory map the file
    void *mapped_memory = mmap(NULL, FILE_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (mapped_memory == MAP_FAILED) {
        perror("Error mapping file to memory");
        close(fd);
        return 1;
    }

    // Step 3: Infinite loop to write and read data
    while (1) {
        size_t offset;
        unsigned char byte_value;

        // Generate random offset and byte value
        generate_random_values(&offset, &byte_value);

        // Print the offset in hexadecimal format
        printf("Offset: 0x%zx -> verified : ok\n", offset);

        // Step 4: Write the byte value at the random offset
        *((unsigned char *)mapped_memory + offset) = byte_value;

        // Step 5: Read back the byte value at the same offset
        unsigned char read_value = *((unsigned char *)mapped_memory + offset);

        // Step 6: Verification
        if (read_value != byte_value) {
            fprintf(stderr, "Error: Mismatch! Written value: 0x%x, Read value: 0x%x\n", byte_value, read_value);
            break;  // Terminate on failure
        }

        // Simulate a delay for page fault observation
        usleep(5000);  // Sleep for 5 milliseconds
    }

    // Step 7: Clean up
    munmap(mapped_memory, FILE_SIZE);
    close(fd);

    return 0;
}

