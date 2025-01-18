#ifndef WEATHER_DISPLAY_H
#define WEATHER_DISPLAY_H

#include "weather_api.h"
#include <string>
#include <iostream>
#include <sstream>

class WeatherDisplay {
    WeatherAPI& api;

public:
    explicit WeatherDisplay(WeatherAPI& weatherAPI) : api(weatherAPI) {}

    std::string displayWeather(const std::string& city) {
        std::string response = api.fetchWeather(city);

        // Mock response example: "temp:15.0"
        double temp = 0.0;
        std::istringstream stream(response);
        std::string key;
        char delimiter;
        stream >> key >> delimiter >> temp;

        std::ostringstream result;
        result << "City: " << temp << " °C";
        return result.str();
    }
};

#endif // WEATHER_DISPLAY_H
