#include <iostream>

enum class Weather {
    Sunny,
    Cloudy,
    Rainy,
    Snowy
};

std::string get_weather_advice(Weather w){
    switch(w){
        case Weather::Sunny: return "适合出门";
        case Weather::Cloudy: return "带把伞吧";
        case Weather::Rainy: return "别出门了";
        case Weather::Snowy: return "多穿点吧";
    }
    return "";
}

int main(){
    Weather today = Weather::Rainy;

   std::cout<<get_weather_advice(today)<<std::endl;

   for(int i = 0;i<4;i++){
    Weather w = static_cast<Weather>(i);
    std::cout<<i<<" -> "<<get_weather_advice(w)<<std::endl;
   }
}