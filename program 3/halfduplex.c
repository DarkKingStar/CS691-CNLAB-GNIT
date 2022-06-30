#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

void main()
{
    int fd1[2],fd2[2];
    char message[1024],buff[1024];
    int pid=0;
    if(pipe(fd1)== -1)
    {
        perror("Pipe 1 creating failed");
        exit(0);
    }
    if(pipe(fd2)== -1)
    {
        perror("Pipe 2 creating failed");
        exit(0);
    }
    pid = fork();
    if(pid>0){
        close(fd1[0]);
        close(fd2[1]);
        while(1)
        {
            printf("parent asking for input string : \n");
            gets(message);
            write(fd1[1],message,1024);
            if(strcmp(message,"exit")==0)break;
            read(fd2[0],buff,1024);
            printf("Received from child: %s\n\n",buff);
            if(strcmp(buff,"exit")==0)break;
        }
    }
    else
    {
        close(fd1[1]);
        close(fd2[0]);
        while(1)
        {
            read(fd1[0],buff,1024);
            printf("Received from parent: %s\n\n",buff);
            if(strcmp(buff,"exit")==0)break;
            printf("child asking for input string : \n");
            gets(message);
            write(fd2[1],message,1024);
            if(strcmp(message,"exit")==0)break;
        }
    }
}