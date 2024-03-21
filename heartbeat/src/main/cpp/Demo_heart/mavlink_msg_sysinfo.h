#pragma once
// MESSAGE SysInfo PACKING

#define MAVLINK_MSG_ID_SysInfo 150


typedef struct __mavlink_sysinfo_t {
 uint16_t voltageBattery; /*<  Battery voltage*/
 uint8_t sysState; /*<  System state.*/
} mavlink_sysinfo_t;

#define MAVLINK_MSG_ID_SysInfo_LEN 3
#define MAVLINK_MSG_ID_SysInfo_MIN_LEN 3
#define MAVLINK_MSG_ID_150_LEN 3
#define MAVLINK_MSG_ID_150_MIN_LEN 3

#define MAVLINK_MSG_ID_SysInfo_CRC 172
#define MAVLINK_MSG_ID_150_CRC 172



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_SysInfo { \
    150, \
    "SysInfo", \
    2, \
    {  { "sysState", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_sysinfo_t, sysState) }, \
         { "voltageBattery", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_sysinfo_t, voltageBattery) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_SysInfo { \
    "SysInfo", \
    2, \
    {  { "sysState", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_sysinfo_t, sysState) }, \
         { "voltageBattery", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_sysinfo_t, voltageBattery) }, \
         } \
}
#endif

