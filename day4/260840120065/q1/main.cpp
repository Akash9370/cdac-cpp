#include<iostream>
#include"employee.h"
using namespace std;


int main(){
    Employee emp1, emp2;

    cout << "--- Employee 1 Data Entry ---\n";
    cin >> emp1; // Calls overloaded >>

    cout << "--- Employee 2 Data Entry ---\n";
    cin >> emp2; // Calls overloaded >>

    cout << "\n--- Displaying Employee Details ---";
    cout << emp1 << emp2; // Calls overloaded << sequentially

    return 0;
}

