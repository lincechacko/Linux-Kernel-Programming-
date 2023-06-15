#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <stdio.h>
int main()
{
        mqd_t mq_create;
        int mq_ret , i;
        i=-1;
        struct mq_attr attr;
        attr.mq_flags=0;
        attr.mq_maxmsg=10;
        attr.mq_msgsize = 8192;
        attr.mq_curmsgs = 0;

        mq_create = mq_open("/mymq",O_CREAT|O_RDWR , 0744 , &attr);

        if(mq_create == 3)
        {
                printf("success");
        }
       else
       {
         printf("failure");
       }
}
