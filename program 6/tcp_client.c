#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#define PORT 8080
void main() {
    int clnsock_fd;
    char message[1024],buff[1024];
    int opt=1;
    struct sockaddr_in svraddr;
    socklen_t addrlen=sizeof(struct sockaddr_in);
    clnsock_fd=socket(AF_INET,SOCK_STREAM,0);
    svraddr.sin_family=AF_INET;
    svraddr.sin_addr.s_addr=inet_addr("127.0.0.1");
    svraddr.sin_port=htons(PORT);
    connect(clnsock_fd,(struct sockaddr *)&svraddr,addrlen);
    while(1)
    {
        printf("Enter message for server: ");
        gets(message);
        send(clnsock_fd,message,sizeof(message),0);
        if(strcmp(message,"exit")==0)break;
        read(clnsock_fd,buff,1024);
        printf("received from server: %s\n",buff);
        if(strcmp(buff,"exit")==0)break;
    }
}