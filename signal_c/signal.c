#include<sys/types.h>
#include<signal.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc,char **argv)
{
    pid_t pid;
    int i=0;
    pid=fork();
    if(pid<0)
            perror("fork");
    else if(pid==0)
    {
        while(1)
        {
            printf("I am son\n");
            sleep(1);
        }
    }
    else{
        while(1){
            printf("I am father\n");
            sleep(1);
            ++i;
            if(3==i)
            {
                kill(pid,SIGINT);//给子进程pid 发送中断信号SIGINT
            }
        }
    }
    return 0;
}
