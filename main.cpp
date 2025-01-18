#include "real_weather_api.h"
#include "weather_display.h"
#include <iostream>

int main() {
    const std::string city = "Wolfsburg";
    const std::string token = "c417bfd432d32985a579e4363b63a49f";

    try {
        RealWeatherAPI realApi(token);
        WeatherDisplay display(realApi);

        std::string result = display.displayWeather(city);
        std::cout << result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
