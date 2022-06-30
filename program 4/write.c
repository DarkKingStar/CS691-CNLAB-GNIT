// Write a programme in C to perform multiple time one-way communication b/w two independent process by using named pipe..

// saved the file as Write.c

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
    char message[1024];
    mkfifo(myfifo,0666);
    fd=open(myfifo,O_WRONLY);
    while(1)
    {
        printf("Enter some string input:");
        gets(message);
        write(fd,message,1024);
        if(strcmp(message,"exit")==0)
        break;
    }
    close(fd);
    return 0;
}
