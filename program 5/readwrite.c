#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
void main() {
    int fd;
    char *myfifo="fifo";
    char buff[1024],message[1024];
    mkfifo(myfifo,0666);
    while(1)
    {
        fd=open(myfifo,O_RDONLY);
        read(fd,buff,1024);
        printf("Received data from write: %s\n",buff);
        if(strcmp(buff,"exit")==0)
            break;
        close(fd);
        fd=open(myfifo,O_WRONLY);
        printf("Enter some string input: ");
        gets(message);
        write(fd,message,1024);
        if(strcmp(message,"exit")==0)
        break;
        close(fd);
    }
}