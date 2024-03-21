/** @file
 *	@brief MAVLink comm testsuite protocol generated from Demo_heart.xml
 *	@see http://mavlink.org
 */

#pragma once

#include <gtest/gtest.h>
#include "Demo_heart.hpp"

#ifdef TEST_INTEROP
using namespace mavlink;
#undef MAVLINK_HELPER
#include "mavlink.h"
#endif


TEST(Demo_heart, SysInfo)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::Demo_heart::msg::SysInfo packet_in{};
    packet_in.sysState = 139;
    packet_in.voltageBattery = 17235;

    mavlink::Demo_heart::msg::SysInfo packet1{};
    mavlink::Demo_heart::msg::SysInfo packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.sysState, packet2.sysState);
    EXPECT_EQ(packet1.voltageBattery, packet2.voltageBattery);
}

#ifdef TEST_INTEROP
TEST(Demo_heart_interop, SysInfo)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_sysinfo_t packet_c {
         17235, 139
    };

    mavlink::Demo_heart::msg::SysInfo packet_in{};
    packet_in.sysState = 139;
    packet_in.voltageBattery = 17235;

    mavlink::Demo_heart::msg::SysInfo packet2{};

    mavlink_msg_sysinfo_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.sysState, packet2.sysState);
    EXPECT_EQ(packet_in.voltageBattery, packet2.voltageBattery);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif
