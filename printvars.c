#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

char *custom_env[] = {"USER=Pikachu", "PATH=/tmp", NULL};

int main(void)
{
    int status;
    printf("Running parent process PID: %d \n", getppid());
    printf("\n");
    pid_t pid = fork();
    if(pid == 0) {
        printf("Running child process PID: %d \n", getpid());
        execle("./echoall", "echoall", "Bandicoot", "Pacman", (char*)NULL, custom_env);
    } else {
        waitpid(pid, &status, 0);
        pid_t pid1 = fork();
        if(pid1 == 0) {
            printf("Running child process PID: %d \n", getpid());
            const char *file = "echoall";
            execlp(file, "echoall", "Spyro", (char*)NULL);
        }
    }
    exit(0);
}