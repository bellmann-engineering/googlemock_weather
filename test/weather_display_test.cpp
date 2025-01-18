#include "weather_display.h"
#include "mock_weather_api.h"
#include <gtest/gtest.h>

TEST(WeatherDisplayTest, DisplaysCorrectWeather) {
    MockWeatherAPI mockApi;

    // Mock the API response
    EXPECT_CALL(mockApi, fetchWeather("Wolfsburg"))
        .Times(1)
        .WillOnce(testing::Return("{"temp":15.0}"));

    // Test the display
    WeatherDisplay display(mockApi);
    std::string result = display.displayWeather("Wolfsburg");

    // Verify the output
    EXPECT_EQ(result, "City: 15 °C");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
