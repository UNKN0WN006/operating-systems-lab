#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/mman.h>
#include<unistd.h>
#include<stdint.h>
#include<inttypes.h>
#include<time.h>

#define FILE_SIZE (8L * 1024L * 1024L * 1024L) //8GB
int main() {
    const char *filename = "bigfile.bin";
    srand(time(NULL)); // Seeding random number generator

    int fd = open(filename, O_RDWR);
    if (fd == -1) {
        perror("Failed to open file");
        return 1;
    }
    // Pre-allocating file space once
    fallocate(fd, 0, 0, FILE_SIZE);
    while (1) {
        // Generating a random offset (F) between 0 and 8GB
        off_t F = ((off_t)rand() * RAND_MAX + rand()) % FILE_SIZE;

        // Generating a random byte value (X) between 0 and 255
        uint8_t X = rand() % 256;

        // Writing the byte X at offset F
        if (lseek(fd, F, SEEK_SET) == -1) {
            perror("Failed to seek to offset F");
            break;
        }
        if (write(fd, &X, 1) != 1) {
            perror("Failed to write byte to file");
            break;
        }
        // Mapping the file into memory using mmap()
        uint8_t *mapped_file = mmap(NULL, FILE_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
        if (mapped_file == MAP_FAILED) {
            perror("Failed to mmap the file");
            break;
        }

        // Reading the byte at offset F
        uint8_t X_prime = mapped_file[F];
        if (X == X_prime) {
            printf("Verification successful: byte value at offset 0x%" PRIx64 " is correct.\n", (uint64_t)F);
        } else {
            printf("ERROR: Verification failed at offset 0x%" PRIx64 ". Expected byte 0x%02x, but found byte 0x%02x.\n",
                   (uint64_t)F, X, X_prime);
            munmap(mapped_file, FILE_SIZE);
            break;
        }
        // Cleanup
        munmap(mapped_file, FILE_SIZE);
        usleep(10000); // slow down loop if needed
    }
    close(fd);
    return 0;
}