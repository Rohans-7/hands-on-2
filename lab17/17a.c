/*
    MT2024128
    Rohan Sonawane
    Write a program to execute ls -l | wc.
    a. use dup
    b. use dup2
    c. use fcntl
*/

#include <unistd.h> 
#include <sys/types.h>
#include <stdio.h> 

void main()
{
    int pipefd[2];  // pipefd[0] -> read, pipefd[1] -> write
    int pipeStatus; 
    pid_t childPid;

    pipeStatus = pipe(pipefd);

    if (pipeStatus == -1)
        perror("Error while creating the file!");
    else
    {
        childPid = fork();

        if (childPid == -1)
            perror("Error while forking child!");
        else if (childPid == 0)
        {
            close(STDIN_FILENO);
            dup(pipefd[0]); 
            close(pipefd[1]);
            execl("/usr/bin/wc", "wc", NULL);
        }
        else
        {
            close(STDOUT_FILENO);
            dup(pipefd[1]);
            close(pipefd[0]);
            execl("/usr/bin/ls", "ls -l", "-l", NULL);
        }
    }
}

/*
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/handsOnLab2/lab17$ ./a.out
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/handsOnLab2/lab17$       5      38     281
^C
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/handsOnLab2/lab17$  
*/
