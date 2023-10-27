#include <iostream>
#include "temperature_data.h"
#include "cleanup_data.h" // Include the cleanup function header

int main() {
    int result1 = processTemperatureData1();
    int result2 = processTemperatureData2();
    int result3 = processTemperatureData3();

    if (result1 != 0 || result2 != 0 || result3 != 0) {
        std::cerr << "Error processing data." << std::endl;
        return 1;
    }

    std::cout << "Data processing completed successfully." << std::endl;

    // Call the cleanup function from the cleanup_data.cxx
    cleanupDataFiles();

    return 0;
}