/*
 * hole.c - call lseek() to create a hole in a text file
 * $ ./hole
 * $ od -c file.hole
 */
#include "apue.h"
#include <fcntl.h>

char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";

int main()
{
    int fd;
    if ((fd = creat("file.hole", FILE_MODE)) < 0) {
        err_sys("creat() error");
    }

    if (write(fd, buf1, strlen(buf1)) != strlen(buf1)) {
        err_sys("buf1 write() error");
    }

    if (lseek(fd, 16384, SEEK_SET) == -1) {
        err_sys("lseek() error");
    }

    if ((write(fd, buf2, strlen(buf2))) != strlen(buf2)) {
        err_sys("buf2 write() error");
    }

    close(fd);
    return 0;
}

