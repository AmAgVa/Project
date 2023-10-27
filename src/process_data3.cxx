#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <iomanip>
#include "temperature_data.h"

int processTemperatureData3() {
    std::ifstream inputFile("warmest_days.txt");
    std::ofstream outputFile("output2.txt");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        std::cerr << "Error opening files." << std::endl;
        return 1;
    }

    std::string dateStr;
    while (std::getline(inputFile, dateStr)) {
        struct tm tm = {};
        strptime(dateStr.c_str(), "%Y-%m-%d", &tm);

        int dayOfYear = tm.tm_yday + 1;

        outputFile << std::setfill('0') << std::setw(3) << dayOfYear << '\n';
    }

    inputFile.close();
    outputFile.close();

    return 0;
}