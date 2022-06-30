#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#define PORT 8080

void main()
{
	int clnsock_fd;
	char message[1024],buff[1024];
	struct sockaddr_in svraddr;
	socklen_t addrlen=sizeof(struct sockaddr_in);
	clnsock_fd=socket(AF_INET,SOCK_STREAM,0);
	memset(&svraddr,0,sizeof(struct sockaddr_in));
	svraddr.sin_family=AF_INET;
	svraddr.sin_addr.s_addr=inet_addr("127.0.0.1");
	svraddr.sin_port=htons(PORT);
	connect(clnsock_fd,(struct sockaddr *)&svraddr,addrlen);
	while(1)
	{
		printf("Enter a message for server:");
		gets(message);
		send(clnsock_fd,message,strlen(message),0);
		memset(buff,0,1024);
		read(clnsock_fd,buff,1024);
		printf("Received message from server:%s\n",buff);
		if(strcmp(buff,"OK")==0)break;
	}
}
