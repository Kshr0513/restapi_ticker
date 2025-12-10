#ifndef RATE_H
#define RATE_H

#include <string>

struct sRate {
    std::string ask;
    std::string bid;
    std::string high;
    std::string last;
    std::string low;
    std::string symbol;
    std::string timestamp;
    std::string volume;
    std::string status;
    std::string response;
};

#endif // RATE_H
