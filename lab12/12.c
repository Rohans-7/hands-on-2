/*
MT2024128
Rohan Sonawane
Write a program to create an orphan process. Use kill system call to send SIGKILL signal to
the parent process from the child process.
*/
#include <sys/types.h> 
#include <signal.h> 
#include <unistd.h>   
#include <stdio.h>   

void main()
{
    pid_t childPid, parentPid;
    int killStatus;

    childPid = fork();

    if (childPid == -1)
        perror("Error while creating child!");
    else if (!childPid)
    {
        printf("Child PID: %d\n", getpid());
        printf("Parent PID: %d\n", getppid());

        sleep(10);

        killStatus = kill(getppid(), SIGKILL);

        if (!killStatus)
        {
            printf("Successfully killed parent!\n");
            sleep(10);
            printf("Child now exiting!\n");
        }
        else
            perror("Error while killing parent!");
    }
    else
    {
        while (1);
    }
}

/*
gcc 12.c
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/handsOnLab2/lab12$ ./a.out
Child PID: 6754
Parent PID: 6753
Successfully killed parent!
Killed
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/handsOnLab2/lab12$ Child now exiting!
^C
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/handsOnLab2/lab12$
*/


