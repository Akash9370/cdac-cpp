#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
using namespace std;

class Vehicle {
protected:
    int hours;
    string vehicleType;
    static int receiptCount;

    // Inline utility function for extra charges
    inline double computeExtraCharge(int totalHours, int baseHours, double hourlyRate) {
        if (totalHours > baseHours) {
            return (totalHours - baseHours) * hourlyRate;
        }
        return 0.0;
    }

public:
    Vehicle(int h, string type);
    virtual ~Vehicle() {}

    // Pure virtual function (NO "= 0" or "virtual" in cpp files)
    virtual void calculateCharge() = 0;

    static int getReceiptCount();
};

#endif