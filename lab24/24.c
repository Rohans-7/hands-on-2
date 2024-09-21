/*
MT2024128
Rohan Sonawane
Write a program to create a message queue and print the key and message queue id.
*/

#include <sys/types.h>
#include <sys/ipc.h>  
#include <sys/msg.h> 
#include <stdio.h>  
#include <unistd.h>  
#include <errno.h> 

void main()
{
    key_t queueKey;      // IPC (Message Queue) key
    int queueIdentifier; // IPC (Message Queue) identifier

    queueKey = ftok(".", 1);

    if (queueKey == -1)
    {
        perror("Error while computing key!");
        _exit(0);
    }

    queueIdentifier = msgget(queueKey, IPC_CREAT | IPC_EXCL | 0700);
    if (queueIdentifier == -1)
    {
        perror("Error while creating Message Queue!");
        _exit(0);
    }

    printf("Key: %d\n", queueKey);
    printf("Message Queue Identifier: %d\n", queueIdentifier);
}

/*
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/handsOnLab2/lab24$ ./a.out
Key: 17105940
Message Queue Identifier: 0
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/handsOnLab2/lab24$  


*/
