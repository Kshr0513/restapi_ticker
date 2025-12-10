#include "GMO.h"
#include <curl/curl.h>
#include <iostream>
tGMO gmo;

void tGMO::fetchGMO() {
    std::string readBuffer;
    CURL* curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "https://api.coin.z.com/public/v1/ticker");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        //curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);

        curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        try {
            json j = json::parse(readBuffer);
            //GMOjsontoStr(j["data"][0], rate);
            GetRateFromJson(j);
        } catch(...) { std::cerr << "GMO JSON parse error\n"; }
    }
}
void tGMO::GetRateFromJson(const json& j){
    for (const auto& item : j["data"]) {
        if (item.value("symbol", "") == "BTC") {
            btcjpy.ask       = item.value("ask", "");
            btcjpy.bid       = item.value("bid", "");
            btcjpy.high      = item.value("high", "");
            btcjpy.last      = item.value("last", "");
            btcjpy.low       = item.value("low", "");
            btcjpy.symbol    = "BTCJPY";
            btcjpy.timestamp = item.value("timestamp", "");
            btcjpy.volume    = item.value("volume", "");
        }
        else if(item.value("symbol", "") == "ETH") {
            ethjpy.ask       = item.value("ask", "");
            ethjpy.bid       = item.value("bid", "");
            ethjpy.high      = item.value("high", "");
            ethjpy.last      = item.value("last", "");
            ethjpy.low       = item.value("low", "");
            ethjpy.symbol    = "ETHJPY";
            ethjpy.timestamp = item.value("timestamp", "");
            ethjpy.volume    = item.value("volume", "");
        }
        else if(item.value("symbol", "") == "XRP") {
            xrpjpy.ask       = item.value("ask", "");
            xrpjpy.bid       = item.value("bid", "");
            xrpjpy.high      = item.value("high", "");
            xrpjpy.last      = item.value("last", "");
            xrpjpy.low       = item.value("low", "");
            xrpjpy.symbol    = "XRPJPY";
            xrpjpy.timestamp = item.value("timestamp", "");
            xrpjpy.volume    = item.value("volume", "");
        }
        else if(item.value("symbol", "") == "SOL") {
            soljpy.ask       = item.value("ask", "");
            soljpy.bid       = item.value("bid", "");
            soljpy.high      = item.value("high", "");
            soljpy.last      = item.value("last", "");
            soljpy.low       = item.value("low", "");
            soljpy.symbol    = "SOLJPY";
            soljpy.timestamp = item.value("timestamp", "");
            soljpy.volume    = item.value("volume", "");
        }
    }
}
tGMO::tGMO() {
    btcjpy = {};
    ethjpy = {};
    xrpjpy = {};
    soljpy = {};
}
/*
{"status":0,"data":[
{"ask":"1.993","bid":"1.988","high":"2.013","last":"1.993","low":"1.927","symbol":"ASTR","timestamp":"2025-11-23T12:08:07.904Z","volume":"3029578"},
{"ask":"999.999","bid":"997.001","high":"999.999","last":"997","low":"997","symbol":"NAC","timestamp":"2025-11-23T12:08:08.305Z","volume":"1309"},
{"ask":"13528993","bid":"13520357","high":"13585122","last":"13521032","low":"13178750","symbol":"BTC_JPY","timestamp":"2025-11-23T12:08:07.985Z","volume":"860.423"},
{"ask":"440776","bid":"440491","high":"446000","last":"440759","low":"428026","symbol":"ETH_JPY","timestamp":"2025-11-23T12:08:08.854Z","volume":"5199.64"},
{"ask":"85950","bid":"85863","high":"87970","last":"85950","low":"84181","symbol":"BCH_JPY","timestamp":"2025-11-23T12:08:08.530Z","volume":"4403.6"},
{"ask":"13025","bid":"13009","high":"13173","last":"13016","low":"12770","symbol":"LTC_JPY","timestamp":"2025-11-23T12:08:08.514Z","volume":"2804"},
{"ask":"318.701","bid":"318.485","high":"324.416","last":"318.827","low":"300.82","symbol":"XRP_JPY","timestamp":"2025-11-23T12:08:08.384Z","volume":"11062620"},
{"ask":"367","bid":"366","high":"372","last":"364","low":"358","symbol":"DOT_JPY","timestamp":"2025-11-23T12:08:08.325Z","volume":"30438"},
{"ask":"400","bid":"398","high":"401","last":"398","low":"390","symbol":"ATOM_JPY","timestamp":"2025-11-23T12:08:07.923Z","volume":"11858"},
{"ask":"64.47","bid":"64.381","high":"65","last":"64.4","low":"63.005","symbol":"ADA_JPY","timestamp":"2025-11-23T12:08:08.522Z","volume":"525090"},
{"ask":"1963","bid":"1960","high":"1962","last":"1961","low":"1879","symbol":"LINK_JPY","timestamp":"2025-11-23T12:08:08.512Z","volume":"12129"},
{"ask":"22.515","bid":"22.5","high":"22.598","last":"22.501","low":"21.742","symbol":"DOGE_JPY","timestamp":"2025-11-23T12:08:08.045Z","volume":"34887300"},
{"ask":"20345","bid":"20328","high":"20608","last":"20345","low":"19735","symbol":"SOL_JPY","timestamp":"2025-11-23T12:08:08.379Z","volume":"36272.4"},
{"ask":"13530000","bid":"13529999","high":"13599997","last":"13530000","low":"13190001","symbol":"BTC","timestamp":"2025-11-23T12:08:08.883Z","volume":"132.33651"},
{"ask":"441075","bid":"441051","high":"446325","last":"441074","low":"428719","symbol":"ETH","timestamp":"2025-11-23T12:08:08.530Z","volume":"1843.2427"},
{"ask":"85905","bid":"85811","high":"88000","last":"85830","low":"84205","symbol":"BCH","timestamp":"2025-11-23T12:08:08.524Z","volume":"2235.268"},
{"ask":"13021","bid":"13013","high":"13184","last":"13021","low":"12755","symbol":"LTC","timestamp":"2025-11-23T12:08:07.782Z","volume":"6472.24"},
{"ask":"318.971","bid":"318.748","high":"324.6","last":"318.978","low":"301.64","symbol":"XRP","timestamp":"2025-11-23T12:08:08.883Z","volume":"3362792"},
{"ask":"37.517","bid":"37.452","high":"37.634","last":"37.518","low":"35.51","symbol":"XLM","timestamp":"2025-11-23T12:08:08.646Z","volume":"704753"},
{"ask":"77.295","bid":"77.2","high":"77.339","last":"77.2","low":"76.13","symbol":"XTZ","timestamp":"2025-11-23T12:08:07.941Z","volume":"18155.5"},
{"ask":"367","bid":"366","high":"370","last":"366","low":"360","symbol":"DOT","timestamp":"2025-11-23T12:08:08.638Z","volume":"27930.6"},
{"ask":"400","bid":"398","high":"400","last":"399","low":"391","symbol":"ATOM","timestamp":"2025-11-23T12:08:08.518Z","volume":"17662.85"},
{"ask":"156.993","bid":"156.313","high":"156.995","last":"156.332","low":"156.234","symbol":"DAI","timestamp":"2025-11-23T12:08:08.427Z","volume":"7342"},
{"ask":"0.189","bid":"0.188","high":"0.192","last":"0.19","low":"0.186","symbol":"FCR","timestamp":"2025-11-23T12:08:08.460Z","volume":"1487234"},
{"ask":"64.5","bid":"64.431","high":"64.973","last":"64.405","low":"62.634","symbol":"ADA","timestamp":"2025-11-23T12:08:08.513Z","volume":"540251"},
{"ask":"1963","bid":"1961","high":"1971","last":"1963","low":"1875","symbol":"LINK","timestamp":"2025-11-23T12:08:08.325Z","volume":"9521.2"},
{"ask":"22.515","bid":"22.511","high":"22.58","last":"22.513","low":"21.8","symbol":"DOGE","timestamp":"2025-11-23T12:08:07.996Z","volume":"8579319"},
{"ask":"20350","bid":"20349","high":"20600","last":"20350","low":"19748","symbol":"SOL","timestamp":"2025-11-23T12:08:08.523Z","volume":"14394"}],
"responsetime":"2025-11-23T12:08:09.109Z"}
*/