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
    int fd_write, fd_read;
    char *fifo1 = "fifo1";
    char *fifo2 = "fifo2";
    char message[] = "Hello from Program A!";
    char buffer[100];

    fd_write = open(fifo1, O_WRONLY);
    if (fd_write == -1) {
        perror("Error opening fifo1 for writing");
        return 1;
    }

    write(fd_write, message, strlen(message) + 1);
    printf("Program A: Sent to Program B: %s\n", message);

    fd_read = open(fifo2, O_RDONLY);
    if (fd_read == -1) {
        perror("Error opening fifo2 for reading");
        return 1;
    }

    read(fd_read, buffer, sizeof(buffer));
    printf("Program A: Received from Program B: %s\n", buffer);

    close(fd_write);
    close(fd_read);

    return 0;
}

/*
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/handsOnLab2/lab21$ ./21a
Program A: Sent to Program B: Hello from Program A!
Program A: Received from Program B: Hello from Program B!
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/handsOnLab2/lab21$  
*/

