/*
    MT2024128
    Rohan Sonawane
    Write a simple program to create a pipe, write to the pipe, read from pipe and display on
    the monitor.
*/
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int pipefd[2];
    char writeMsg[] = "Hello from the pipe!";
    char readMsg[100];
    
    if (pipe(pipefd) == -1) {
        perror("Pipe failed");
        return 1;
    }

    write(pipefd[1], writeMsg, strlen(writeMsg) + 1);

    read(pipefd[0], readMsg, sizeof(readMsg));

    printf("Received: %s\n", readMsg);

    close(pipefd[0]);
    close(pipefd[1]);

    return 0;
}

/*
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/handsOnLab2/lab14$ gcc 14.c
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/handsOnLab2/lab14$ ./a.out
Received: Hello from the pipe!
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/handsOnLab2/lab14$

*/
