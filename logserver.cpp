#include "logserver.hpp"
#include <string>
#include <unistd.h>
using std::string;


// -------------------
// Get instance of logger
LogServer& LogServer::logger() 
{
    static LogServer logserver;
    return logserver;
}


// -------------------
// Send message function
int LogServer::send_log(char *topic, char *msg)
{
    s_sendmore(m_publisher, topic);
    s_send(m_publisher, msg);
}


// -------------------
// Constructor
LogServer::LogServer(string port) 
{
    m_context = zmq_ctx_new();
    m_publisher = zmq_socket(m_context, ZMQ_PUB);
    
    string bind_to = "tcp://*:" + port;
    zmq_bind(m_publisher, bind_to.c_str());
}


// -------------------
// Destructor
LogServer::~LogServer() 
{
    zmq_close(m_publisher);
    zmq_ctx_destroy(m_context);
}
