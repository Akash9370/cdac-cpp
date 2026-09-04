#include <iostream>
#include <string>
#include <vector>
#include "Vehicle.h"
#include "Car.h"
#include "Truck.h"

using namespace std;

int main() {
    vector<Vehicle*> vehicleList;
    char continueChoice;

    cout << "========================================" << endl;
    cout << "    AUTOMATED PARKING MANAGEMENT SYSTEM" << endl;
    cout << "========================================" << endl;

    do {
        char vehicleChoice;
        int parkingHours;

        // Input Validation for Vehicle Type
        while (true) {
            cout << "\nEnter type of Vehicle (C for Car, T for Truck): ";
            cin >> vehicleChoice;
            if (vehicleChoice == 'C' || vehicleChoice == 'c' || vehicleChoice == 'T' || vehicleChoice == 't') {
                break;
            }
            cout << "Invalid vehicle type! Please enter 'C' or 'T'." << endl;
        }

        // Input Validation for Parking Hours
        while (true) {
            cout << "Enter parking hours: ";
            cin >> parkingHours;
            if (parkingHours > 0) {
                break;
            }
            cout << "Parking hours must be positive numbers! Please try again." << endl;
        }

        Vehicle* myVehicle = nullptr;

        if (vehicleChoice == 'C' || vehicleChoice == 'c') {
            myVehicle = new Car(parkingHours);
        } else {
            string codeInput;
            cout << "Enter discount code if available (or press Enter to skip): ";
            cin.ignore();
            getline(cin, codeInput);
            myVehicle = new Truck(parkingHours, codeInput);
        }

        // Store in vector for later cleanup
        vehicleList.push_back(myVehicle);

        // Display receipt immediately using runtime polymorphism
        myVehicle->calculateCharge();

        cout << "\nDo you want to enter another vehicle? (y/n): ";
        cin >> continueChoice;

    } while (continueChoice == 'y' || continueChoice == 'Y');

    // Clean up heap memory
    for (Vehicle* v : vehicleList) {
        delete v;
    }
    vehicleList.clear();

    cout << "\nProgram closed successfully. All memory cleaned up." << endl;
    return 0;
}