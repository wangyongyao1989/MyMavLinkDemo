//
// Created by MMM on 2024/3/22.
//

#ifndef MYMAVLINKDEMO_SENDRECEIVEMAV_H
#define MYMAVLINKDEMO_SENDRECEIVEMAV_H

#include "message.hpp"

class SendReceiveMav {
public:
    void sendMavLinkMsg(mavlink::Message *msg);
};


#endif //MYMAVLINKDEMO_SENDRECEIVEMAV_H
