package com.example.mymavlink.ackmsg;

import com.example.mymavlink.manger.MyLinkPacket;

public class AckSysInfo extends BaseAckMsg {
    public static final int MAVLINK_MSG_ID_SysInfo = 150;
    public static final int DEST_ID_SysInfo = 3;
    public static final int SRC_ID_SysInfo = 2;


    public static final int MAVLINK_MSG_LENGTH = 3;
    private static final long serialVersionUID = MAVLINK_MSG_ID_SysInfo;

    public int voltageBattery;
    public short sysState;

    public AckSysInfo() {
    }

    public AckSysInfo(MyLinkPacket myLinkPacket) {
        this.sysid = myLinkPacket.sysid;
        desId = myLinkPacket.destId;
        srcId = myLinkPacket.srcId;
        this.compid = myLinkPacket.compid;
        this.msgid = MAVLINK_MSG_ID_SysInfo;
        unpack(myLinkPacket);
    }


    //解析出payload包含的实体数值
    private void unpack(MyLinkPacket myLinkPacket) {
        super.decrypt(myLinkPacket);
        sysState = myLinkPacket.payload.getShort();
        voltageBattery = myLinkPacket.payload.getInt();
    }


    @Override
    public String toString() {
        return "AckSysInfo{" +
                "voltageBattery=" + voltageBattery +
                ", sysState=" + sysState +
                '}';
    }

}
