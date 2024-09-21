/*
MT2024128
Rohan Sonawane
Write two programs so that both can communicate by FIFO -Use one way communication.
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

void main()
{
    char *s;
    int fd;
    long int size = 100;
    char *file = "./20-fifo";
    mkfifo(file, S_IRWXU);
    while (1)
    {
        fd = open(file, O_WRONLY);
        if (fd == -1)
            perror("Error");
        else
        {
            printf("enter message:\n");
            int l = getline(&s, &size, stdin);
            write(fd, s, l);
            close(fd);
        }
    }
}
/*
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/handsOnLab2/lab20$ ./20a
enter message:
Hi This is Rohan
enter message:




*/
