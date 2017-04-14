#include<sys/time.h>
#include<sys/types.h>
#include<sys/select.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

int main()
{
    fd_set readfds;
    FD_ZERO(&readfds);
    FD_SET(STDIN_FILENO,&readfds);
    int ret;
    char buf[256]={0};
    struct timeval tv={5,1000};
    ret=select(STDIN_FILENO+1,&readfds,NULL,NULL,&tv);
    printf("ret=%d\n",ret);
    if(-1==ret)
    {
        perror("select error");
        exit(EXIT_FAILURE);
    }
    else if(ret)
    {
        if(FD_ISSET(STDIN_FILENO,&readfds))
            read(STDIN_FILENO,buf,256);
        printf("read from stdin msg:%s\n",buf);
    }
    else
        printf("timeout\n");
    return 0;
}
