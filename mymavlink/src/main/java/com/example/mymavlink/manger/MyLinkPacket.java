package com.example.mymavlink.manger;

import com.example.mymavlink.msssage.MyLinkPayload;

import java.io.Serializable;

public class MyLinkPacket implements Serializable {
    private static final long serialVersionUID = 2095947771227815314L;
    public static final int MAVLINK_STX = 0xFD; // 253
    public static final int HEADER_LEN = 12;
    public final int len;
    public int seq;
    public int sysid;
    public int destId;
    public int srcId;
    public int compid;
    public int msgid;
    public MyLinkPayload payload;
    public CRC crc;
    public int incompatFlags;
    public int compatFlags;

    public MyLinkPacket(int payloadLength) {
        len = payloadLength;
        payload = new MyLinkPayload();
    }

    public boolean payloadIsFilled() {
        return payload.size() >= len;
    }

    public boolean generateCRC(final int payloadSize) {
        if (crc == null) {
            crc = new CRC();
        } else {
            crc.start_checksum();
        }
        crc.update_checksum(payloadSize);
        crc.update_checksum(incompatFlags);
        crc.update_checksum(compatFlags);
        crc.update_checksum(seq);
        crc.update_checksum(sysid);
        crc.update_checksum(destId);
        crc.update_checksum(srcId);
        crc.update_checksum(compid);
        crc.update_checksum(msgid);
        crc.update_checksum(msgid >>> 8);
        crc.update_checksum(msgid >>> 16);
        payload.resetIndex();

        for (int i = 0; i < payloadSize; i++) {
            crc.update_checksum(payload.getByte());
        }
        return crc.finish_checksum(msgid);
    }

    private int mavTrimPayload(final byte[] payload) {
        int length = payload.length;
        while (length > 1 && payload[length - 1] == 0) {
            length--;
        }
        return length;
    }

    public byte[] encodePacket() {
        final int bufLen;
        final int payloadSize;

        payloadSize = mavTrimPayload(payload.payload.array());
        bufLen = HEADER_LEN + payloadSize + 2;
        byte[] buffer = new byte[bufLen];
        int i = 0;
        buffer[i++] = (byte) MAVLINK_STX;
        buffer[i++] = (byte) payloadSize;
        buffer[i++] = (byte) incompatFlags;
        buffer[i++] = (byte) compatFlags;
        buffer[i++] = (byte) seq;
        buffer[i++] = (byte) sysid;
        buffer[i++] = (byte) destId;
        buffer[i++] = (byte) srcId;
        buffer[i++] = (byte) compid;
        buffer[i++] = (byte) (msgid & 0XFF);
        buffer[i++] = (byte) ((msgid >>> 8) & 0XFF);
        buffer[i++] = (byte) ((msgid >>> 16) & 0XFF);
        for (int j = 0; j < payloadSize; ++j) {
            buffer[i++] = payload.payload.get(j);
        }

        generateCRC(payloadSize);
        buffer[i++] = (byte) (crc.getLSB());
        buffer[i++] = (byte) (crc.getMSB());

        return buffer;
    }

}
