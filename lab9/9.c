/*
MT2024128
Rohan Sonawane
 Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal - Use signal system call.
*/
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main() {
    printf("Ignoring SIGINT for 5 seconds. Try pressing Ctrl+C...\n");
    signal(SIGINT, SIG_IGN);

    sleep(5);

    printf("Restoring default action for SIGINT. Try pressing Ctrl+C again...\n");
    signal(SIGINT, SIG_DFL);
    sleep(10);

    printf("Program exit.\n");

    return 0;
}

/*
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/handsOnLab2/lab9$ ./a.out
Ignoring SIGINT for 5 seconds. Try pressing Ctrl+C...
^CRestoring default action for SIGINT. Try pressing Ctrl+C again...
^C
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/handsOnLab2/lab9$ 

*/
