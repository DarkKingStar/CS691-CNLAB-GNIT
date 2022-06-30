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
    char buff[1024];
    char * myfifo= "fifo";
    mkfifo(myfifo,0666);
    fd = open(myfifo, O_RDONLY);
    while(1){
        read(fd,buff,1024);
        printf("Reader received String: \t%s\n",buff);
        if(strcmp(buff,"exit")==0)break;
    }
    close(fd);
}