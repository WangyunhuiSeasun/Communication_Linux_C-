#include <CanWork.h>

CanWork::CanWork(/* args */)
{
    s = socket(PF_CAN, SOCK_RAW, CAN_RAW);  //创建套接字
    strcpy(ifr.ifr_name, "can0");
    ioctl(s, SIOCGIFINDEX, &ifr);           //指定 can0 设备
    addr.can_family = AF_CAN;
    addr.can_ifindex = ifr.ifr_ifindex;
    bind(s, (struct sockaddr *)&addr, sizeof(addr));    //将套接字与 can0 绑定
}

CanWork::~CanWork()
{
    close(s);
}

bool CanWork::CanSend(struct can_frame frame)
{
    nbytes = write(s, &frame, sizeof(frame));   //发送 frame[0]
    if (nbytes != sizeof(frame))
    {
        printf("Send Error frame\n!");
        return false; //发送错误，退出
    }
    return true;
}

struct can_frame CanWork::CanRecv()
{

    struct can_frame frame;
    nbytes = read(s, &frame, sizeof(frame));    //接收报文
                                                //显示报文
    if (nbytes > 0)
    {
        printf("ID=0x%x DLC=%d data[0]=0x%x\n", frame.can_id,
               frame.can_dlc, frame.data[0]);
    }
    return frame;
}
