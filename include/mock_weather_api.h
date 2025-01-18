#ifndef MOCK_WEATHER_API_H
#define MOCK_WEATHER_API_H

#include "weather_api.h"
#include <gmock/gmock.h>

class MockWeatherAPI : public WeatherAPI {
public:
    MOCK_METHOD(std::string, fetchWeather, (const std::string& city), (override));
};

#endif // MOCK_WEATHER_API_H
