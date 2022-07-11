#include <CanWork.h>

int main(int argc, char *argv[])
{
    printf("Hello World \n");

    CanWork canWork;
    struct can_frame frameSend;
    struct can_frame frameRecv;
    frameSend.can_id = 0x01;
    frameSend.can_dlc = 6;
    frameSend.data[0] = 'H';
    frameSend.data[1] = 'e';
    frameSend.data[2] = 'l';
    frameSend.data[3] = 'l';
    frameSend.data[4] = 'o';
    frameSend.data[5] = '!';

    while (1)
    {
        canWork.CanSend(frameSend);
        sleep(1);
        frameRecv = canWork.CanRecv();
        sleep(1);
    }
}