#include "weather_display.h"
#include "mock_weather_api.h"
#include <gtest/gtest.h>

TEST(WeatherDisplayTest, DisplaysCorrectWeather) {
    // Arrange
    MockWeatherAPI mockApi;

    // Mock the API response
    EXPECT_CALL(mockApi, fetchWeather("Wolfsburg"))
        .Times(1)
        .WillOnce(testing::Return("{\"temp\":15.0}"));  // Correctly escaped JSON

    std::string expected = "Wolfsburg: 15 °C";

    // Act
    WeatherDisplay display(mockApi);
    std::string actual = display.displayWeather("Wolfsburg");

    // Assert
    EXPECT_EQ(actual, expected);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
