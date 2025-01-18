#ifndef REAL_WEATHER_API_H
#define REAL_WEATHER_API_H

#include "weather_api.h"
#include <curl/curl.h>
#include <stdexcept>

class RealWeatherAPI : public WeatherAPI {
    std::string token;

public:
    explicit RealWeatherAPI(const std::string& apiToken) : token(apiToken) {}

    std::string fetchWeather(const std::string& city) override {
        std::string url = "http://api.openweathermap.org/data/2.5/weather?q=" + city + ",de&APPID=" + token + "&units=metric";
        std::string response;

        CURL* curl = curl_easy_init();
        if (!curl) throw std::runtime_error("Failed to initialize CURL");

        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        CURLcode res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            curl_easy_cleanup(curl);
            throw std::runtime_error("CURL request failed: " + std::string(curl_easy_strerror(res)));
        }

        curl_easy_cleanup(curl);
        return response;
    }

private:
    static size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* userData) {
        size_t totalSize = size * nmemb;
        userData->append(static_cast<char*>(contents), totalSize);
        return totalSize;
    }
};

#endif // REAL_WEATHER_API_H
