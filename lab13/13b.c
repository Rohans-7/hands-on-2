/*
MT2024128
Rohan Sonawane
Write two programs: first program is waiting to catch SIGSTOP signal, the second program
will send the signal (using kill system call). Find out whether the first program is able to catch
the signal or not.
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main() {
    pid_t pid;

    printf("Enter the PID of the process to send SIGSTOP to: ");
    scanf("%d", &pid);

    if (kill(pid, SIGSTOP) == 0) {
        printf("SIGSTOP signal sent to process with PID %d\n", pid);
    } else {
        perror("Failed to send SIGSTOP signal");
        exit(1);
    }

    sleep(5);
    if (kill(pid, SIGCONT) == 0) {
        printf("SIGCONT signal sent to process with PID %d\n", pid);
    } else {
        perror("Failed to send SIGCONT signal");
        exit(1);
    }

    return 0;
}

/*
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/handsOnLab2/lab13$ gcc 13b.c
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/handsOnLab2/lab13$ ./a.out
Enter the PID of the process to send SIGSTOP to: 6651
SIGSTOP signal sent to process with PID 6651
SIGCONT signal sent to process with PID 6651
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/handsOnLab2/lab13$  

*/

