/*
    MT2024128
    Rohan Sonawane
    Create a FIFO file by
    a.mknod command
    b.mkfifo command
    c.use strace command to find out,which command(mknod or mkfifo) is better.
    c.mknod system call
    d.mkfifo library function
*/
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    if (mknod("my_fifo", S_IFIFO | 0666, 0) == -1) {
        perror("mknod failed");
        return 1;
    }
    
    printf("FIFO 'my_fifo' created using mknod.\n");
    return 0;
}

/*
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/handsOnLab2/lab19$ gcc 19d.c
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/handsOnLab2/lab19$ ./a.out
FIFO 'my_fifo' created using mknod.
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/handsOnLab2/lab19$  
*/
