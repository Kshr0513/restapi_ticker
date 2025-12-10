#ifndef BITBANK_H
#define BITBANK_H

#include <string>
#include "json.hpp"
#include "rate.h"
#include "main.h"

using json = nlohmann::json;

class tbitbank {
    public:
        sRate btcjpy;
        sRate ethjpy;
        sRate xrpjpy;
        sRate soljpy;
        tbitbank();
        void fetchbitbank();
        void GetRateFromJson(const json& j);
};
extern tbitbank bitbank;
#endif // BITBANK_H