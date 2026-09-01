#include <iostream>
#include <cstring>
#include "booking.h"

using namespace std;

int Booking::idCounter = 0;

int Booking::generateID() {
    return 1000 + ++idCounter;
}

// Default & Parameterized Constructor (with default values)
Booking::Booking(const char* src, const char* dest, double dist) {
    bookingId = generateID();
    
    source = new char[strlen(src) + 1];
    strcpy(source, src);

    destination = new char[strlen(dest) + 1];
    strcpy(destination, dest);

    distance = dist;
    fare = 0.0;
    fareDistOnly = 0.0;
    fareVehicle = 0.0;
    farePassengers = 0.0;
    farePremium = 0.0;
}

// Copy Constructor (Deep Copy)
Booking::Booking(const Booking& other) {
    bookingId = other.bookingId;
    distance = other.distance;
    fare = other.fare;
    fareDistOnly = other.fareDistOnly;
    fareVehicle = other.fareVehicle;
    farePassengers = other.farePassengers;
    farePremium = other.farePremium;

    source = new char[strlen(other.source) + 1];
    strcpy(source, other.source);

    destination = new char[strlen(other.destination) + 1];
    strcpy(destination, other.destination);
}

// Assignment Operator
Booking& Booking::operator=(const Booking& other) {
    if (this != &other) {
        delete[] source;
        delete[] destination;

        bookingId = other.bookingId;
        distance = other.distance;
        fare = other.fare;
        fareDistOnly = other.fareDistOnly;
        fareVehicle = other.fareVehicle;
        farePassengers = other.farePassengers;
        farePremium = other.farePremium;

        source = new char[strlen(other.source) + 1];
        strcpy(source, other.source);

        destination = new char[strlen(other.destination) + 1];
        strcpy(destination, other.destination);
    }
    return *this;
}

// Destructor
Booking::~Booking() {
    if (source != nullptr) delete[] source;
    if (destination != nullptr) delete[] destination;
}

// Setters
void Booking::setSource(const char* src) {
    if (source != nullptr) delete[] source;
    source = new char[strlen(src) + 1];
    strcpy(source, src);
}

void Booking::setDestination(const char* dest) {
    if (destination != nullptr) delete[] destination;
    destination = new char[strlen(dest) + 1];
    strcpy(destination, dest);
}

// Overloaded calculateFare implementation
// 1. Distance only (rs10 / km base rate)
double Booking::calculateFare(double dist) {
    return dist * 10.0;
}

// 2. Distance + Vehicle type (Multiplier based on class)
double Booking::calculateFare(double dist, int vehicleType) {
    double base = calculateFare(dist);
    double multiplier = 1.0;
    if (vehicleType == 2) multiplier = 1.5;      // Sedan
    else if (vehicleType == 3) multiplier = 2.0; // SUV
    return base * multiplier;
}

// 3. Distance + Vehicle type + Passengers (Flat rs5 extra per passenger)
double Booking::calculateFare(double dist, int vehicleType, int passengers) {
    double baseVehicleFare = calculateFare(dist, vehicleType);
    return baseVehicleFare + (passengers * 5.0);
}

// 4. Premium Booking (Distance + Vehicle + Passengers + Premium service charge)
double Booking::calculateFare(double dist, int vehicleType, int passengers, double serviceCharge) {
    double fareWithPassengers = calculateFare(dist, vehicleType, passengers);
    return fareWithPassengers + serviceCharge;
}

void Booking::acceptBooking() {
    char tempSrc[MAX_STR_LEN];
    char tempDest[MAX_STR_LEN];
    int vehicleType, passengers;
    double serviceCharge;

    cout << "Enter Source: ";
    cin.getline(tempSrc, MAX_STR_LEN);
    setSource(tempSrc);

    cout << "Enter Destination: ";
    cin.getline(tempDest, MAX_STR_LEN);
    setDestination(tempDest);

    cout << "Enter Distance (in km): ";
    cin >> distance;

    cout << "Enter Vehicle Type (1: Economy, 2: Sedan, 3: SUV): ";
    cin >> vehicleType;

    cout << "Enter Number of Passengers: ";
    cin >> passengers;

    cout << "Enter Premium Service Charge: ";
    cin >> serviceCharge;

    while (cin.get() != '\n'); // clear newline buffer

    // Execute overloaded calculations
    fareDistOnly = calculateFare(distance);
    fareVehicle = calculateFare(distance, vehicleType);
    farePassengers = calculateFare(distance, vehicleType, passengers);
    farePremium = calculateFare(distance, vehicleType, passengers, serviceCharge);

    // Final fare defaults to full premium pricing
    fare = farePremium;

    cout << "Booking ID " << bookingId << " Created.\n";
}

void Booking::displayBooking() const {
    cout << "\n--------------------------------------------";
    cout << "\nBooking ID        : " << bookingId;
    cout << "\nSource            : " << source;
    cout << "\nDestination       : " << destination;
    cout << "\nDistance (km)     : " << distance;
    cout << "\nFare (Dist Only)  : Rs" << fareDistOnly;
    cout << "\nFare (+Vehicle)   : Rs" << fareVehicle;
    cout << "\nFare (+Passengers): Rs" << farePassengers;
    cout << "\nTotal Premium Fare: Rs" << farePremium;
    cout << "\n--------------------------------------------\n";
}

// Operator Overloading
istream& operator>>(istream& in, Booking& b) {
    b.acceptBooking();
    return in;
}

ostream& operator<<(ostream& out, const Booking& b) {
    b.displayBooking();
    return out;
}
