// weather_processing.h
#ifndef WEATHER_PROCESSING_H
#define WEATHER_PROCESSING_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Path to the raw data file and processed data file
#define RAW_DATA_FILE "/root_address_to_file/CEP/rawdata.txt"  //add root address of rawdata.txt file
#define PROCESSED_DATA_FILE "/root_address_to_file/processed_data.txt" //add root address for processed_data.txt

// Function declarations
void get_current_datetime(char *buffer, size_t size);
void process_weather_data();

#endif // WEATHER_PROCESSING_H
