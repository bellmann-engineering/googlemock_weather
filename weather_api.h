#ifndef WEATHER_API_H
#define WEATHER_API_H

#include <string>

class WeatherAPI {
public:
    virtual ~WeatherAPI() = default;
    virtual std::string fetchWeather(const std::string& city) = 0; // Returns weather JSON or string
};

#endif // WEATHER_API_H
