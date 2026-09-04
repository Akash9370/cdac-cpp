#ifndef TRUCK_H
#define TRUCK_H

#include "Vehicle.h"
#include <string>

// Function template for discount code validation
template <typename T>
bool validateDiscount(T inputCode, T validCode) {
    return inputCode == validCode;
}

class Truck : public Vehicle {
private:
    std::string discountCode;

public:
    Truck(int hrs, std::string code);
    void calculateCharge() override;
};

#endif