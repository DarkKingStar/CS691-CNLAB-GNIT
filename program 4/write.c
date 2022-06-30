#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<string.h>
#include<stdlib.h>

void main()
{
    int fd;
    char message[1024];
    char * myfifo= "fifo";
    mkfifo(myfifo,0666);
    fd = open(myfifo, O_WRONLY);
    while(1){
        printf("Writer asking for input String: \n");
        gets(message);
        write(fd,message,1024);
        if(strcmp(message,"exit")==0)break;
    }
    close(fd);
}