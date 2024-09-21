/*
MT2024128
Rohan Sonawane
Write a program to create a shared memory.
a.write some data to the shared memory
b.attach with O_RDONLY and check whether you are able to overwrite.c.detach the shared memory
d.remove the shared memory
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
void main()
{
    key_t key = ftok(".", 2);
    int shmid = shmget(key, 1024, IPC_CREAT | 0744);
    char *data;
    data = shmat(shmid, (void *)0, 0);
    printf("write in shared memory\n");
    scanf("%[^\n]", data);

    printf("data from shared memory : %s\n", data);
}

/*
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/handsOnLab2/lab30$ ./a.out
write in shared memory
Rohan
data from shared memory : Rohan
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/handsOnLab2/lab30$
*/