/**
 * @brief Pack a sysinfo message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param sysState  System state.
 * @param voltageBattery  Battery voltage
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_sysinfo_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t sysState, uint16_t voltageBattery)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SysInfo_LEN];
    _mav_put_uint16_t(buf, 0, voltageBattery);
    _mav_put_uint8_t(buf, 2, sysState);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SysInfo_LEN);
#else
    mavlink_sysinfo_t packet;
    packet.voltageBattery = voltageBattery;
    packet.sysState = sysState;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SysInfo_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SysInfo;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SysInfo_MIN_LEN, MAVLINK_MSG_ID_SysInfo_LEN, MAVLINK_MSG_ID_SysInfo_CRC);
}

/**
 * @brief Pack a sysinfo message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param sysState  System state.
 * @param voltageBattery  Battery voltage
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_sysinfo_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint8_t sysState, uint16_t voltageBattery)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SysInfo_LEN];
    _mav_put_uint16_t(buf, 0, voltageBattery);
    _mav_put_uint8_t(buf, 2, sysState);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SysInfo_LEN);
#else
    mavlink_sysinfo_t packet;
    packet.voltageBattery = voltageBattery;
    packet.sysState = sysState;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SysInfo_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SysInfo;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_SysInfo_MIN_LEN, MAVLINK_MSG_ID_SysInfo_LEN, MAVLINK_MSG_ID_SysInfo_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_SysInfo_MIN_LEN, MAVLINK_MSG_ID_SysInfo_LEN);
#endif
}

/**
 * @brief Pack a sysinfo message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param sysState  System state.
 * @param voltageBattery  Battery voltage
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_sysinfo_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t sysState,uint16_t voltageBattery)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SysInfo_LEN];
    _mav_put_uint16_t(buf, 0, voltageBattery);
    _mav_put_uint8_t(buf, 2, sysState);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SysInfo_LEN);
#else
    mavlink_sysinfo_t packet;
    packet.voltageBattery = voltageBattery;
    packet.sysState = sysState;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SysInfo_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SysInfo;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SysInfo_MIN_LEN, MAVLINK_MSG_ID_SysInfo_LEN, MAVLINK_MSG_ID_SysInfo_CRC);
}

/**
 * @brief Encode a sysinfo struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param sysinfo C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_sysinfo_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_sysinfo_t* sysinfo)
{
    return mavlink_msg_sysinfo_pack(system_id, component_id, msg, sysinfo->sysState, sysinfo->voltageBattery);
}

/**
 * @brief Encode a sysinfo struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param sysinfo C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_sysinfo_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_sysinfo_t* sysinfo)
{
    return mavlink_msg_sysinfo_pack_chan(system_id, component_id, chan, msg, sysinfo->sysState, sysinfo->voltageBattery);
}

/**
 * @brief Encode a sysinfo struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param sysinfo C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_sysinfo_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_sysinfo_t* sysinfo)
{
    return mavlink_msg_sysinfo_pack_status(system_id, component_id, _status, msg,  sysinfo->sysState, sysinfo->voltageBattery);
}

/**
 * @brief Send a sysinfo message
 * @param chan MAVLink channel to send the message
 *
 * @param sysState  System state.
 * @param voltageBattery  Battery voltage
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_sysinfo_send(mavlink_channel_t chan, uint8_t sysState, uint16_t voltageBattery)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SysInfo_LEN];
    _mav_put_uint16_t(buf, 0, voltageBattery);
    _mav_put_uint8_t(buf, 2, sysState);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SysInfo, buf, MAVLINK_MSG_ID_SysInfo_MIN_LEN, MAVLINK_MSG_ID_SysInfo_LEN, MAVLINK_MSG_ID_SysInfo_CRC);
#else
    mavlink_sysinfo_t packet;
    packet.voltageBattery = voltageBattery;
    packet.sysState = sysState;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SysInfo, (const char *)&packet, MAVLINK_MSG_ID_SysInfo_MIN_LEN, MAVLINK_MSG_ID_SysInfo_LEN, MAVLINK_MSG_ID_SysInfo_CRC);
#endif
}

/**
 * @brief Send a sysinfo message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_sysinfo_send_struct(mavlink_channel_t chan, const mavlink_sysinfo_t* sysinfo)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_sysinfo_send(chan, sysinfo->sysState, sysinfo->voltageBattery);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SysInfo, (const char *)sysinfo, MAVLINK_MSG_ID_SysInfo_MIN_LEN, MAVLINK_MSG_ID_SysInfo_LEN, MAVLINK_MSG_ID_SysInfo_CRC);
#endif
}

#if MAVLINK_MSG_ID_SysInfo_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_sysinfo_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t sysState, uint16_t voltageBattery)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint16_t(buf, 0, voltageBattery);
    _mav_put_uint8_t(buf, 2, sysState);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SysInfo, buf, MAVLINK_MSG_ID_SysInfo_MIN_LEN, MAVLINK_MSG_ID_SysInfo_LEN, MAVLINK_MSG_ID_SysInfo_CRC);
#else
    mavlink_sysinfo_t *packet = (mavlink_sysinfo_t *)msgbuf;
    packet->voltageBattery = voltageBattery;
    packet->sysState = sysState;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SysInfo, (const char *)packet, MAVLINK_MSG_ID_SysInfo_MIN_LEN, MAVLINK_MSG_ID_SysInfo_LEN, MAVLINK_MSG_ID_SysInfo_CRC);
#endif
}
#endif

#endif

// MESSAGE SysInfo UNPACKING


/**
 * @brief Get field sysState from sysinfo message
 *
 * @return  System state.
 */
static inline uint8_t mavlink_msg_sysinfo_get_sysState(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Get field voltageBattery from sysinfo message
 *
 * @return  Battery voltage
 */
static inline uint16_t mavlink_msg_sysinfo_get_voltageBattery(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  0);
}

/**
 * @brief Decode a sysinfo message into a struct
 *
 * @param msg The message to decode
 * @param sysinfo C-struct to decode the message contents into
 */
static inline void mavlink_msg_sysinfo_decode(const mavlink_message_t* msg, mavlink_sysinfo_t* sysinfo)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    sysinfo->voltageBattery = mavlink_msg_sysinfo_get_voltageBattery(msg);
    sysinfo->sysState = mavlink_msg_sysinfo_get_sysState(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_SysInfo_LEN? msg->len : MAVLINK_MSG_ID_SysInfo_LEN;
        memset(sysinfo, 0, MAVLINK_MSG_ID_SysInfo_LEN);
    memcpy(sysinfo, _MAV_PAYLOAD(msg), len);
#endif
}
