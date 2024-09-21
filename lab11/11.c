/*
MT2024128
Rohan Sonawane
Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal -
use sigaction system call.
*/
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void reset_sigint(int signum) {
    printf("Resetting SIGINT to default action.\n");

    struct sigaction sa_default;
    sa_default.sa_handler = SIG_DFL;
    sigemptyset(&sa_default.sa_mask);
    sa_default.sa_flags = 0;
    sigaction(SIGINT, &sa_default, NULL);
}

int main() {
    struct sigaction sa_ignore, sa_reset;

    printf("Ignoring SIGINT for 5 seconds. Try pressing Ctrl+C...\n");
    sa_ignore.sa_handler = SIG_IGN;
    sigemptyset(&sa_ignore.sa_mask);
    sa_ignore.sa_flags = 0;
    sigaction(SIGINT, &sa_ignore, NULL);

    sleep(5);

    sa_reset.sa_handler = reset_sigint;
    sigemptyset(&sa_reset.sa_mask);
    sa_reset.sa_flags = 0;
    sigaction(SIGINT, &sa_reset, NULL);

    printf("Press Ctrl+C to reset SIGINT to default action. After reset, press Ctrl+C again to terminate.\n");

    while (1) {
        pause();
    }

    return 0;
}

/*
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/handsOnLab2/lab11$ ./a.out
Ignoring SIGINT for 5 seconds. Try pressing Ctrl+C...
^CPress Ctrl+C to reset SIGINT to default action. After reset, press Ctrl+C again to terminate.
^CResetting SIGINT to default action.
^C
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/handsOnLab2/lab11$ 
*/

