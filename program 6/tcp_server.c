#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#define PORT 8080
void main(){
    int svrsock_fd,new_conn;
    char message[1024],buff[1024];
    int opt=1;
    struct sockaddr_in svraddr;
    socklen_t addrlen=sizeof(struct sockaddr_in);
    svrsock_fd=socket(AF_INET,sock_STREAM,0);
    setsockopt(svrsock_fd,SOL_SOCKET,SO_REUSEADDR|SO_REUSEPORT,&opt,sizeof(opt));
    svraddr.sin_family=AF_INET;
    svraddr.sin_addr.s_addr=INADDR_ANY;
    svraddr.sin_port=htons(PORT);
    
    bind(svrsock_fd,(struct sockaddr *)& address,addrlen);
    listen(svrsock_fd,3);
    printf("Waiting for Client\n");
    new_conn=accept(svrsock_fd,(struct sockaddr *)& address,&addrlen);
    while(1){
        read(new_conn,buff,1024);
        printf("Received message for client:%s\n",buff);
        if(strcmp(buff,"exit")==0)break;
        printf("enter string for client:");
        gets(message);
        send(new_conn,message,sizeof(message),0);
        if(strcmp(message,"exit")==0)break;
    }
}