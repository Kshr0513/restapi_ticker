#ifndef MAIN_H
#define MAIN_H

#include <string>
#include "json.hpp"
#include "rate.h"
#include "GMO.h"
#include "CoinCheck.h"
#include "bitFlyer.h"
#include "bitbank.h"
using json = nlohmann::json;

extern size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output);
#endif // MAIN_H
