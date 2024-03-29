package com.example.mymavlink.sendmsg;

import com.example.mymavlink.manger.MyLinkPacket;

public class CmdSysInfo extends BaseCmd {
    public static final int MAVLINK_MSG_ID_SysInfo = 150;
    public static final int MAVLINK_MSG_LENGTH = 3;
    private static final long serialVersionUID = MAVLINK_MSG_ID_SysInfo;

    public int voltageBattery;
    public short sysState;

    public CmdSysInfo(int voltageBattery, short sysState) {
        this.voltageBattery = voltageBattery;
        this.sysState = sysState;

    }


    @Override
    public String toString() {
        return "AckSysInfo{" +
                "voltageBattery=" + voltageBattery +
                ", sysState=" + sysState +
                '}';
    }

    @Override
    public MyLinkPacket pack() {
        MyLinkPacket myLinkPacket = new MyLinkPacket(MAVLINK_MSG_LENGTH);
        //设置帧头的sysid、destId、srcId、compid、msgid
        myLinkPacket.sysid = 1;
        myLinkPacket.destId = 2;
        myLinkPacket.srcId = 3;
        myLinkPacket.compid = 3;
        myLinkPacket.msgid = 3;
        //添加命令playload实际的值
        myLinkPacket.payload.putUnsignedShort(voltageBattery);
        myLinkPacket.payload.putUnsignedByte(sysState);
        return null;
    }
}
