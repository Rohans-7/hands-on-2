#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
    if (mkfifo("my_fifo", 0666) == -1) {
        perror("mkfifo failed");
        return 1;
    }
    
    printf("FIFO 'my_fifo' created using mkfifo.\n");
    return 0;
}

/*
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/handsOnLab2/lab19$ gcc 19e.c
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/handsOnLab2/lab19$ ./a.out
FIFO 'my_fifo' created using mkfifo.
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/handsOnLab2/lab19$  
*/

