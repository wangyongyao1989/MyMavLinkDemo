/** @file
 *	@brief MAVLink comm protocol generated from Demo_heart.xml
 *	@see http://mavlink.org
 */

#pragma once

#include <array>
#include <cstdint>
#include <sstream>

#ifndef MAVLINK_STX
#define MAVLINK_STX 253
#endif

#include "../message.hpp"

namespace mavlink {
namespace Demo_heart {

/**
 * Array of msg_entry needed for @p mavlink_parse_char() (through @p mavlink_get_msg_entry())
 */
constexpr std::array<mavlink_msg_entry_t, 1> MESSAGE_ENTRIES {{ {150, 172, 3, 3, 0, 0, 0} }};

//! MAVLINK VERSION
constexpr auto MAVLINK_VERSION = 1;


// ENUM DEFINITIONS


/** @brief System state. */
enum class SYS_STATE
{
    STOP=0, /* System stop state | */
    RUN=1, /* System run state | */
};

//! SYS_STATE ENUM_END
constexpr auto SYS_STATE_ENUM_END = 2;


} // namespace Demo_heart
} // namespace mavlink

// MESSAGE DEFINITIONS
#include "./mavlink_msg_sysinfo.hpp"

// base include

