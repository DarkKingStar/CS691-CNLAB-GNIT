#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#define PORT 8080
void main()
{
	int svrsock_fd;
	char message[1024], buff[1024];
	struct sockaddr_in svraddr, clnaddr;
	socklen_t svraddrlen = sizeof(struct sockaddr_in);
	socklen_t clnaddrlen = sizeof(struct sockaddr_in);
	svrsock_fd = socket(AF_INET, SOCK_DGRAM, 0);
	
	svraddr.sin_family = AF_INET;
	svraddr.sin_addr.s_addr = INADDR_ANY;
	svraddr.sin_port = htons(PORT);
	bind(svrsock_fd,(struct sockaddr *)&svraddr,svraddrlen);
	while(1)
	{
		printf("Enter input string for server : ");
		gets(message);
		sendto(svrsock_fd,message,sizeof(message),0,(struct sockaddr *)&clnaddr,clnaddrlen);
		if(strcmp(message,"exit")==0) break;
		printf("Waiting for server : \n");
		recvfrom(svrsock_fd,buff,sizeof(buff),MSG_WAITALL,(struct sockaddr *)&clnaddr,&clnaddrlen);
		printf("Received data from server : %s\n",buff);
		if(strcmp(buff,"exit")==0) break;
		
	}
}
