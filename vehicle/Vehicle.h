#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include <iostream>
#include <stdexcept>

using namespace std;

// Template function to validate input year (between 2000 and current year 2026)
template <typename T>
bool validateYear(T yr) {
    return (yr >= 2000 && yr <= 2026);
}

class Vehicle {
protected:
    string registrationNumber;
    string modelName;
    string manufacturer;
    int year;
    static int totalVehicles; // Static data member to count records

    // Inline function to format and return the base vehicle display string
    inline string formatBaseDetails() const {
        return "RegNo: " + registrationNumber + 
               ", Model: " + modelName + 
               ", Manufacturer: " + manufacturer + 
               ", Year: " + to_string(year);
    }

public:
    Vehicle(string regNo, string model, string manu, int yr);
    virtual ~Vehicle() {}

    // Pure virtual function enforcing runtime polymorphism
    virtual void displayInfo() const = 0;

    static int getTotalVehicles();
    
    string getRegistrationNumber() const;
    string getModelName() const;
    string getManufacturer() const;
    int getYear() const;
};

#endif