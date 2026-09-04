#include "Vehicle.h"

// Initialize static data member
int Vehicle::totalVehicles = 0;

Vehicle::Vehicle(string regNo, string model, string manu, int yr) {
    if (regNo.empty()) {
        throw invalid_argument("Exception: Registration number cannot be empty!");
    }
    if (!validateYear(yr)) {
        throw invalid_argument("Exception: Invalid year! Year must be between 2000 and 2026.");
    }

    registrationNumber = regNo;
    modelName = model;
    manufacturer = manu;
    year = yr;
    totalVehicles++;
}

int Vehicle::getTotalVehicles() {
    return totalVehicles;
}

string Vehicle::getRegistrationNumber() const { return registrationNumber; }
string Vehicle::getModelName() const { return modelName; }
string Vehicle::getManufacturer() const { return manufacturer; }
int Vehicle::getYear() const { return year; }