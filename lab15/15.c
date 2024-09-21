/*
MT2024128
Rohan Sonawane
Write a simple program to send some data from parent to the child process.
*/
#include <unistd.h>  
#include <sys/types.h>
#include <stdio.h> 
void main()
{
    pid_t childPid;
    int pipefd[2];      
    int pipeStatus;    
    int readBytes, writeBytes;

    char *writeBuffer = "This is data from parent", *readBuffer;

    pipeStatus = pipe(pipefd);

    if (pipeStatus == -1)
        perror("Error creating pipe!");
    else
    {
        printf("Pipe created successfully\n");
        childPid = fork();
        if (childPid == -1)
            perror("Error creating child process");
        else if (childPid == 0)
        {
            readBytes = read(pipefd[0], &readBuffer, sizeof(writeBuffer));
            if (readBytes == -1)
                perror("Error while reading from pipe!\n");
            else
                printf("Data from parent to child: %s\n", readBuffer);
        }
        else
        {
            writeBytes = write(pipefd[1], &writeBuffer, sizeof(writeBuffer));
            if (writeBytes == -1)
                perror("Error writing to pipe!");
        }
    }
}

/*
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/handsOnLab2/lab15$ gcc 15.c
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/handsOnLab2/lab15$ ./a.out
Pipe created successfully
Data from parent to child: This is data from parent
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/handsOnLab2/lab15$  

*/
