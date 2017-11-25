#include "logserver.hpp"
#include <unistd.h>


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
    s_sendmore (m_publisher, topic);
    s_send (m_publisher, msg);
}


// -------------------
// Constructor
LogServer::LogServer() 
{
    m_context = zmq_ctx_new ();
    m_publisher = zmq_socket (m_context, ZMQ_PUB);
    zmq_bind (m_publisher, (char *)"tcp://*:5563");
}


// -------------------
// Destructor
LogServer::~LogServer() 
{
    zmq_close (m_publisher);
    zmq_ctx_destroy (m_context);
}
