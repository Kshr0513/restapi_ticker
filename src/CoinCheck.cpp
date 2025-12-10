#include "CoinCheck.h"
#include <curl/curl.h>
#include <iostream>

tCoinCheck coincheck;

void tCoinCheck::fetchCoinCheck() {
    std::string readBuffer;
    CURL* curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "https://coincheck.com/api/ticker");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        try {
            json j = json::parse(readBuffer);
            coinCheckjsontoStr(j);
        } catch(...) { std::cerr << "CoinCheck JSON parse error\n"; }
    }
    //std::cout << readBuffer << std::endl;
}
void tCoinCheck::coinCheckjsontoStr(const json& j){
    btcjpy.last   = j.value("last", "");
    btcjpy.bid    = j.value("bid", "");
    btcjpy.ask    = j.value("ask", "");
    btcjpy.high   = j.value("high", "");
    btcjpy.low    = j.value("low", "");
    btcjpy.volume = j.value("volume", "");
    btcjpy.symbol = "BTCJPY";
    btcjpy.timestamp = j.value("timestamp", "");
}
/*
{"last":13784049.0,"bid":13784051.0,"ask":13787636.0,"high":13826861.0,"low":13386819.0,"volume":679.42000073,"timestamp":1763951250}
*/