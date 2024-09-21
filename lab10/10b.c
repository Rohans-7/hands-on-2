#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handleSigint(int sig) {
    printf("Caught SIGINT (Ctrl+C)\n");
}

int main() {
    struct sigaction sa;

    sa.sa_handler = handleSigint;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGINT, &sa, NULL);

    printf("Waiting for (Ctrl+C). Press Ctrl+C to trigger the signal.\n");
    while (1) {
        pause();
    }

    return 0;
}

/*
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/handsOnLab2/lab10$ ./a.out
Waiting for (Ctrl+C). Press Ctrl+C to trigger the signal.
^CCaught SIGINT (Ctrl+C)
^CCaught SIGINT (Ctrl+C)
^CCaught SIGINT (Ctrl+C)
^CCaught SIGINT (Ctrl+C)
^Z
[1]+  Stopped                 ./a.out
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/handsOnLab2/lab10$ 

*/

