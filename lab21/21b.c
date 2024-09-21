/*
MT2024128
Rohan Sonawane
Write two programs so that both can communicate by FIFO -Use two way communication.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd_read, fd_write;
    char *fifo1 = "fifo1";
    char *fifo2 = "fifo2";
    char buffer[100];
    char message[] = "Hello from Program B!";

    fd_read = open(fifo1, O_RDONLY);
    if (fd_read == -1) {
        perror("Error opening fifo1 for reading");
        return 1;
    }

    read(fd_read, buffer, sizeof(buffer));
    printf("Program B: Received from Program A: %s\n", buffer);

    fd_write = open(fifo2, O_WRONLY);
    if (fd_write == -1) {
        perror("Error opening fifo2 for writing");
        return 1;
    }

    write(fd_write, message, strlen(message) + 1);
    printf("Program B: Sent to Program A: %s\n", message);

    close(fd_read);
    close(fd_write);

    return 0;
}

/*
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/handsOnLab2/lab21$ ./21b
Program B: Received from Program A: Hello from Program A!
Program B: Sent to Program A: Hello from Program B!
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/handsOnLab2/lab21$  
*/

