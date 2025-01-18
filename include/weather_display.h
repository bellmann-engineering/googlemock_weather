#ifndef WEATHER_DISPLAY_H
#define WEATHER_DISPLAY_H

#include "weather_api.h"
#include <string>
#include <iostream>
#include <sstream>
#include <regex>

class WeatherDisplay {
    WeatherAPI& api;

public:
    explicit WeatherDisplay(WeatherAPI& weatherAPI) : api(weatherAPI) {}

    std::string displayWeather(const std::string& city) {
        std::string response = api.fetchWeather(city);

        // Extract temperature from the JSON response
        std::regex tempRegex(R"("temp":([-+]?[0-9]*\.?[0-9]+))");
        std::smatch match;

        if (std::regex_search(response, match, tempRegex)) {
            double temp = std::stod(match[1].str());

            std::ostringstream result;
            result << city << ": " << temp << " °C";
            return result.str();
        }

        return "Error: Unable to parse temperature.";
    }
};

#endif // WEATHER_DISPLAY_H
