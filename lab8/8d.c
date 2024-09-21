// Question : Write a separate program using signal system call to catch `SIGALRM` (use `alarm` system call)

#include <signal.h> 
#include <unistd.h>
#include <stdio.h>  

void callback()
{
    printf("Signal SIGALRM has been caught!\n");
    _exit(0);
}

void main()
{
    __sighandler_t signalStatus;

    alarm(1);

    signalStatus = signal(SIGALRM, (void *)callback);
    if (signalStatus == SIG_ERR)
        perror("Error while catching signal!");
    else
        while (1);
}

/*
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/handsOnLab2/lab8$ ./a.out
Signal SIGALRM has been caught!
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/handsOnLab2/lab8$ 
*/
