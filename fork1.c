#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t pid  = fork();

    if (pid < 0)
    {
        printf("Fork failed");
        return 1;
    }else if (fork == 0)
    {
        char *args[] = {"./myadder", "10", "20", NULL};
        execvp(args[0], args);
    }
    else
    {
        printf("Waiting for child to finish...\n");
        wait(NULL);
    }
    return 0;
}