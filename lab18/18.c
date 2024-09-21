
/*
    MT2024128
    Rohan Sonawane
    Write a program to find out total number of directories on the pwd.
    execute ls -l | grep ^d | wc ? Use only dup2.
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int pipe1[2], pipe2[2]; // Two pipes: one for ls -> grep, one for grep -> wc
    pid_t pid1, pid2, pid3;

    if (pipe(pipe1) == -1) {
        perror("Pipe1 failed");
        return 1;
    }

    if (pipe(pipe2) == -1) {
        perror("Pipe2 failed");
        return 1;
    }
    if ((pid1 = fork()) == 0) {
        dup2(pipe1[1], STDOUT_FILENO);
        close(pipe1[0]);
        close(pipe1[1]);
        execlp("ls", "ls", "-l", NULL);
        perror("ls failed");
        exit(1);
    }

    if ((pid2 = fork()) == 0) {
        dup2(pipe1[0], STDIN_FILENO);
        dup2(pipe2[1], STDOUT_FILENO);
        close(pipe1[1]);
        close(pipe1[0]);
        close(pipe2[0]);
        close(pipe2[1]);

        execlp("grep", "grep", "^d", NULL);
        perror("grep failed");
        exit(1);
    }

    if ((pid3 = fork()) == 0) {
        dup2(pipe2[0], STDIN_FILENO);
        close(pipe1[0]); 
        close(pipe1[1]);
        close(pipe2[1]);
        close(pipe2[0]); 

        execlp("wc", "wc", "-l", NULL);
        perror("wc failed");
        exit(1);
    }

    close(pipe1[0]);
    close(pipe1[1]);
    close(pipe2[0]);
    close(pipe2[1]);

    wait(NULL);
    wait(NULL);
    wait(NULL);

    return 0;
}

/*
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/handsOnLab2/lab18$ gcc 18.c
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/handsOnLab2/lab18$ ./a.out
0
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/handsOnLab2/lab18$  
*/

