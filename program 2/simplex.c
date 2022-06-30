#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

void main()
{
    int pid=0;
    int fd[2];
    char buff[1024];
    char message[1024];
    if(pipe(fd) == -1)
    {
        perror("pipe creating failed");
        exit(0);
    }
    pid = fork();
    if(pid>0)
    {
        close(fd[0]);
        while(1)
        {
            gets(message);
            write(fd[1],message,1024);
            if(strcmp(message, "exit")==0)break;
        }
    }
    else
    {
        close(fd[1]);
        while(1)
        {
            read(fd[0],buff,1024);
            printf("%s\n",buff);
            if(strcmp(buff,"exit")==0)break;
        }
    }
}