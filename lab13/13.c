/*
MT2024128
Rohan Sonawane
Write two programs: first program is waiting to catch SIGSTOP signal, the second program
will send the signal (using kill system call). Find out whether the first program is able to catch
the signal or not.
*/
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handle_signal(int sig) {
    if (sig == SIGINT) {
        printf("Caught SIGINT signal.\n");
    }
    else if (sig == SIGCONT) {
        printf("Caught SIGCONT signal. Resuming process...\n");
    }
}

int main() {
    struct sigaction sa;
    sa.sa_handler = handle_signal;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    sigaction(SIGINT, &sa, NULL);
    sigaction(SIGCONT, &sa, NULL);

    printf("Process is waiting for signals. PID: %d\n", getpid());

    while (1) {
        pause();
    }

    return 0;
}

/*
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/handsOnLab2/lab13$ ./a.out
Process is waiting for signals. PID: 6651

[1]+  Stopped                 ./a.out
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/handsOnLab2/lab13$ Caught SIGCONT signal. Resuming process...

*/

