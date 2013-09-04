#include "apue.h"

int main()
{
    char c;
    while((c = getc(stdin)) != EOF) {
        if (putc(c, stdout) == EOF) {
            err_sys("output error");
        }
    }

    if (ferror(stdin)) {
        err_sys("input error");
    }

    return 0;
}

