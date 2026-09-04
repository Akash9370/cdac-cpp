#include "Bike.h"

Bike::Bike(string regNo, string model, string manu, int yr, string engineCap)
    : Vehicle(regNo, model, manu, yr), engineCapacity(engineCap) {
    if (engineCap.empty()) {
        throw invalid_argument("Exception: Engine capacity cannot be empty!");
    }
}

void Bike::displayInfo() const {
    cout << formatBaseDetails() << ", EngineCapacity: " << engineCapacity << endl;
}

string Bike::getEngineCapacity() const {
    return engineCapacity;
}