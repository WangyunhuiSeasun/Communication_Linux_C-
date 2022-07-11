#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <net/if.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <linux/can.h>
#include <linux/can/raw.h>

class CanWork
{
private:
    int s, nbytes;
    struct sockaddr_can addr;
    struct ifreq ifr;

public:
    CanWork();
    ~CanWork();

    bool CanSend(struct can_frame frame);
    struct can_frame CanRecv();
};
