#include "Car.h"

Car::Car(string regNo, string model, string manu, int yr, string fuel)
    : Vehicle(regNo, model, manu, yr), fuelType(fuel) {
    if (fuel.empty()) {
        throw invalid_argument("Exception: Fuel type cannot be empty!");
    }
}

void Car::displayInfo() const {
    cout << formatBaseDetails() << ", FuelType: " << fuelType << endl;
}

string Car::getFuelType() const {
    return fuelType;
}