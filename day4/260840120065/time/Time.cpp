#include "Time.h"

// Constructor: Accepts hours and minutes, converts excess minutes into hours
Time::Time(int h, int m) {
    hrs = h + (m / 60);
    mins = m % 60;
    if (mins < 0) {
        mins += 60;
        hrs -= 1;
    }
}

// Copy Constructor
Time::Time(const Time &t) {
    hrs = t.hrs;
    mins = t.mins;
}

// Binary + Operator
Time Time::operator+(const Time &t) const {
    Time temp;
    temp.hrs = this->hrs + t.hrs;
    temp.mins = this->mins + t.mins;

    // Handle overflow (>= 60 mins)
    if (temp.mins >= 60) {
        temp.hrs += temp.mins / 60;
        temp.mins = temp.mins % 60;
    }
    return temp;
}

// Binary - Operator
Time Time::operator-(const Time& t) const {
    Time temp;
    temp.hrs = this->hrs - t.hrs;
    temp.mins = this->mins - t.mins;

   //
    if (temp.mins < 0) {
        int borrow = (-temp.mins + 59) / 60;
        temp.hrs -= borrow;
        temp.mins += borrow * 60;
    }
    return temp;
}

// Assignment Operator
Time& Time::operator=(const Time &t) {
    if (this != &t) {
        this->hrs = t.hrs;
        this->mins = t.mins;
    }
    return *this;
}

// Prefix Increment (++t)
Time& Time::operator++() {
    this->mins++;
    this->hrs++;
    if (this->mins >= 60) {
        this->hrs += this->mins / 60;
        this->mins = this->mins % 60;
    }
    return *this;
}

// Postfix Increment (t++)
Time Time::operator++(int) {
    Time temp = *this; // Save initial state
    this->mins++;
    this->hrs++;
    if (this->mins >= 60) {
        this->hrs += this->mins / 60;
        this->mins = this->mins % 60;
    }
    return temp;       // Return saved state
}

// Prefix Decrement (--t)
Time& Time::operator--() {
    this->mins--;
    this->hrs--;
    if (this->mins < 0) {
        this->hrs--;
        this->mins = 59;
    }
    return *this;
}

// Postfix Decrement (t--)
Time Time::operator--(int) {
    Time temp = *this; // Save initial state
    this->mins--;
    this->hrs--;
    if (this->mins < 0) {
        this->hrs--;
        this->mins = 59;
    }
    return temp;       // Return saved state
}

// Output Stream Operator <<
std::ostream& operator<<(std::ostream &out, const Time &t) {
    out << t.hrs << " hours " << t.mins << " minutes";
    return out;
}

// Input Stream Operator >>
std::istream& operator>>(std::istream &in, Time &t) {
    int h, m;
    std::cout << "Enter Hours: ";
    in >> h;
    std::cout << "Enter Minutes: ";
    in >> m;

    t.hrs = h + (m / 60);
    t.mins = m % 60;
    if (t.mins < 0) {
        t.mins += 60;
        t.hrs -= 1;
    }
    return in;
}
