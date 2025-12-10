#ifndef BITFLYER_H
#define BITFLYER_H

#include <string>
#include "json.hpp"
#include "rate.h"
#include "main.h"

using json = nlohmann::json;

class tbitFlyer {
    public:
        sRate btcjpy;
        sRate ethjpy;
        void fetchbitFlyer();
        void bitFlyerjsontoStr(const json& j);
};

extern tbitFlyer bitflyer;
#endif // BITFLYER_H