#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char **argv) {
    pid_t pid1, pid2, pid3,pid4,pid5;
    pid1 = fork();

    if (pid1 < 0)
    {
        perror("Fork failed");
        exit(1);
    }

    if (pid1 > 0) 
    {
        printf("Parent Process with PID: %d and PPID: %d\n", getpid(), getppid());
        wait(NULL);
    }
     else
    {
        printf("Child process A with PID: %d and PPID: %d\n", getpid(), getppid());
        pid2 = fork();

        if (pid2 < 0) 
        {
            perror("Fork failed");
            exit(1);
        }

        if (pid2 > 0) 
        {
            wait(NULL);
        }
         else 
        {
            printf("Child process B with PID: %d and PPID: %d\n", getpid(), getppid());
            pid3 = fork();
            if (pid3 < 0) 
            {
                perror("Fork failed");
                exit(1);
            }

            if (pid3 > 0) 
            {
                wait(NULL);
            }
             else
            {
              printf("Child process C with PID: %d and PPID: %d\n", getpid(), getppid());
              pid4=fork();
              if (pid4 < 0) 
            {
                perror("Fork failed");
                exit(1);
            }

            if (pid4 > 0) 
            {
                wait(NULL);
            }
             else
            {
              printf("Child process D with PID: %d and PPID: %d\n", getpid(), getppid());
              pid5=fork();
              if (pid5 < 0) 
            {
                perror("Fork failed");
                exit(1);
            }

            if (pid5 > 0) 
            {
                wait(NULL);
            }
             else
            {
              printf("Child process E with PID: %d and PPID: %d\n", getpid(), getppid());
            }
            }
        }
        }
    }

    return 0;
}
