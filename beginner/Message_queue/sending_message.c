#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <stdio.h>

int main()
{
        mqd_t mq_create , mq_snd_open;
        int mq_ret;
        long int len;
        char buf[8192];

        mq_snd_open = mq_open("/mymq",O_WRONLY);

        printf("enter a message :\n");
        scanf("%[^\n]",buf);
        len = strlen(buf);

        mq_ret = mq_send(mq_snd_open , buf , len+1 , 0);

        if(mq_ret == 0)
        {
                printf("message is sent successfully\n");
        }
        else
        {
                printf("message is not sent\n");
        }
}
