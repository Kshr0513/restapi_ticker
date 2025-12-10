#ifndef GMO_H
#define GMO_H

#include <string>
#include "json.hpp"
#include "rate.h"
#include "main.h"

using json = nlohmann::json;

class tGMO {
    public:
        sRate btcjpy;
        sRate ethjpy;
        sRate xrpjpy;
        sRate soljpy;
        tGMO();
        void fetchGMO();
        void GetRateFromJson(const json& j);
};
extern tGMO gmo;
#endif // GMO_H
