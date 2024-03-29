import com.MAVLink.Demo_heart.msg_sysinfo;
import com.MAVLink.MAVLinkPacket;
import com.MAVLink.Messages.MAVLinkMessage;

public class SendMav {

    public void sendSysinfoMsg() {
        msg_sysinfo sysinfo = new msg_sysinfo();
        sysinfo.sysState = 1;
        sysinfo.voltageBattery = 85;
        sendMavLinkMsg(sysinfo);
    }

    private void sendMavLinkMsg(MAVLinkMessage msg) {
        MAVLinkPacket packet = msg.pack();
        byte[] bytes = packet.encodePacket();
        // TODO:  组帧命令集发送byte数据即可
    }
}
