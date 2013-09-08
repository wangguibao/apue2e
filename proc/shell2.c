#include "apue.h"
#include <sys/wait.h>

void sig_int(int signo)
{
    printf("Interrupt\n");
}

int main()
{
    char buf[MAXLINE];
    pid_t pid;
    int status;

    if (signal(SIGINT, sig_int) == SIG_ERR) {
        err_sys("signal() error");
    }

    printf("%% ");
    while ((fgets(buf, MAXLINE, stdin)) != NULL) {
        int n = strlen(buf);
        if (buf[n - 1] == '\n') {
            buf[n - 1] = '\0';
        }

        if ((pid = fork()) < 0) {
            err_sys("fork error");
        }
        else if (pid == 0) {                    /* child */
            execlp(buf, buf, (char *) 0);
        }

        if ((pid = waitpid(pid, &status, 0)) < 0) {
            err_sys("waitpid error");
        }

        printf("%% ");
    }

    return 0;
}
