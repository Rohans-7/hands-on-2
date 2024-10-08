/*
    MT2024128
    Rohan Sonawane
    Write a separate program (for each time domain) to set a interval timer in 10sec and
    10micro second
    a. ITIMER_REAL
    b. ITIMER_VIRTUAL
    c. ITIMER_PROF
*/
#include <sys/time.h>
#include <signal.h> 
#include <unistd.h>  
#include <stdio.h>   

void main(int argc, char *argv[])
{
    int timerStatus;

    struct itimerval timer;

    if (argc != 2)
    {
        printf("Pass 1 for 10s timer or 2 for 10ms timer\n");
        _exit(0);
    }

    if ((int)(*argv[1] - 48) == 1)
    {
        timer.it_interval.tv_sec = 0;
        timer.it_interval.tv_usec = 0;
        timer.it_value.tv_sec = 10;
        timer.it_value.tv_usec = 0;
    }
    else if ((int)(*argv[1] - 48) == 2)
    {
        timer.it_interval.tv_sec = 0;
        timer.it_interval.tv_usec = 0;
        timer.it_value.tv_sec = 0;
        timer.it_value.tv_usec = 10000;
    }

    timerStatus = setitimer(ITIMER_REAL, &timer, 0);
    if (timerStatus == -1)
        perror("Error while setting an interval timer!");

    while(1);
}

/*
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/handsOnLab2/lab1$ ./a.out
Pass 1 for 10s timer or 2 for 10ms timer
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/handsOnLab2/lab1$ ./a.out 1
Alarm clock
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/handsOnLab2/lab1$ 
*/
