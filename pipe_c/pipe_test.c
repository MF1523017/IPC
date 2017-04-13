#include<unistd.h>
#include<stdio.h>
#include<string.h>

int main()
{
    int _pipe[2];//0:read pipe   1:write pipe
    int ret=pipe(_pipe);
    if(ret==-1)
            printf("create pipe error\n");
    pid_t id=fork();
    if(id<0)
            printf("fock error\n");
    else if(id==0)//child
    {
        close(_pipe[0]);
        int i=0;
        char *_msg=NULL;
        while(i<100)
        {
                _msg="I am a coder";
                write(_pipe[1],_msg,strlen(_msg)+1);
                usleep(1000);
                ++i;
        }
    }
    else {//father
        close(_pipe[1]);
        char _msg[100];
        int j=0;
        while(j<100)
        {
            memset(_msg,'\0',sizeof(_msg));
            read(_pipe[0],_msg,sizeof(_msg));
            printf("%s\n",_msg);
            ++j;
        }
    }
    return 0;
}
