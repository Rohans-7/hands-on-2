// Question : Write a simple program to print the created thread IDs.
/*
MT2024128
Rohan Sonawane
Write a simple program to print the created thread ids.

*/

#include <pthread.h> 
#include <stdio.h>  

void sampleFunction()
{
    printf("Running in thread with thread ID: %lu\n", pthread_self());
}

void main()
{
    pthread_t threadID;
    if(pthread_create(&threadID, NULL, (void *)sampleFunction, NULL))
        perror("Error while creating thread");

    pthread_exit(NULL);
}

/*

rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/handsOnLab2/lab7$ gcc 7.c
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/handsOnLab2/lab7$ ./a.out
Running in thread with thread ID: 140459284362944
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/handsOnLab2/lab7$ 

*/
