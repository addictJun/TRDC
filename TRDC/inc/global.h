#pragma once
#ifndef GLOBEL_H
#define GLOBEL_H

// (0xffff ffff）设定为“用户命令
//由R和X开头的是name，其他为键值


//扫描串口
#define S_SCAN_SERIAL            "scan_serial"
#define SCAN_DATA_LIST           "scan_data_list"

/// 打开串口
#define S_OPEN_SERIAL            "open_serial"
#define BAUD                      "baud"
#define COM                       "com"

/// 关闭串口
#define S_CLOSE_SERIAL		      "close_serial"

/// 显示
#define S_STOP_REV                "stop_rev"
#define S_START_REV               "start_rev"

/// 发送数据
#define S_SEND_DATA              "send_data"
#define SEND_DATA                "send_data"
#define WEEK_FLAG                "week_flag"
#define HEX_FLAG                 "hex_flag"
#define R_SEND_DATA				 "r_send_data"

/// 接收数据
#define S_RECV_DATA              "recv_data"




#endif // !TR_GLOBEL_H