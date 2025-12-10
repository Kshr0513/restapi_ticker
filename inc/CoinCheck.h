#ifndef COINCHECK_H
#define COINCHECK_H

#include <string>
#include "json.hpp"
#include "rate.h"
#include "main.h"

using json = nlohmann::json;

class tCoinCheck {
    public:
        sRate btcjpy;
        sRate ethjpy;
        void fetchCoinCheck();
        void coinCheckjsontoStr(const json& j);
};

extern tCoinCheck coincheck;
#endif // COINCHECK_H