// weather.c
#include "weather-1.h"
#include <string.h>

// Callback function to handle the data from libcurl
static size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t totalSize = size * nmemb;
    struct MemoryStruct *mem = (struct MemoryStruct *)userp;

    char *ptr = realloc(mem->memory, mem->size + totalSize + 1);
    if(ptr == NULL) return 0;  // out of memory!

    mem->memory = ptr;
    memcpy(&(mem->memory[mem->size]), contents, totalSize);
    mem->size += totalSize;
    mem->memory[mem->size] = 0;

    return totalSize;
}

// Function to fetch weather data using libcurl
char *fetch_weather_data() {
    CURL *curl;
    CURLcode res;
    struct MemoryStruct *chunk = (struct MemoryStruct *)malloc(sizeof(struct MemoryStruct));

    if(chunk == NULL) {
        fprintf(stderr, "Failed to allocate memory for chunk.\n");
        return NULL;
    }

    chunk->memory = malloc(1);  // initial memory allocation
    chunk->size = 0;  // no data at this point

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, API_URL);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)chunk);

        res = curl_easy_perform(curl);
        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
            free(chunk->memory);
            free(chunk);
            return NULL;
        }
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
    return chunk->memory;
}

// Function to extract required data from JSON response
void parse_and_process_weather_data(const char *data) {
    double temp = 0, wind_speed = 0;
    int humidity = 0, visibility = 0;

    // Extract values manually (ideally use a JSON library)
    sscanf(strstr(data, "\"temp\":") + 7, "%lf", &temp);
    sscanf(strstr(data, "\"humidity\":") + 11, "%d", &humidity);
    sscanf(strstr(data, "\"speed\":") + 8, "%lf", &wind_speed);
    sscanf(strstr(data, "\"visibility\":") + 13, "%d", &visibility);

    // Convert Kelvin to Celsius for temperature
    temp -= 273.15;

    // Open file to store raw data
    FILE *file = fopen(FILE_PATH, "a");
    if(file != NULL) {
        fprintf(file, "Temperature: %.2f �C, ", temp);
        fprintf(file, "Humidity: %d%%, ", humidity);
        fprintf(file, "Wind Speed: %.2f m/s, ", wind_speed);
        fprintf(file, "Visibility: %d meters\n", visibility);
        fclose(file);
        printf("Weather data saved to %s\n", FILE_PATH);
    } else {
        perror("Error opening file");
    }

    // Alerts based on conditions
    if(temp > 30) {
        printf("ALERT: Temperature is high (%.2f°C)\n", temp);
        system("/home/abdullah/Desktop/CEP/weather_alert.sh 'Phew, it's hot today! Stay hydrated'");
    } else if(temp < 10) {
        printf("ALERT: Temperature is low (%.2f°C)\n", temp);
        system("/home/abdullah/Desktop/CEP/weather_alert.sh 'Brrr! It's chilly outside. Stay warm!'");
    }

    if(wind_speed > 10) {  // assuming 10 m/s as high wind speed threshold
        printf("ALERT: High wind speed detected (%.2f m/s)\n", wind_speed);
        system("/home/abdullah/Desktop/CEP/weather_alert.sh 'Hold onto your hats! It's super windy.'");
    }

    if(visibility < 1000) {  // assuming low visibility is below 1000 meters
        printf("ALERT: Low visibility detected (%d meters)\n", visibility);
        system("/home/abdullah/Desktop/CEP/weather_alert.sh 'Drive safe! Visibility is low due to fog or mist.'");
    }
}

