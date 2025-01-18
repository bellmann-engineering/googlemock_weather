#ifndef MOCK_WEATHER_API_H
#define MOCK_WEATHER_API_H

#include "weather_api.h"
#include <gmock/gmock.h>

class MockWeatherAPI : public WeatherAPI {
public:
    MOCK_METHOD(std::string, fetchWeather, (const std::string& city), (override));
};

#endif // MOCK_WEATHER_API_H

// weather_display_test.cpp
#include "weather_display.h"
#include "mock_weather_api.h"
#include <gtest/gtest.h>

TEST(WeatherDisplayTest, DisplaysCorrectWeather) {
    MockWeatherAPI mockApi;

    // Set up the mock to return a predefined response
    EXPECT_CALL(mockApi, fetchWeather("Wolfsburg"))
        .Times(1)
        .WillOnce(testing::Return("{\"temp\":15.0}"));

    // Use the mock in the display class
    WeatherDisplay display(mockApi);
    std::string result = display.displayWeather("Wolfsburg");

    // Verify the output
    EXPECT_EQ(result, "City: 15 °C");
}
