/*
============================================================================
Name : 34b_server.c
Author : Raj Kanani
Roll No : MT2024074
Description : Write a program to create a concurrent server.
              a. use fork
              b. use pthread_create
============================================================================
*/
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/ip.h>
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>

void threadHandler(int *fd)
{
    int readBytes, writeBytes;
    char dataFromClient[1024] = {'\0'};

    writeBytes = write(*fd, "Hello from Server Program\n", 27);
    if (writeBytes == -1)
        printf("Error while writing to network via socket!\n");
    else
        printf("Data sent to client!\n");

    readBytes = read(*fd, dataFromClient, 1024);
    if (readBytes == -1)
        printf("Error while reading from network via socket!\n");
    else
        printf("Data from client: %s\n", dataFromClient);

    close(*fd);
}

int main()
{
    int socketFileDescriptor, connectionFileDescriptor;
    int bindStatus;
    int listenStatus;
    int clientSize;
    pthread_t threadID;

    struct sockaddr_in address, client;

    int readBytes, writeBytes;
    char dataFromClient[1024] = {'\0'};

    socketFileDescriptor = socket(AF_INET, SOCK_STREAM, 0);
    if (socketFileDescriptor == -1)
    {
        printf("Error while creating socket!\n");
        exit(0);
    }
    printf("Server side socket successfully created!\n");

    address.sin_addr.s_addr = htonl(INADDR_ANY);
    address.sin_family = AF_INET;
    address.sin_port = htons(8080);

    bindStatus = bind(socketFileDescriptor, (struct sockaddr *)&address, sizeof(address));
    if (bindStatus == -1)
    {
        printf("Error while binding name to socket!\n");
        exit(0);
    }
    printf("Binding to socket was successful!\n");

    listenStatus = listen(socketFileDescriptor, 2);
    if (listenStatus == -1)
    {
        printf("Error while trying to listen for connections!\n");
        exit(0);
    }
    printf("Now listening for connections on a socket!\n");

    while (1)
    {
        clientSize = (int)sizeof(client);
        connectionFileDescriptor = accept(socketFileDescriptor, (struct sockaddr *)&client, &clientSize);
        if (connectionFileDescriptor == -1)
            printf("Error while accepting a connection!\n");
        else
        {
            clientSize = (int)sizeof(client);
            connectionFileDescriptor = accept(socketFileDescriptor, (struct sockaddr *)&client, &clientSize);

            if (connectionFileDescriptor == -1)
                printf("Error while accepting a connection!\n");
            else
            {   
                if (pthread_create(&threadID, NULL, (void *)threadHandler, &connectionFileDescriptor))
                    printf("Error while creating thread\n");
            }
        }
    }

    close(socketFileDescriptor);

    return 0;
}
/*  Output :
    kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Hands_On-List_II/Practical_34$ gcc -o 34b_server 34b_server.c
    kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Hands_On-List_II/Practical_34$ ./34b_server
    Server side socket successfully created!
    Binding to socket was successful!
    Now listening for connections on a socket!
    Data sent to client!
    Data from client: Hello from client

*/