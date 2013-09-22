/*
 * seek.c - Demos lseek() function
 * $ seek < /etc/motd
 * cat /etc/legal | seek
 */
#include "apue.h"

int main()
{
    if (lseek(STDIN_FILENO, 0, SEEK_CUR) == -1) {
        printf("cannot seek\n");
    }
    else {
        printf("Seek OK\n");
    }

    return 0;
}

