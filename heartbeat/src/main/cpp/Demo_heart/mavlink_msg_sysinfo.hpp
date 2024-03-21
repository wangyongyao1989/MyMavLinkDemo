// MESSAGE SysInfo support class

#pragma once

namespace mavlink {
namespace Demo_heart {
namespace msg {

/**
 * @brief SysInfo message
 *
 * System information.
 */
struct SysInfo : mavlink::Message {
    static constexpr msgid_t MSG_ID = 150;
    static constexpr size_t LENGTH = 3;
    static constexpr size_t MIN_LENGTH = 3;
    static constexpr uint8_t CRC_EXTRA = 172;
    static constexpr auto NAME = "SysInfo";


    uint8_t sysState; /*<  System state. */
    uint16_t voltageBattery; /*<  Battery voltage */


    inline std::string get_name(void) const override
    {
            return NAME;
    }

    inline Info get_message_info(void) const override
    {
            return { MSG_ID, LENGTH, MIN_LENGTH, CRC_EXTRA };
    }

    inline std::string to_yaml(void) const override
    {
        std::stringstream ss;

        ss << NAME << ":" << std::endl;
        ss << "  sysState: " << +sysState << std::endl;
        ss << "  voltageBattery: " << voltageBattery << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << voltageBattery;                // offset: 0
        map << sysState;                      // offset: 2
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> voltageBattery;                // offset: 0
        map >> sysState;                      // offset: 2
    }
};

} // namespace msg
} // namespace Demo_heart
} // namespace mavlink
