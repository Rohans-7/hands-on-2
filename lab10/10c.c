#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void handleSigfpe(int sig) {
    printf("Caught SIGFPE (Floating Point Exception)\n");
    exit(1);
}

int main() {
    struct sigaction sa;
    sa.sa_handler = handleSigfpe;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGFPE, &sa, NULL);

    int b=0;

    int x =10/b;

    return 0;
}

/*
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/handsOnLab2/lab10$ ./a.out
Caught SIGFPE (Floating Point Exception)
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/handsOnLab2/lab10$ 

*/

