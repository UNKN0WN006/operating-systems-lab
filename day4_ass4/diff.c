#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdint.h>
#include <time.h>

#define FILE_SIZE (8L * 1024L * 1024L * 1024L) // 8GB

int main() {
    int fd = open("bigfile.bin", O_RDWR);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    srand(time(0));

    // Make sure file is big enough
    fallocate(fd, 0, 0, FILE_SIZE);

    while (1) {
        off_t pos = (off_t)rand() % FILE_SIZE;
        unsigned char val = rand() % 256;

        lseek(fd, pos, SEEK_SET);
        write(fd, &val, 1);

        unsigned char *mem = mmap(NULL, FILE_SIZE, PROT_READ, MAP_SHARED, fd, 0);
        if (mem == MAP_FAILED) {
            perror("mmap");
            break;
        }

        if (mem[pos] == val) {
            printf("OK at 0x%lx\n", (unsigned long)pos);
        } else {
            printf("Mismatch at 0x%lx: wrote 0x%x, read 0x%x\n", (unsigned long)pos, val, mem[pos]);
            munmap(mem, FILE_SIZE);
            break;
        }

        munmap(mem, FILE_SIZE);
        usleep(10000);
    }

    close(fd);
    return 0;
}
