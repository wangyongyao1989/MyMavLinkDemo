import com.MAVLink.Demo_heart.msg_sysinfo;
import com.MAVLink.MAVLinkPacket;
import com.MAVLink.Messages.MAVLinkMessage;
import com.MAVLink.Parser;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.util.Arrays;

public class UdpReceiveThread extends Thread {
    private static final String TAG = UdpReceiveThread.class.getSimpleName();
    private DatagramSocket datagramSocket;
    private Byte mByte;
    private Parser commandParser = new Parser();
    private MAVLinkPacket mavPkt = null;

    public UdpReceiveThread(DatagramSocket datagramSocket) {
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
                        MAVLinkMessage mavMessage = mavPkt.unpack();
                        if (mavMessage != null) {
                            // TODO:  通过msgID来分流分类信息
                            switch (mavMessage.msgid) {
                                case msg_sysinfo.MAVLINK_MSG_ID_SysInfo: {
                                    msg_sysinfo msgSysinfo = (msg_sysinfo) mavMessage;
                                }
                                break;
                            }

                        }
                    }
                }

            } catch (IOException e) {

            }
        }
    }

}
