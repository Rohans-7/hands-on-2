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

int main()
{
    key_t queueKey;
    int queueIdentifier;
    int messageSendStatus;

    struct msgbuf
    {
        long mtype;
        int someNumber;
    } data;

    queueKey = ftok(".", 1);

    if (queueKey == -1)
    {
        perror("Error while computing key!\n");
        _exit(0);
    }

    queueIdentifier = msgget(queueKey, IPC_CREAT | 0700);

    if (queueIdentifier == -1)
    {
        perror("Error while creating message queue!\n");
        _exit(0);
    }

    printf("Key: %d\n", queueKey);
    printf("Message Queue Identifier: %d\n\n", queueIdentifier);

    data.mtype = 1;
    data.someNumber = 100;

    messageSendStatus = msgsnd(queueIdentifier, &data, sizeof(data), 0);

    if (messageSendStatus == -1)
    {
        perror("Error while sending message via Message Queue!\n");
        _exit(0);
    }

    printf("Message sent!\n");

    return 0;
}

/*
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/handsOnLab2/lab26$ ./a.out
Message sent: Hello, this is a test message!
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/handsOnLab2/lab26$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x01050414 0          rohan-sona 700        0            0           
0x01050417 1          rohan-sona 700        0            0           
0x4105041a 2          rohan-sona 666        100          1           

*/

