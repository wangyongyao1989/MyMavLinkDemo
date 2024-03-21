/** @file
 *  @brief MAVLink comm protocol generated from Demo_heart.xml
 *  @see http://mavlink.org
 */
#pragma once
#ifndef MAVLINK_DEMO_HEART_H
#define MAVLINK_DEMO_HEART_H

#ifndef MAVLINK_H
    #error Wrong include order: MAVLINK_DEMO_HEART.H MUST NOT BE DIRECTLY USED. Include mavlink.h from the same directory instead or set ALL AND EVERY defines from MAVLINK.H manually accordingly, including the #define MAVLINK_H call.
#endif

#define MAVLINK_DEMO_HEART_XML_HASH 703978447510633515

#ifdef __cplusplus
extern "C" {
#endif

// MESSAGE LENGTHS AND CRCS

#ifndef MAVLINK_MESSAGE_LENGTHS
#define MAVLINK_MESSAGE_LENGTHS {}
#endif

#ifndef MAVLINK_MESSAGE_CRCS
#define MAVLINK_MESSAGE_CRCS {{150, 172, 3, 3, 0, 0, 0}}
#endif

#include "../protocol.h"

#define MAVLINK_ENABLED_DEMO_HEART

// ENUM DEFINITIONS


/** @brief System state. */
#ifndef HAVE_ENUM_SYS_STATE
#define HAVE_ENUM_SYS_STATE
typedef enum SYS_STATE
{
   SYS_STOP=0, /* System stop state | */
   SYS_RUN=1, /* System run state | */
   SYS_STATE_ENUM_END=2, /*  | */
} SYS_STATE;
#endif

// MAVLINK VERSION

#ifndef MAVLINK_VERSION
#define MAVLINK_VERSION 1
#endif

#if (MAVLINK_VERSION == 0)
#undef MAVLINK_VERSION
#define MAVLINK_VERSION 1
#endif

// MESSAGE DEFINITIONS
#include "./mavlink_msg_sysinfo.h"

// base include



#if MAVLINK_DEMO_HEART_XML_HASH == MAVLINK_PRIMARY_XML_HASH
# define MAVLINK_MESSAGE_INFO {MAVLINK_MESSAGE_INFO_SysInfo}
# define MAVLINK_MESSAGE_NAMES {{ "SysInfo", 150 }}
# if MAVLINK_COMMAND_24BIT
#  include "../mavlink_get_info.h"
# endif
#endif

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // MAVLINK_DEMO_HEART_H
