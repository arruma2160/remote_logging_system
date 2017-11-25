#ifndef PUB_SUB_CONFIG_HPP_
#define PUB_SUB_CONFIG_HPP_

#include <string>
#include <unistd.h>

class PubSubConfig {
    /**
     *
     */
    PubSubConfig(){};  // TODO: read from file config params
    PubSubConfig(const PubSubConfig&) = delete;
    PubSubConfig& operator=(const PubSubConfig&) = delete;

    static constexpr std::string m_port = "2222";  // TODO: move this to config file
public:
    /**
     *
     */
    static PubSubConfig& config()
    {
        static PubSubConfig s;
        return s;
    }

    /**
     *
     */
    std::string server_port() 
    {
        return m_port;
    }
};

#endif

