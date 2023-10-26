#ifndef TEMPERATURE_DATA_H
#define TEMPERATURE_DATA_H

#include <string>
#include <ctime>

struct TemperatureData {
    std::string date;
    double temperature;
};

int processTemperatureData1();
int processTemperatureData2();
int processTemperatureData3();

#endif // TEMPERATURE_DATA_H