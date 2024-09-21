/*
MT2024128
Rohan Sonawane
Write a separate program using signal system call to catch the following signals.
    a.SIGSEGV
    b.SIGINT
    c.SIGFPE
    d.SIGALRM(use alarm system call)
    e.SIGALRM(use setitimer system call)
    f.SIGVTALRM(use setitimer system call)
    g.SIGPROF(use setitimer system call)
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void signalHandler(int sig) {
    printf("\nCaught SIGINT (Ctrl+C). Exiting gracefully...\n");
    exit(0);
}

int main() {
    signal(SIGINT,signalHandler);

    printf(" Press Ctrl+C to trigger SIGINT.\n");
    while (1) {
        printf("Infinite programm running\n");
    }

    return 0;
}

/*
Infinite programm running
Infinite programm running
Infinite programm running
^CInfinite programm running

Caught SIGINT (Ctrl+C). Exiting gracefully...
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/handsOnLab2/lab8$ 
*/

