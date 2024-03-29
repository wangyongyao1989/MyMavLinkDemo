package com.example.mymavlink;


import com.example.mymavlink.ackmsg.AckSysInfo;
import com.example.mymavlink.manger.MyLinkPacket;
import com.example.mymavlink.sendmsg.BaseCmd;
import com.example.mymavlink.sendmsg.CmdSysInfo;

public class SendMav {

    public void sendSysinfoMsg() {
        CmdSysInfo ackSysInfo = new CmdSysInfo(100,(short) 5);
        sendMavLinkMsg(ackSysInfo);
    }

    private void sendMavLinkMsg(BaseCmd msg) {
        MyLinkPacket packet = msg.pack();
        byte[] bytes = packet.encodePacket();
        // TODO:  组帧命令集发送byte数据即可
    }
}
