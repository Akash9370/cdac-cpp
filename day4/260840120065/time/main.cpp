#include <iostream>
#include "Time.h"

using namespace std;


// Function to test and demonstrate all 3 constructors
void demonstrateConstructors() {
    
    
    Time Default;                  // Default Constructor (0, 0)
    Time Param(10, 50);            // Parameterized Constructor (10 hrs, 50 mins)
    Time Copy(Param);             // Copy Constructor (Copies Param)

    cout << "Default Time (Default)      : " << Default << endl;
    cout << "Parameterized Time (Param)  : " << Param << endl;
    cout << "Copied Time (Copy)          : " << Copy << endl;
}

int main() {
    // Default working objects for interactive demonstration
    Time t1(10, 50);
    Time t2(2, 35);
    Time t3; // For storing operation results

    int choice;

    do {
        
 
        cout << "----------------------------------------" << endl;
        cout << " 1. Demonstrate All 3 Constructors" << endl;
        cout << " 2. Input/Set Values for t1 and t2 (using >>)" << endl;
        cout << " 3. Addition (t3 = t1 + t2)" << endl;
        cout << " 4. Subtraction (t3 = t1 - t2)" << endl;
        cout << " 5. Single Assignment (t3 = t1)" << endl;
        cout << " 6. Chained Assignment (t3 = t2 = t1)" << endl;
        cout << " 7. Prefix Increment (++t1)" << endl;
        cout << " 8. Postfix Increment (t3 = t1++)" << endl;
        cout << " 9. Prefix Decrement (--t1)" << endl;
        cout << " 10. Postfix Decrement (t3 = t1--)" << endl;
        cout << " 11. Display All Current Objects (using <<)" << endl;
        cout << " 0. Exit" << endl;
        cout << "----------------------------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                // Runs the requested constructor test logic
                demonstrateConstructors();
                break;
            }
            case 2: {
                
                cout << "--- Enter Time 1 (t1) ---" << endl;
                cin >> t1;
                cout << "\n--- Enter Time 2 (t2) ---" << endl;
                cin >> t2;
                cout << "\nUpdated Objects:\n  t1: " << t1 << "\n  t2: " << t2 << endl;
                break;
            }
            case 3: {
                
                t3 = t1 + t2;
                cout << "Result: " << t1 << " + " << t2 << "\n     => " << t3 << endl;
                break;
            }
            case 4: {
                
                t3 = t1 - t2;
                cout << "Result: " << t1 << " - " << t2 << "\n     => " << t3 << endl;
                break;
            }
            case 5: {
                
                cout << "Before: t3 = " << t3 << ", t1 = " << t1 << endl;
                t3 = t1;
                cout << "After (t3 = t1): t3 is now " << t3 << endl;
                break;
            }
            case 6: {
                
                cout << "Setting t1 = 5 hours 15 mins..." << endl;
                t1 = Time(5, 15);
                cout << "Before: t1 = " << t1 << " | t2 = " << t2 << " | t3 = " << t3 << endl;
                
                // Chained assignment test
                t3 = t2 = t1;
                cout << "\nAfter (t3 = t2 = t1):" << endl;
                cout << "  t1: " << t1 << "\n  t2: " << t2 << "\n  t3: " << t3 << endl;
                break;
            }
            case 7: {
                
                cout << "Original t1: " << t1 << endl;
                Time result = ++t1;
                cout << "After ++t1 execution:" << endl;
                cout << "  Updated t1    : " << t1 << endl;
                cout << "  Returned Value: " << result << endl;
                break;
            }
            case 8: {
                
                cout << "Original t1: " << t1 << endl;
                t3 = t1++;
                cout << "After t3 = t1++ execution:" << endl;
                cout << "  Updated t1       : " << t1 << " (Incremented)" << endl;
                cout << "  Returned t3 Value: " << t3 << " (Preserved Old Value)" << endl;
                break;
            }
            case 9: {
                
                cout << "Original t1: " << t1 << endl;
                Time result = --t1;
                cout << "After --t1 execution:" << endl;
                cout << "  Updated t1    : " << t1 << endl;
                cout << "  Returned Value: " << result << endl;
                break;
            }
            case 10: {
                
                cout << "Original t1: " << t1 << endl;
                t3 = t1--;
                cout << "After t3 = t1-- execution:" << endl;
                cout << "  Updated t1       : " << t1 << " (Decremented)" << endl;
                cout << "  Returned t3 Value: " << t3 << " (Preserved Old Value)" << endl;
                break;
            }
            case 11: {
                
                cout << "t1 = " << t1 << endl;
                cout << "t2 = " << t2 << endl;
                cout << "t3 = " << t3 << endl;
                break;
            }
            case 0:
                cout << "\nExiting Program... Goodbye!" << endl;
                break;
            default:
                cout << "\n[ERROR] Invalid Choice! Please enter a number between 0 and 11." << endl;
                break;
        }

    } while (choice != 0);

    return 0;
}
