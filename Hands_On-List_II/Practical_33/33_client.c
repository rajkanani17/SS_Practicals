/*
============================================================================
Name : 33_client.c
Author : Raj Kanani
Roll No : MT2024074
Description : Write a program to communicate between two machines using socket.
============================================================================
*/
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/ip.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
    int socketFileDescriptor;
    int connectStatus;

    struct sockaddr_in address;

    int readBytes, writeBytes;
    char dataFromServer[1024] = {'\0'};

    socketFileDescriptor = socket(AF_INET, SOCK_STREAM, 0);
    if (socketFileDescriptor == -1)
    {
        printf("Error while creating socket!\n");
        exit(0);
    }
    printf("Client side socket successfully created!\n");

    address.sin_addr.s_addr = htonl(INADDR_ANY);
    address.sin_family = AF_INET;
    address.sin_port = htons(8080);

    connectStatus = connect(socketFileDescriptor, (struct sockaddr *)&address, sizeof(address));
    if (connectStatus == -1)
    {
        printf("Error while connecting to server!\n");
        exit(0);
    }
    printf("Client to server connection successfully established!\n");


    readBytes = read(socketFileDescriptor, dataFromServer, 1024);
    if (readBytes == -1)
        printf("Error while reading from network via socket!\n");
    else
        printf("Data from server: %s\n", dataFromServer);

    writeBytes = write(socketFileDescriptor, "Hello from client program!\n", 27);
    if (writeBytes == -1)
        printf("Error while writing to network via socket!\n");
    else
        printf("Data sent to server!\n");

    close(socketFileDescriptor);

    return 0;
}
/*  Output :
    kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Hands_On-List_II/Practical_33$ gcc -o 33_client 33_client.c
    kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Hands_On-List_II/Practical_33$ ./33_client
    Client side socket successfully created!
    Client to server connection successfully established!
    Data from server: Hello from Server program!

    Data sent to server!

*/