/*
 * Exercise 3.6
 * If you open a file for readwrite with the append flag, can you still read
 * from anywhere in the file using lseek? Can you use lseek to replace existing
 * data in the file? Write a program to verify this
 *
 * Use:
 * $a.out file.txt
 */
#include "apue.h"
#include <fcntl.h>

int main(int argc, char **argv)
{
    int fd;
    char buf[MAXLINE];
    char *replace = "Replace";

    if ((fd = open(argv[1], O_RDWR | O_APPEND)) == -1) {
        err_sys("open fail");
    }

    if (lseek(fd, 20, SEEK_SET) == -1) {
        err_sys("lseek fail");
    }
    if (read(fd, buf, MAXLINE) < 0) {
        err_sys("read after lseek error");
    }
    else {
        printf("%s\n", buf);
    }

    /* Rewind to 20 from beginning */
    if (lseek(fd, 20, SEEK_SET) == -1) {
        err_sys("lseek fail 2");
    }
    if (write(fd, replace, strlen(replace)) != strlen(replace)) {
        err_sys("write after lseek fail");
    }

    /*Last step, verify write*/
    if (lseek(fd, 0, SEEK_SET) == -1) {
        err_sys("lseek fail 3");
    }
    if (read(fd, buf, MAXLINE) < 0) {
        err_sys("read fail 2");
    }
    else {
        printf("file after write: %s\n", buf);
    }

    close(fd);
    return 0;
}


