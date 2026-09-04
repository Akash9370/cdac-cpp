#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Vehicle.h"
#include "Car.h"
#include "Bike.h"

using namespace std;

// Helper functions for binary serialization of strings
void writeString(ofstream &out, const string &s) {
    size_t length = s.size();
    out.write(reinterpret_cast<const char*>(&length), sizeof(length));
    out.write(s.c_str(), length);
}

string readString(ifstream &in) {
    size_t length;
    in.read(reinterpret_cast<char*>(&length), sizeof(length));
    string s(length, '\0');
    in.read(&s[0], length);
    return s;
}

int main() {
    int numVehicles = 0;

    cout << "Enter number of vehicles: ";
    while (!(cin >> numVehicles) || numVehicles <= 0) {
        cout << "Invalid input. Please enter a positive integer: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    vector<Vehicle*> vehicles;

    // Input loop with Exception Handling
    for (int i = 0; i < numVehicles; ++i) {
        char type;
        string regNo, model, manu, extraField;
        int yr;

        while (true) {
            try {
                cout << "\nEnter type of vehicle (C for Car, B for Bike): ";
                cin >> type;
                if (type != 'C' && type != 'c' && type != 'B' && type != 'b') {
                    throw invalid_argument("Exception: Invalid vehicle type! Please enter 'C' or 'B'.");
                }

                cout << "Enter Registration Number: ";
                cin >> regNo;
                cout << "Enter Model Name: ";
                cin >> model;
                cout << "Enter Manufacturer: ";
                cin >> manu;
                cout << "Enter Year: ";
                if (!(cin >> yr)) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    throw invalid_argument("Exception: Year must be a valid number.");
                }

                if (type == 'C' || type == 'c') {
                    cout << "Enter Fuel Type: ";
                    cin >> extraField;
                    vehicles.push_back(new Car(regNo, model, manu, yr, extraField));
                } else {
                    cout << "Enter Engine Capacity: ";
                    cin >> extraField;
                    vehicles.push_back(new Bike(regNo, model, manu, yr, extraField));
                }
                break; // Successfully added, break out of retry loop
            } catch (const exception &e) {
                cout << e.what() << " Please re-enter details for this vehicle.\n" << endl;
            }
        }
    }

    // 1. Store vehicle objects into a binary file
    ofstream outFile("vehicles.dat", ios::binary);
    if (!outFile) {
        cerr << "Error: Could not open file for writing!" << endl;
        for (auto v : vehicles) delete v;
        return 1;
    }

    int totalCount = vehicles.size();
    outFile.write(reinterpret_cast<const char*>(&totalCount), sizeof(totalCount));

    for (const auto* v : vehicles) {
        if (const auto* car = dynamic_cast<const Car*>(v)) {
            char type = 'C';
            outFile.write(&type, sizeof(type));
            writeString(outFile, car->getRegistrationNumber());
            writeString(outFile, car->getModelName());
            writeString(outFile, car->getManufacturer());
            int yr = car->getYear();
            outFile.write(reinterpret_cast<const char*>(&yr), sizeof(yr));
            writeString(outFile, car->getFuelType());
        } else if (const auto* bike = dynamic_cast<const Bike*>(v)) {
            char type = 'B';
            outFile.write(&type, sizeof(type));
            writeString(outFile, bike->getRegistrationNumber());
            writeString(outFile, bike->getModelName());
            writeString(outFile, bike->getManufacturer());
            int yr = bike->getYear();
            outFile.write(reinterpret_cast<const char*>(&yr), sizeof(yr));
            writeString(outFile, bike->getEngineCapacity());
        }
    }
    outFile.close();

    // Clean up initial memory heap pointers
    for (auto v : vehicles) {
        delete v;
    }
    vehicles.clear();

    // 2. Read them back from binary file and display records via polymorphism
    cout << "\n---------------------------------------------------------------------------------------" << endl;
    cout << "Expected Output (after reading from file)" << endl;

    ifstream inFile("vehicles.dat", ios::binary);
    if (!inFile) {
        cerr << "Error: Could not open file for reading!" << endl;
        return 1;
    }

    int readCount = 0;
    inFile.read(reinterpret_cast<char*>(&readCount), sizeof(readCount));

    vector<Vehicle*> loadedVehicles;
    for (int i = 0; i < readCount; ++i) {
        char type;
        inFile.read(&type, sizeof(type));
        string regNo = readString(inFile);
        string model = readString(inFile);
        string manu = readString(inFile);
        int yr;
        inFile.read(reinterpret_cast<char*>(&yr), sizeof(yr));
        string extra = readString(inFile);

        if (type == 'C') {
            loadedVehicles.push_back(new Car(regNo, model, manu, yr, extra));
        } else if (type == 'B') {
            loadedVehicles.push_back(new Bike(regNo, model, manu, yr, extra));
        }
    }
    inFile.close();

    // Polymorphic display call
    for (const auto* v : loadedVehicles) {
        v->displayInfo();
    }

    cout << "---------------------------------------------------------------------------------------" << endl;
    cout << "Total Vehicles stored: " << Vehicle::getTotalVehicles() << endl;

    // Clean up loaded heap memory
    for (auto v : loadedVehicles) {
        delete v;
    }
    loadedVehicles.clear();

    return 0;
}