// main.c
#include <stdio.h>
#include "weather-1.h"
int main(void) {
    char *weather_data = fetch_weather_data();
    if(weather_data) {
        parse_and_process_weather_data(weather_data);
        free(weather_data);
    } else {
        printf("Failed to retrieve weather data.\n");
    }

    return 0;
}
