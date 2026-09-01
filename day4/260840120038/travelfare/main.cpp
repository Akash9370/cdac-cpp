#include <iostream>
#include "booking.h"

using namespace std;

int main() {
    Booking b1, b2;

    cout << "--- Booking 1 Entry ---\n";
    cin >> b1; // Calls overloaded >>

    cout << "\n--- Booking 2 Entry ---\n";
    cin >> b2; // Calls overloaded >>

    cout << "\n--- Displaying Booking Details ---";
    cout << b1 << b2; // Calls overloaded << sequentially

    return 0;
}
