#include "bitFlyer.h"
#include <curl/curl.h>
#include <iostream>

tbitFlyer bitflyer;

void tbitFlyer::fetchbitFlyer() {
    std::string readBuffer;
    CURL* curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "https://api.bitflyer.com/v1/getticker?product_code=BTC_JPY");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        try {
            json j = json::parse(readBuffer);
            bitFlyerjsontoStr(j);
            //std::cout << readBuffer << std::endl;
        } catch(...) { std::cerr << "bitFlyer JSON parse error\n"; }
    }
}
void tbitFlyer::bitFlyerjsontoStr(const json& j) {
    btcjpy.symbol    = "BTCJPY";
    btcjpy.last      = j.value("ltp", "");
    btcjpy.ask       = j.value("best_ask", "");
    btcjpy.bid       = j.value("best_bid", "");
    btcjpy.volume    = j.value("volume", "");
    btcjpy.timestamp = j.value("timestamp", "");
}
/*
{"product_code":"BTC_JPY",
"state":"RUNNING",
"timestamp":"2025-11-23T10:33:16.52",
"tick_id":14771261,
"best_bid":13483863.0,
"best_ask":13492440.0,
"best_bid_size":0.01,
"best_ask_size":0.104478,
"total_bid_depth":138.80482354,
"total_ask_depth":307.18693969,
"market_bid_size":0.0,
"market_ask_size":0.0,
"ltp":13492440.0,
"volume":1675.97535776,
"volume_by_product":549.3421787}
*/