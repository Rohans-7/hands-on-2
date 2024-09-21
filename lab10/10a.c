/*
MT2024128
Rohan Sonawane
Write a separate program using sigaction system call to catch the following signals.
a. SIGSEGV
b. SIGINT
c. SIGFPE
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void handleSigsegv(int sig) {
    printf("Caught SIGSEGV (Segmentation Fault)\n");
    exit(1);
}

int main() {
    struct sigaction sa;

    // Catch SIGSEGV
    sa.sa_handler = handleSigsegv;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGSEGV, &sa, NULL);

    int *ptr = NULL;
    *ptr = 9;

    return 0;
}

/*
ohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/handsOnLab2/lab10$ ./a.out
Caught SIGSEGV (Segmentation Fault)
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/handsOnLab2/lab10$

*/

