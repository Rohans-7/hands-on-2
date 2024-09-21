/*
MT2024128
Rohan Sonawane
Write a program to communicate between two machines using socket.
*/

#include <sys/types.h>  
#include <sys/socket.h> 
#include <netinet/ip.h> 
#include <stdio.h>      
#include <unistd.h>     
void main()
{
    int socktd=socket(AF_INET,SOCK_STREAM,0);
    if(socktd==-1){
        perror("Erroe when creating socket");
    }
    printf("Socket created\n");

    struct sockaddr_in address;
    address.sin_addr.s_addr=htonl(INADDR_ANY);
    address.sin_family=AF_INET;
    address.sin_port=htons(8080);

    int connectionS = connect(socktd, (struct sockaddr *)&address, sizeof(address));

    if(connectionS==-1){
        perror("Error while establishing Connection");
    }
    
    printf("Connection with server established");

    char buf[100];
    read(socktd,buf,100);
    printf("Data from server: %s\n",buf);

    printf("Write massage for server: ");
    scanf("%[^\n]",buf);

    write(socktd,buf,sizeof(buf));
    printf("Data sent to server");

    close(socktd);
}
/*
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/handsOnLab2/lab33$ ./33c
Socket created
Connection with server establishedData from server: Hi Server here
Write massage for server: Hi client this side
Data sent to serverrohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/handsOnLab2/lab33$  
*/
