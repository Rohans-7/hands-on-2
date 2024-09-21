/*
MT2024128
Rohan Sonawane
Write a program to send and receive data from parent to child vice versa.Use two way communication.
*/
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int pipe1[2], pipe2[2];
    pid_t pid;
    char parentMsg[] = "Hello from parent!";
    char childMsg[] = "Hello from child!";
    char readBuffer[100];

    // pipe1 (parent to child) , pipe2 (child to parent)
    if (pipe(pipe1) == -1 || pipe(pipe2) == -1) {
        perror("Pipe failed");
        return 1;
    }

    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    }

    if (pid > 0) {
        close(pipe1[0]);
        close(pipe2[1]);
        write(pipe1[1], parentMsg, strlen(parentMsg) + 1);

        read(pipe2[0], readBuffer, sizeof(readBuffer));
        printf("Parent received: %s\n", readBuffer);

        close(pipe1[1]);
        close(pipe2[0]);

    } else{
        close(pipe2[0]);

        read(pipe1[0], readBuffer, sizeof(readBuffer));
        printf("Child received: %s\n", readBuffer);

        write(pipe2[1], childMsg, strlen(childMsg) + 1);

        close(pipe1[0]);
        close(pipe2[1]);
    }

    return 0;
}

/*
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/handsOnLab2/lab16$ gcc 16.c
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/handsOnLab2/lab16$ ./a.out
Child received: Hello from parent!
Parent received: Hello from child!
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/handsOnLab2/lab16$  

*/

