#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
void main()
{
    int fd[2];
    char buff[16];
    char * message = "Welcome to gnit";
    if(pipe(fd) == -1)
    {
        perror("Pipe Creating Failed!");
        exit(0);
    }
    write(fd[1],message,16);
    read(fd[0],buff,16);
    printf("%s\n",buff);
}