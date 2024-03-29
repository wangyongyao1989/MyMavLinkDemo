package com.example.mymavlink;

import com.example.mymavlink.ackmsg.AckSysInfo;
import com.example.mymavlink.manger.MyLinkPacket;
import com.example.mymavlink.manger.MyParser;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.util.Arrays;

public class ReceiveThread extends Thread {
    private static final String TAG = ReceiveThread.class.getSimpleName();
    private DatagramSocket datagramSocket;
    private Byte mByte;
    private MyParser commandParser = new MyParser();
    private MyLinkPacket mavPkt = null;

    public ReceiveThread(DatagramSocket datagramSocket) {
        this.datagramSocket = datagramSocket;
    }


    @Override
    public void run() {
        if (datagramSocket == null) {
            return;
        }

        byte[] buffer = new byte[512];
        DatagramPacket pack = new DatagramPacket(buffer, buffer.length);

        while (!Thread.interrupted()) {
            try {
                datagramSocket.receive(pack);
                if (pack == null || pack.getLength() < 1) {
                    return;
                }

                byte[] res = Arrays.copyOf(buffer, pack.getLength());
                for (int i = 0; i < pack.getLength(); i++) {
                    mByte = buffer[i];
                    mavPkt = commandParser.mavlink_parse_char(mByte & 0xff);
                    if (mavPkt != null && mavPkt.len > 0) {
                        // TODO:或可通过srcId/desId/compid都可分流分类信息
//                        switch (mavPkt.srcId) {
//
//                        }

                        // TODO:  通过msgID来分流分类信息
                        switch (mavPkt.msgid) {
                            case AckSysInfo.MAVLINK_MSG_ID_SysInfo: {
                                AckSysInfo ackSysInfo = new AckSysInfo(mavPkt);
                            }
                            break;
                        }

                    }
                }

            } catch (IOException e) {

            }
        }
    }

}
