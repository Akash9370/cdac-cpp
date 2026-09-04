#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"

class Car : public Vehicle {
public:
    Car(int hrs);
    void calculateCharge() override; // "override" goes ONLY here
};

#endif