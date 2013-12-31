#include "apue.h"

int main(void)
{
    char *ptr;
    int size;

    if (chdir("/var/spool/mail") < 0) {
        err_sys("chdir failed");
    }

    ptr = path_alloc(&size);
    if (getcwd(ptr, size) == NULL) {
        err_sys("getcwd failed");
    }

    printf("cwd = %s\n", ptr);

    return 0;
}

