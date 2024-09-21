/*
MT2024128
Rohan Sonawane
Write a program to find out time taken to execute getpid system call. Use time stamp counter.
*/
#include <stdio.h>
#include<unistd.h>

unsigned long long rdtsc() {
    unsigned int lo, hi;

    __asm__ volatile ("rdtsc" : "=a" (lo), "=d" (hi));
    return ((unsigned long long)hi << 32) | lo;
}

int main() {
    unsigned long long start, end;
    pid_t pid;

    start = rdtsc();
   
    for (int i = 0; i < 100; i++){
	    pid=getppid();
    }

    end = rdtsc();
    
    printf("Clock cycles: %llu\n", end - start);

    return 0;
}

/*
 *
 *rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/handsOnLab2/lab4$ ./a.out
Clock cycles: 42732
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/handsOnLab2/lab4$ 
*/
