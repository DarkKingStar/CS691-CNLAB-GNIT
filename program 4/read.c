// Write a programme in C to perform multiple time one-way communication b/w two independent process by using named pipe..

// saved the file as Read.c

#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main()
{
    int fd;
    char *myfifo="fifo";
    char buff[1024];
    mkfifo(myfifo,0666);
    fd=open(myfifo,O_RDONLY);
    while(1)
    {
        read(fd,buff,1024);
        printf("Received Data:%s\n",buff);
        if(strcmp(buff,"exit")==0)
        break;
    }
    close(fd);
    return 0;
}
