#include "Truck.h"
#include <iostream>

using namespace std;

Truck::Truck(int hrs, string code) : Vehicle(hrs, "Truck"), discountCode(code) {}

void Truck::calculateCharge() {
    double fixedCharge = 200.0;
    double extraCharge = computeExtraCharge(hours, 2, 50.0);
    double totalCharge = fixedCharge + extraCharge;

    bool isValidDiscount = validateDiscount(discountCode, string("TRUCK50"));

    if (isValidDiscount) {
        totalCharge -= 50.0;
    }

    cout << "\n--- Parking Receipt ---" << endl;
    cout << "Vehicle type = " << vehicleType << endl;
    cout << "Extra charge = Rs. " << extraCharge << endl;

    if (isValidDiscount) {
        cout << "Total Charge after discount = Rs. " << totalCharge << endl;
    } else {
        cout << "Total Parking Charge = Rs. " << totalCharge << endl;
    }
    cout << "Receipts generated so far: " << getReceiptCount() << endl;
}