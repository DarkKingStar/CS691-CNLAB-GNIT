#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#define PORT 8080

void main()
{
	int svrsock_fd,new_conn;
	char message[1024],buff[1024];
	int opt=1;
	struct sockaddr_in address;
	socklen_t addrlen=sizeof(struct sockaddr_in);
	svrsock_fd=socket(AF_INET,SOCK_STREAM,0);
	address.sin_family=AF_INET;
	address.sin_addr.s_addr=INADDR_ANY;
	address.sin_port=htons(PORT);
	setsockopt(svrsock_fd,SOL_SOCKET,SO_REUSEADDR|SO_REUSEPORT,&opt,sizeof(opt));
	bind(svrsock_fd,(struct sockaddr *)&address,addrlen);
	listen(svrsock_fd,3);
	printf("Waiting for client\n");
	new_conn=accept(svrsock_fd,(struct sockaddr*)&address,&addrlen);

	while(1)
	{
		memset(buff,0,1024);
		read(new_conn,buff,1024);
		printf("Received message from client:%s\n",buff);
		if(strcmp(buff,"end")==0)
		{
			send(new_conn,"OK",3,0);
			break;
		}
		printf("Enter message for client:");
		gets(message);
		send(new_conn,message,strlen(message),0);
	}
}
