#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    pid_t pid1, pid2, pid3, pid4, pid5;
    int status1, status2, status3;

    pid1 = fork();

    if (pid1 != 0)
    {
        pid2 = fork();

        if (pid2 != 0)
        {
            waitpid(pid2,&status1,0);
            printf("Process P0 with PID=%d, PPID=%d.\n", getpid(), getppid());
            execlp("ps", "ps", NULL);
        }
        else
        {
            pid3 = fork();
            if (pid3 != 0){
                pid4 = fork();
                if (pid4 != 0){
                    pid5 = fork();
                    if (pid5 != 0){
                        wait(&status2);
                        wait(&status3);
                        printf("Process P2 with PID=%d, PPID=%d.\n", getpid(), getppid());
                    }
                    else{
                        printf("Process P5 with PID=%d, PPID=%d.\n", getpid(), getppid());
                    }
                }
                else{
                    printf("Process P4 with PID=%d, PPID=%d.\n", getpid(), getppid());
                }
            }
            else{
                printf("Process P3 with PID=%d, PPID=%d.\n", getpid(), getppid());
            }
        }
    }

    else
    {
        printf("Process P1 with PID=%d, PPID=%d.\n", getpid(), getppid());
    }
}

