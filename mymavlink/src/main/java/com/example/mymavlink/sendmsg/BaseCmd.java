package com.example.mymavlink.sendmsg;

import com.example.mymavlink.manger.MyLinkPacket;

import java.io.Serializable;

public abstract class BaseCmd implements Serializable {
    public int sysid;
    private int desId;
    private int srcId;
    public int compid;
    public int msgid;

    public abstract MyLinkPacket pack();

}
