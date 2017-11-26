#ifndef CUSTOM_LOGGER_HPP_
#define CUSTOM_LOGGER_HPP_

#include <string>
#include "logserver.hpp"

inline void log_info(std::string msg)
{
    LogServer::logger().send_log((char *)"INFO",(char *) msg.c_str());    
}

inline void log_debug(std::string msg)
{
    LogServer::logger().send_log((char *)"DEBUG",(char *) msg.c_str());    
}

inline void log_error(std::string msg)
{
    LogServer::logger().send_log((char *)"ERROR",(char *) msg.c_str());    
}

#endif

