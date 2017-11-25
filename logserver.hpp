#ifndef LOGSERVER_HPP_
#define LOGSERVER_HPP_
#include "zhelpers.h"
#include <string>
#include <unistd.h>

class LogServer {
    /**
     *
     */
    LogServer(std::string port = "2222");

    LogServer(const LogServer&) = delete;
    LogServer& operator=(const LogServer&) = delete;

    void *m_context; /**< */
    void *m_publisher; /**< */
public:
    /**
     *
     */
    static LogServer& logger();

    /**
     *
     */
    int send_log(char *topic, char *msg);

    /**
     *
     */
    ~LogServer();
};

#endif

