#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

void handleSigvtalrm(int sig) {
    printf("Caught SIGVTALRM signal\n");
}

int main() {
    struct itimerval timer;
    signal(SIGVTALRM, handleSigvtalrm);

    timer.it_value.tv_sec = 2;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 2;
    timer.it_interval.tv_usec = 0;


    if (setitimer(ITIMER_VIRTUAL, &timer, NULL) == -1) {
        perror("Itimer virtual");
        exit(1);
    }

    while (1) {
    }

    return 0;
}

/*
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/handsOnLab2/lab8$ ./a.out
Caught SIGVTALRM signal
Caught SIGVTALRM signal
^C
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/handsOnLab2/lab8$ 
*/

