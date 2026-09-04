#include "Vehicle.h"

int Vehicle::receiptCount = 0; // Initialize static member

Vehicle::Vehicle(int h, string type) : hours(h), vehicleType(type) {
    receiptCount++;
}

int Vehicle::getReceiptCount() {
    return receiptCount; // (NO "static" keyword here)
}