#include<iostream>
using namespace std;
#include "Vehicle.h"
#include "Car.h"

#include "Car.h"
#include <iostream>

using namespace std;

Car::Car(int hrs) : Vehicle(hrs, "Car") {}

void Car::calculateCharge() { // NO "override" here
    double fixedCharge = 100.0;
    double extraCharge = computeExtraCharge(hours, 3, 30.0);
    double totalCharge = fixedCharge + extraCharge;

    cout << "\n--- Parking Receipt ---" << endl;
    cout << "Vehicle type = " << vehicleType << endl;
    cout << "Extra charge = Rs. " << extraCharge << endl;
    cout << "Total Parking Charge = Rs. " << totalCharge << endl;
    cout << "Receipts generated so far: " << getReceiptCount() << endl;
}