
#include "seasonal.h"
#include "year_temp_anlys.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <string>
#include <tuple>
#include "temperature_data.h"
#include "cleanup_data.h" // Include the cleanup function header

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <CSV filename for weather>" << " <CSV filename for daily temperature>"
                      " <year to use for daily temperature analysis>" << std::endl;
        return 1;
    }

    const std::string filename = argv[1];
    const std::string daily_temperature_file = argv[2];

    YearlyTempAnalysis yearlyTempAnalysis(daily_temperature_file);
    const int year = std::stoi(argv[3]);
    yearlyTempAnalysis.handle_csv(year);



    // Process temperature data (nat)
    int result1 = processTemperatureData1(filename); 
    int result2 = processTemperatureData2();
    int result3 = processTemperatureData3();
    
    //Error check (nat)
    if (result1 != 0 || result2 != 0 || result3 != 0) {
        std::cerr << "Error processing temperature data." << std::endl;
        return 1;
    }

 
    WeatherDataAnalysis weatherAnalysis(filename);
    weatherAnalysis.readWeatherData();

    
    const int startYear = 1780;
    const int endYear = 2022;

    std::vector<std::tuple<int, double>> springData, summerData, autumnData, winterData;

    for (int year = startYear; year <= endYear; year++) {
        springData.push_back(std::make_tuple(year, weatherAnalysis.calculateAverageSeasonTemperature(3, 5, year)));
        summerData.push_back(std::make_tuple(year, weatherAnalysis.calculateAverageSeasonTemperature(6, 8, year)));
        autumnData.push_back(std::make_tuple(year, weatherAnalysis.calculateAverageSeasonTemperature(9, 11, year)));
        winterData.push_back(std::make_tuple(year, weatherAnalysis.calculateAverageSeasonTemperature(12, 2, year)));
    }


    std::ofstream springFile("spring.csv");
    std::ofstream summerFile("summer.csv");
    std::ofstream autumnFile("autumn.csv");
    std::ofstream winterFile("winter.csv");

    if (!springFile.is_open() || !summerFile.is_open() || !autumnFile.is_open() || !winterFile.is_open()) {
        std::cerr << "Failed to open one or more output files for writing." << std::endl;
        return 1;
    }

    for (const auto& entry : springData) {
        int year;
        double averageTemp;
        std::tie(year, averageTemp) = entry;
        springFile << year << " " << averageTemp << std::endl;
    }

    for (const auto& entry : summerData) {
        int year;
        double averageTemp;
        std::tie(year, averageTemp) = entry;
        summerFile << year << " " << averageTemp << std::endl;
    }

    for (const auto& entry : autumnData) {
        int year;
        double averageTemp;
        std::tie(year, averageTemp) = entry;
        autumnFile << year << " " << averageTemp << std::endl;
    }

    for (const auto& entry : winterData) {
        int year;
        double averageTemp;
        std::tie(year, averageTemp) = entry;
        winterFile << year << " " << averageTemp << std::endl;
    }


    springFile.close();
    summerFile.close();
    autumnFile.close();
    winterFile.close();


    // Call the cleanup function from the cleanup_data.cxx (nat)
    cleanupDataFiles();
    
    //(nat)
    std::cout << "Data processing completed successfully." << std::endl;



    return 0;
}
