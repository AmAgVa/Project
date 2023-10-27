#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include "temperature_data.h"

int processTemperatureData1() {
    std::ifstream input("cleaneddata_Lund.csv");

    std::vector<TemperatureData> data;
    std::map<int, TemperatureData> warmestDays;
    std::map<int, TemperatureData> coldestDays;

    std::string line;
    while (std::getline(input, line)) {
        std::istringstream iss(line);
        std::string date, time;
        double temperature;

        if (std::getline(iss, date, ';') && std::getline(iss, time, ';') && (iss >> temperature)) {
            int year = std::stoi(date.substr(0, 4));

            if (warmestDays.find(year) == warmestDays.end() || temperature > warmestDays[year].temperature) {
                warmestDays[year] = {date, temperature};
            }

            if (coldestDays.find(year) == coldestDays.end() || temperature < coldestDays[year].temperature) {
                coldestDays[year] = {date, temperature};
            }
        }
    }

    std::ofstream warmestOutput("warmest_days.txt");
    std::ofstream coldestOutput("coldest_days.txt");

    for (const auto& entry : warmestDays) {
        warmestOutput << entry.second.date << std::endl;
    }

    for (const auto& entry : coldestDays) {
        coldestOutput << entry.second.date << std::endl;
    }

    warmestOutput.close();
    coldestOutput.close();

    return 0;
}
