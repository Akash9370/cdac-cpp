#ifndef BIKE_H
#ifndef BIKE_H
#define BIKE_H

#include "Vehicle.h"

class Bike : public Vehicle {
private:
    string engineCapacity;

public:
    Bike(string regNo, string model, string manu, int yr, string engineCap);
    void displayInfo() const override;
    string getEngineCapacity() const;
};

#endif
#endif