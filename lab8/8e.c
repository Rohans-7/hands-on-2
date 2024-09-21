#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

void handleAlarm(int sig) {
    printf("Caught SIGALRM signal: %d\n", sig);
}

int main() {
    signal(SIGALRM, handleAlarm);

    struct itimerval timer;
 
    timer.it_value.tv_sec = 2;
    timer.it_value.tv_usec = 0;

    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 0;

    if (setitimer(ITIMER_REAL, &timer, NULL) == -1) {
        perror("settimer");
        return 1;
    }

    printf("Waiting for SIGALRM to execute,\n");
    pause();

    return 0;
}

/*
ohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/handsOnLab2/lab8$ ./a.out
Waiting for SIGALRM to execute,
Caught SIGALRM signal: 14
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/handsOnLab2/lab8$ 


*/
