/*
MT2024128
Rohan Sonawane
Write a program to wait for data to be written into FIFO within 10 seconds, use select
system call with FIFO.
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/select.h>
#include <sys/stat.h>

int main() {
    int fd;
    char *fifo = "my_fifo";
    char buffer[100];
    fd_set read_fds;
    struct timeval timeout;
    int retval;

    if (mkfifo(fifo, 0666) == -1) {
        perror("Error creating FIFO");
    }

    fd = open(fifo, O_RDONLY | O_NONBLOCK);
    if (fd == -1) {
        perror("Error opening FIFO");
        return 1;
    }

    FD_ZERO(&read_fds);
    FD_SET(fd, &read_fds);

    timeout.tv_sec = 10;
    timeout.tv_usec = 0;

    retval = select(fd + 1, &read_fds, NULL, NULL, &timeout);

    if (retval == -1) {
        perror("select() error");
    } else if (retval == 0) {
        printf("No data within 10 seconds.\n");
    } else {
        if (FD_ISSET(fd, &read_fds)) {
            int bytes_read = read(fd, buffer, sizeof(buffer) - 1);
            if (bytes_read > 0) {
                buffer[bytes_read] = '\0';
                printf("Received: %s\n", buffer);
            } else {
                printf("No data read.\n");
            }
        }
    }

    close(fd);

    return 0;
}

/*
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/handsOnLab2/lab22$ ./22_a
Received: Hello from another process!

rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/handsOnLab2/lab22$  

*/

