#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#define PageSize 1024

int main(int argc, char *argv[]) {
    int fd;
    struct stat st;
    char *mapped;
        if ((fd = open("/Users/liutong/Desktop/android/mmap/file",
             O_RDWR)) < 0) {
        printf("wrong!\n");
        return 0;
    }
    if (fstat(fd, &st) == -1) {
        printf("wrong!\n");
        return 0;
    }
    lseek(fd, 1024, SEEK_SET);
    if ((mapped = mmap(NULL, PageSize, PROT_READ|PROT_WRITE,
            MAP_SHARED, fd, 0)) == (void *)-1) {
        printf("mmap wrong!\n");
    }
    int size = st.st_size;
    printf("size:\n");
    printf("%d\n", size);
    char *buf = "zhn loves me";
    memcpy(mapped, buf, strlen(buf));
    if (msync((void *)mapped, PageSize, MS_SYNC) == -1) {
        printf("msync wrong!\n");
        return 0;
    }
    close(fd);
    printf("\n");
    printf("%s\n", mapped);
    return 0;

}