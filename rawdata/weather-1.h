// weather.h
#ifndef WEATHER_H
#define WEATHER_H "weather-1.h"

#include <stdlib.h>
#include <stdio.h>
#include <curl/curl.h>

#define FILE_PATH "/root_address_to_file/CEP/rawdata.txt"
#define API_URL "http://api.openweathermap.org/data/2.5/weather?appid=your_API_key&q=karachi"

// Structure to store fetched data
struct MemoryStruct {
    char *memory;
    size_t size;
};

// Function declarations
char *fetch_weather_data();
void parse_and_process_weather_data(const char *data);

#endif // WEATHER_H

