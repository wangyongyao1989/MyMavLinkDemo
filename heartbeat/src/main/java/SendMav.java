import com.MAVLink.MAVLinkPacket;
import com.MAVLink.Messages.MAVLinkMessage;

public class SendMav {

    public void sendMavLinkMsg(MAVLinkMessage msg) {
        MAVLinkPacket packet = msg.pack();
        byte[] bytes = packet.encodePacket();
        // TODO:  组帧命令集发送byte数据即可
    }
}
