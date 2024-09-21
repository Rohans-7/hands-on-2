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
    char *file = "./20-fifo";
    int fd = open(file, O_RDONLY); 

    while (1)
    {
        if (fd == -1)
            perror("Error");
        else
        {
            char buf;
            while (read(fd, &buf, 1) > 0)
                write(1, &buf, 1);
            write(1, "\n", 1);
        }
        close(fd);
    }
}
/*
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/handsOnLab2/lab20$ ./20b
Hi This is Rohan

*/
