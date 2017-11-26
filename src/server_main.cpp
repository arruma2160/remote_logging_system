#include "zhelpers.h"
#include "custom_logger.hpp"
#include <unistd.h>


int main (void)
{
    while (1) {
        log_info("info message 1");
        log_info("info message 2");
        log_info("info message 3");

        log_debug("debug message 1");
        log_debug("debug message 2");
        log_debug("debug message 3");

        log_error("error message 1");
        log_error("error message 2");
        log_error("error message 3");

        sleep(1);
    }
    return 0;
}

