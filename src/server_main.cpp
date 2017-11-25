#include "zhelpers.h"
#include "logserver.hpp"
#include <unistd.h>


int main (void)
{
    while (1) {
        LogServer::logger().send_log((char *)"A", 
                                     (char *)"We don't want to see this");
        LogServer::logger().send_log((char *)"B", 
                                     (char *)"We would like to see this");
        sleep (1);
    }
    return 0;
}

