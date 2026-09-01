#ifndef TIME_H
#define TIME_H

#include <iostream>

class Time {
private:
    int hrs;
    int mins;

public:
    // Constructors
    Time(int h = 0, int m = 0);          // Default Parameterized Constructor
    Time(const Time &t);                 // Copy Constructor

    // Arithmetic Operators
    Time operator+(const Time &t) const;
    Time operator-(const Time &t) const;

    // Assignment Operator
    Time& operator=(const Time &t);

    // Increment Operators
    Time& operator++();    // Prefix ++
    Time operator++(int);  // Postfix ++

    // Decrement Operators
    Time& operator--();    // Prefix --
    Time operator--(int);  // Postfix --

    // Stream I/O Operators
    friend std::ostream& operator<<(std::ostream &out, const Time &t);
    friend std::istream& operator>>(std::istream &in, Time &t);
};

#endif // TIME_H
