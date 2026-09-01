#ifndef BOOKING_H
#define BOOKING_H

#include <iostream>

const int MAX_STR_LEN = 100;

class Booking {
private:
    static int idCounter;
    int bookingId;
    char* source;
    char* destination;
    double distance;
    double fare;

    // Overloaded fare storage for demonstration/display
    double fareDistOnly;
    double fareVehicle;
    double farePassengers;
    double farePremium;

public:
    // Constructors & Destructor
    Booking(const char* src = "Unknown", const char* dest = "Unknown", double dist = 0.0);
    Booking(const Booking& other);
    ~Booking();

    // Assignment Operator for Deep Copying
    Booking& operator=(const Booking& other);

    // ID Generator
    int generateID();

    // Overloaded Fare Calculation Methods
    double calculateFare(double dist);
    double calculateFare(double dist, int vehicleType); // 1: Economy, 2: Sedan, 3: SUV
    double calculateFare(double dist, int vehicleType, int passengers);
    double calculateFare(double dist, int vehicleType, int passengers, double serviceCharge);

    // Member helper functions for Stream Operators
    void acceptBooking();
    void displayBooking() const;

    // Getters
    int getBookingId() const { return bookingId; }
    const char* getSource() const { return source; }
    const char* getDestination() const { return destination; }
    double getDistance() const { return distance; }
    double getFare() const { return fare; }

    // Setters
    void setSource(const char* src);
    void setDestination(const char* dest);
    void setDistance(double dist) { distance = dist; }

    // Friend Stream Operators
    friend std::istream& operator>>(std::istream& in, Booking& b);
    friend std::ostream& operator<<(std::ostream& out, const Booking& b);
};

#endif
