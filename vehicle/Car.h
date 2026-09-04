#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"

class Car : public Vehicle {
private:
    string fuelType;

public:
    Car(string regNo, string model, string manu, int yr, string fuel);
    void displayInfo() const override;
    string getFuelType() const;
};

#endif