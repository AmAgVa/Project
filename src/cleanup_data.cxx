#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <iomanip>
#include <cstdlib>
#include "cleanup_data.h" // Include the cleanup function header

void cleanupDataFiles() {
    // Delete "warmest_days.txt" if it exists
    if (std::remove("warmest_days.txt") == 0) {
    }

    // Delete "coldest_days.txt" if it exists
    if (std::remove("coldest_days.txt") == 0) {
   }

    // Rename "output.txt" to "coldest_days.txt"
    if (std::rename("output.txt", "coldest_days.txt") == 0) {
    }

    // Rename "output2.txt" to "warmest_days.txt"
    if (std::rename("output2.txt", "warmest_days.txt") == 0) {
    }
}