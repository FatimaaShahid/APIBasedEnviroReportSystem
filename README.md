**API BASED ENVIRONMENT REPORTING SYSTEM**

**Overview**
This project aims to create an Integrated Environmental Monitoring System using the C programming language. The system interacts with the OpenWeatherMap API to retrieve real-time environmental data such as temperature, humidity, wind speed, and visibility. The core functionalities include:

•	Retrieving weather data in real-time.

•	Storing both raw and processed data in files.

•	Automating data processing tasks through shell scripts.

•	Implementing memory optimization techniques with pointers and dynamic memory allocation.

•	Sending real-time alerts for critical environmental conditions.

**Features**

•	Real-time Data Fetching: The system uses cURL to fetch weather data from the OpenWeatherMap API.

•	Data Processing: It calculates the average of temperature, humidity, wind speed, and visibility, and logs them with timestamps.

•	Shell Script Automation: Shell scripts are used to automate the data retrieval and alert notifications.

•	Real-time Alerts: Alerts are triggered for abnormal weather conditions like high temperatures, low visibility, and high wind speeds.

•	Modular Design: The C code is modularized using header files to improve readability and maintainability.

**Installation**

To run this project on your local system, follow these steps:

**1.	Clone the Repository:**

      Git clone https://github.com/FatimaaShahid/APIBasedEnviroReportSystem.git

**2.	Install Required Libraries:**

  o	You will need libcurl to interact with the API. 
  
  On Linux, you can install it with:
  
      sudo apt-get install libcurl4-openssl-dev

**3.	Compile the Code:**

Navigate to the project directory and compile the C program:
      
**•	To compile program 1 (raw data):**

      gcc raw_data_main.c  weather-1.c –o raw_data_main –lcurl
      
**•	To compile program 2 (processed data):**

      gcc -o processed_data_program  processed_data_main.c  weather_processing.c

**4.	Run the Program:**

Execute the program to start fetching and processing weather data:
      
      ./raw_data_main (program1)
      ./processed_data_program (program 2)

**5.	Automation via Shell Script:**

Use the provided shell script to trigger notifications based on critical weather conditions:

      ./weather_alert.sh

**File Structure :**


•	**Weather-1.h:** Contains the function declarations of raw_data_main.c , API link and all the raw_data_main.c data.

•	**Weather-1.c:** Contains implementation of function defined in weather-1.h and alert conditions to generate alert messages.

•	**Raw_data_main.c:** is the main file of program 1.

•	**weather_processing.c:** Responsible for processing the raw data and saving it in a structured format in a file named processed data.

•	**Weather_processing.h**: Contains the function declarations of processed_data.c

•	**Processed_data_main.c:** is the main file of program 2.

•	**weather_alert.sh:** Shell script for sending notifications when critical weather conditions are detected.

•	**rawdata.txt:** File to store the fetched raw weather data.

•	**processed_data.txt:** File to store the processed and averaged weather data.

