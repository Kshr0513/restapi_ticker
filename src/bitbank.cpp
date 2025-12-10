#include "bitbank.h"
#include <curl/curl.h>
#include <iostream>
tbitbank bitbank;

void tbitbank::fetchbitbank() {
    std::string readBuffer;
    CURL* curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "https://public.bitbank.cc/tickers");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        try {
            json j = json::parse(readBuffer);
            GetRateFromJson(j);
        } catch(...) { std::cerr << "bitbank JSON parse error\n"; }
    }
    //std::cout << readBuffer << std::endl;
}
void tbitbank::GetRateFromJson(const json& j){
    for (const auto& item : j["data"]) {
        if (item.value("pair", "") == "btc_jpy") {
            btcjpy.ask       = item.value("sell", "");
            btcjpy.bid       = item.value("buy", "");
            btcjpy.high      = item.value("high", "");
            btcjpy.last      = item.value("last", "");
            btcjpy.low       = item.value("low", "");
            btcjpy.symbol    = "BTCJPY";
            btcjpy.timestamp = item.value("timestamp", "");
            btcjpy.volume    = item.value("vol", "");
        }
        else if(item.value("pair", "") == "eth_jpy") {
            ethjpy.ask       = item.value("sell", "");
            ethjpy.bid       = item.value("buy", "");
            ethjpy.high      = item.value("high", "");
            ethjpy.last      = item.value("last", "");
            ethjpy.low       = item.value("low", "");
            ethjpy.symbol    = "ETHJPY";
            ethjpy.timestamp = item.value("timestamp", "");
            ethjpy.volume    = item.value("vol", "");
        }
        else if(item.value("pair", "") == "xrp_jpy") {
            xrpjpy.ask       = item.value("sell", "");
            xrpjpy.bid       = item.value("buy", "");
            xrpjpy.high      = item.value("high", "");
            xrpjpy.last      = item.value("last", "");
            xrpjpy.low       = item.value("low", "");
            xrpjpy.symbol    = "XRPJPY";
            xrpjpy.timestamp = item.value("timestamp", "");
            xrpjpy.volume    = item.value("vol", "");
        }
        else if(item.value("pair", "") == "sol_jpy") {
            soljpy.ask       = item.value("sell", "");
            soljpy.bid       = item.value("buy", "");
            soljpy.high      = item.value("high", "");
            soljpy.last      = item.value("last", "");
            soljpy.low       = item.value("low", "");
            soljpy.symbol    = "SOLJPY";
            soljpy.timestamp = item.value("timestamp", "");
            soljpy.volume    = item.value("vol", "");
        }
    }
}
tbitbank::tbitbank() {
    btcjpy = {};
    ethjpy = {};
    xrpjpy = {};
    soljpy = {};
}
/*
{"success":1,"data":[
{"pair":"btc_jpy","sell":"13585410","buy":"13585409","open":"13212201","high":"13650000","low":"13160923","last":"13585409","vol":"173.0226","timestamp":1763911933545},
{"pair":"xrp_jpy","sell":"321.620","buy":"321.570","open":"303.200","high":"324.900","low":"300.895","last":"321.300","vol":"10008894.3419","timestamp":1763911933588},
{"pair":"eth_jpy","sell":"441660","buy":"441659","open":"430126","high":"447313","low":"427001","last":"441492","vol":"3322.6696","timestamp":1763911933588},
{"pair":"sol_jpy","sell":"20554.4","buy":"20550.1","open":"19902.7","high":"20777.2","low":"19758.9","last":"20521.8","vol":"24735.5609","timestamp":1763911933483},
{"pair":"dot_jpy","sell":"363.422","buy":"362.242","open":"361.517","high":"370.971","low":"357.133","last":"362.223","vol":"19989.7611","timestamp":1763911933545},
{"pair":"doge_jpy","sell":"22.833","buy":"22.832","open":"21.750","high":"22.914","low":"21.513","last":"22.827","vol":"32934277.6148","timestamp":1763911933588},
{"pair":"ltc_jpy","sell":"13069.6","buy":"13066.5","open":"12800.6","high":"13200.0","low":"12686.1","last":"13056.2","vol":"4560.2939","timestamp":1763911933545},
{"pair":"bcc_jpy","sell":"85227","buy":"84901","open":"84518","high":"88900","low":"83520","last":"85027","vol":"879.2634","timestamp":1763911933400},
{"pair":"mona_jpy","sell":"13.681","buy":"13.680","open":"13.399","high":"13.800","low":"13.102","last":"13.682","vol":"24813.3281","timestamp":1763911873810},
{"pair":"xlm_jpy","sell":"37.940","buy":"37.850","open":"35.775","high":"38.085","low":"35.550","last":"37.727","vol":"2474098.4153","timestamp":1763911933545},
{"pair":"qtum_jpy","sell":"244.195","buy":"243.644","open":"240.970","high":"245.727","low":"239.589","last":"243.921","vol":"16398.4952","timestamp":1763911933545},
{"pair":"bat_jpy","sell":"30.094","buy":"29.926","open":"29.591","high":"31.482","low":"29.530","last":"29.969","vol":"1745049.1302","timestamp":1763911933400},
{"pair":"omg_jpy","sell":"14.135","buy":"13.855","open":"14.206","high":"14.598","low":"13.200","last":"14.135","vol":"3041.1177","timestamp":1763911873810},
{"pair":"xym_jpy","sell":"0.669","buy":"0.666","open":"0.643","high":"0.670","low":"0.632","last":"0.666","vol":"5628418.7578","timestamp":1763911930517},
{"pair":"link_jpy","sell":"1975.441","buy":"1967.264","open":"1871.067","high":"1992.467","low":"1859.000","last":"1970.859","vol":"19418.8746","timestamp":1763911933588},
{"pair":"mkr_jpy","sell":null,"buy":null,"open":"259371","high":"259371","low":"259371","last":"259371","vol":"0.0000","timestamp":1763911873810},
{"pair":"boba_jpy","sell":"7.295","buy":"7.023","open":"6.847","high":"7.430","low":"6.764","last":"7.044","vol":"818670.6804","timestamp":1763911933483},
{"pair":"enj_jpy","sell":"7.000","buy":"6.979","open":"7.013","high":"7.013","low":"6.485","last":"7.000","vol":"16800.7156","timestamp":1763911919427},
{"pair":"astr_jpy","sell":"1.993","buy":"1.992","open":"1.922","high":"2.013","low":"1.914","last":"1.992","vol":"9805989.4136","timestamp":1763911933295},
{"pair":"ada_jpy","sell":"64.788","buy":"64.694","open":"62.412","high":"65.423","low":"62.122","last":"64.675","vol":"849047.0990","timestamp":1763911933545},
{"pair":"avax_jpy","sell":"2086.000","buy":"2085.628","open":"2071.625","high":"2101.953","low":"2054.150","last":"2088.173","vol":"13565.5552","timestamp":1763911933588},
{"pair":"axs_jpy","sell":"174.228","buy":"172.716","open":"171.106","high":"179.377","low":"170.190","last":"175.914","vol":"6807.9296","timestamp":1763911933483},
{"pair":"flr_jpy","sell":"2.087","buy":"2.082","open":"1.931","high":"2.120","low":"1.903","last":"2.080","vol":"10551084.9271","timestamp":1763911933400},
{"pair":"sand_jpy","sell":"24.031","buy":"23.916","open":"23.449","high":"24.461","low":"23.336","last":"23.994","vol":"47717.3360","timestamp":1763911932335},
{"pair":"gala_jpy","sell":"1.174","buy":"1.171","open":"1.162","high":"1.189","low":"1.156","last":"1.168","vol":"3436980.1246","timestamp":1763911933588},
{"pair":"chz_jpy","sell":"4.398","buy":"4.382","open":"4.379","high":"4.424","low":"4.344","last":"4.406","vol":"29271.3504","timestamp":1763911933084},
{"pair":"ape_jpy","sell":"44.893","buy":"44.212","open":"43.922","high":"44.977","low":"43.238","last":"44.977","vol":"66662.9807","timestamp":1763911933483},
{"pair":"oas_jpy","sell":"0.387","buy":"0.386","open":"0.383","high":"0.416","low":"0.375","last":"0.386","vol":"11677139.5775","timestamp":1763911932683},
{"pair":"mana_jpy","sell":"25.945","buy":"25.786","open":"26.025","high":"26.162","low":"25.440","last":"26.162","vol":"1549.4639","timestamp":1763911919781},
{"pair":"grt_jpy","sell":"7.865","buy":"7.813","open":"7.563","high":"7.900","low":"7.500","last":"7.809","vol":"258308.0626","timestamp":1763911933350},
{"pair":"rndr_jpy","sell":null,"buy":null,"open":"1337.808","high":"1337.808","low":"1337.808","last":"1337.808","vol":"0.0000","timestamp":1763911873810},
{"pair":"bnb_jpy","sell":"132899","buy":"132516","open":"129279","high":"133782","low":"128370","last":"132714","vol":"317.7503","timestamp":1763911933545},
{"pair":"dai_jpy","sell":"156.798","buy":"156.501","open":"156.829","high":"157.000","low":"156.500","last":"156.799","vol":"25064.0339","timestamp":1763911900723},
{"pair":"op_jpy","sell":"47.786","buy":"47.611","open":"47.331","high":"48.329","low":"46.876","last":"47.501","vol":"85758.3415","timestamp":1763911932964},
{"pair":"arb_jpy","sell":"31.544","buy":"31.472","open":"31.230","high":"32.076","low":"30.911","last":"31.500","vol":"126730.8355","timestamp":1763911933545},
{"pair":"klay_jpy","sell":"12.4730","buy":"12.4127","open":"11.9000","high":"12.4528","low":"11.8709","last":"12.4000","vol":"9486.9708","timestamp":1763911933588},
{"pair":"imx_jpy","sell":"50.358","buy":"48.201","open":"47.828","high":"50.937","low":"47.828","last":"48.024","vol":"141057.8509","timestamp":1763911933545},
{"pair":"mask_jpy","sell":"106.869","buy":"106.135","open":"105.000","high":"107.839","low":"103.661","last":"106.520","vol":"17457.1472","timestamp":1763911933588},
{"pair":"pol_jpy","sell":"21.211","buy":"21.158","open":"20.817","high":"21.450","low":"20.666","last":"21.217","vol":"221850.6372","timestamp":1763911933400},
{"pair":"cyber_jpy","sell":"121.38","buy":"120.92","open":"120.28","high":"124.63","low":"120.28","last":"121.88","vol":"34155.8353","timestamp":1763911933545},
{"pair":"render_jpy","sell":"271.201","buy":"270.046","open":"262.299","high":"277.312","low":"258.200","last":"271.364","vol":"56223.8733","timestamp":1763911933588},
{"pair":"trx_jpy","sell":"43.0802","buy":"43.0511","open":"42.8515","high":"43.2071","low":"42.8106","last":"43.1256","vol":"384819.1250","timestamp":1763911933483},
{"pair":"lpt_jpy","sell":"636.93","buy":"627.03","open":"620.08","high":"648.18","low":"610.00","last":"631.40","vol":"4578.8507","timestamp":1763911931689},
{"pair":"atom_jpy","sell":"395.856","buy":"394.334","open":"389.469","high":"401.130","low":"382.647","last":"394.307","vol":"14094.1497","timestamp":1763911933245},
{"pair":"sui_jpy","sell":"214.078","buy":"213.525","open":"210.000","high":"220.394","low":"206.486","last":"213.800","vol":"168715.96337731","timestamp":1763911933483},
{"pair":"sky_jpy","sell":"6.6699","buy":"6.6403","open":"6.4309","high":"6.7987","low":"6.4309","last":"6.6400","vol":"554841.72083309","timestamp":1763911933025},
{"pair":"xrp_btc","sell":null,"buy":null,"open":"0.00001690","high":"0.00001690","low":"0.00001690","last":"0.00001690","vol":"0.0000","timestamp":1763911873810},
{"pair":"eth_btc","sell":null,"buy":null,"open":"0.08056496","high":"0.08056496","low":"0.08056496","last":"0.08056496","vol":"0.0000","timestamp":1763911873810},
{"pair":"ltc_btc","sell":null,"buy":null,"open":"0.00299999","high":"0.00299999","low":"0.00299999","last":"0.00299999","vol":"0.0000","timestamp":1763911873810},
{"pair":"bcc_btc","sell":null,"buy":null,"open":"0.00590165","high":"0.00590165","low":"0.00590165","last":"0.00590165","vol":"0.0000","timestamp":1763911873810},
{"pair":"mona_btc","sell":null,"buy":null,"open":"0.00002200","high":"0.00002200","low":"0.00002200","last":"0.00002200","vol":"0.0000","timestamp":1763911873810},
{"pair":"xlm_btc","sell":null,"buy":null,"open":"0.00000507","high":"0.00000507","low":"0.00000507","last":"0.00000507","vol":"0.0000","timestamp":1763911873810},
{"pair":"qtum_btc","sell":null,"buy":null,"open":"0.00015250","high":"0.00015250","low":"0.00015250","last":"0.00015250","vol":"0.0000","timestamp":1763911873810},
{"pair":"bat_btc","sell":null,"buy":null,"open":"0.00001595","high":"0.00001595","low":"0.00001595","last":"0.00001595","vol":"0.0000","timestamp":1763911873810},
{"pair":"omg_btc","sell":null,"buy":null,"open":"0.00008715","high":"0.00008715","low":"0.00008715","last":"0.00008715","vol":"0.0000","timestamp":1763911873810},
{"pair":"xym_btc","sell":null,"buy":null,"open":"0.00000200","high":"0.00000200","low":"0.00000200","last":"0.00000200","vol":"0.0000","timestamp":1763911873810},
{"pair":"link_btc","sell":null,"buy":null,"open":"0.00036000","high":"0.00036000","low":"0.00036000","last":"0.00036000","vol":"0.0000","timestamp":1763911873810},
{"pair":"mkr_btc","sell":null,"buy":null,"open":"0.03300000","high":"0.03300000","low":"0.03300000","last":"0.03300000","vol":"0.0000","timestamp":1763911873810},
{"pair":"boba_btc","sell":null,"buy":null,"open":"0.00001640","high":"0.00001640","low":"0.00001640","last":"0.00001640","vol":"0.0000","timestamp":1763911873810},
{"pair":"enj_btc","sell":null,"buy":null,"open":"0.00002332","high":"0.00002332","low":"0.00002332","last":"0.00002332","vol":"0.0000","timestamp":1763911873810},
{"pair":"matic_btc","sell":null,"buy":null,"open":"0.00004200","high":"0.00004200","low":"0.00004200","last":"0.00004200","vol":"0.0000","timestamp":1763911873810},
{"pair":"matic_jpy","sell":null,"buy":null,"open":"57.383","high":"57.383","low":"57.383","last":"57.383","vol":"0.0000","timestamp":1763911873810}]}
*/