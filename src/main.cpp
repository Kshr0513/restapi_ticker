#include "main.h"
#include <iostream>
#include <thread>
#include <curl/curl.h>

size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output){
    size_t totalSize = size * nmemb;
    output->append((char*)contents, totalSize);
    return totalSize;
}
int main() {
    tCoinCheck coincheck;
    tbitFlyer bitflyer;
    curl_global_init(CURL_GLOBAL_DEFAULT);
    
    // マルチスレッドで同時取得
    std::thread thread_GMO([&]{ gmo.fetchGMO(); });
    std::thread thread_CoinCheck([&]{ coincheck.fetchCoinCheck(); });
    std::thread thread_bitFlyer([&]{ bitflyer.fetchbitFlyer(); });
    std::thread thread_bitbank([&]{ bitbank.fetchbitbank(); });

    thread_GMO.join();
    thread_CoinCheck.join();
    thread_bitFlyer.join();
    thread_bitbank.join();

    std::cout << "===============   GMO  =======================" << std::endl;
    std::cout << gmo.btcjpy.symbol << "-" << gmo.btcjpy.last << "-" << gmo.btcjpy.timestamp << std::endl;
    std::cout << gmo.ethjpy.symbol << "-" << gmo.ethjpy.last << "-" << gmo.ethjpy.timestamp << std::endl;
    std::cout << gmo.xrpjpy.symbol << "-" << gmo.xrpjpy.last << "-" << gmo.xrpjpy.timestamp << std::endl;
    std::cout << gmo.soljpy.symbol << "-" << gmo.soljpy.last << "-" << gmo.soljpy.timestamp << std::endl;
    std::cout << "===============  bitbank  ====================" << std::endl;
    std::cout << bitbank.btcjpy.symbol << "-" << bitbank.btcjpy.ask << "-" << bitbank.btcjpy.bid << std::endl;
    std::cout << bitbank.ethjpy.symbol << "-" << bitbank.ethjpy.ask << "-" << bitbank.ethjpy.bid << std::endl;
    std::cout << bitbank.xrpjpy.symbol << "-" << bitbank.xrpjpy.ask << "-" << bitbank.xrpjpy.bid << std::endl;
    std::cout << bitbank.soljpy.symbol << "-" << bitbank.soljpy.ask << "-" << bitbank.soljpy.bid << std::endl;
    std::cout << "===============  bitFlyer  ===================" << std::endl;
    std::cout << bitflyer.btcjpy.symbol << "-" << bitflyer.btcjpy.bid << "-" << bitflyer.btcjpy.ask << std::endl;
    std::cout << "===============  CoinCheck  ==================" << std::endl;
    std::cout << coincheck.btcjpy.symbol << "-" << coincheck.btcjpy.last << "-" << coincheck.btcjpy.timestamp << std::endl;

    curl_global_cleanup();

    return 0;
}
