#include "Friend.h"
#include "Services.h"
#include <iostream>

using namespace std;

const int MAX_FRIENDS = 50;

int main() {
    Friend friendArray[MAX_FRIENDS];
    int currentCount = 0;

    cout << "Enter the total number of friends you want to add initially (Max " << MAX_FRIENDS << "): ";
    cin >> currentCount;
    while (cin.get() != '\n'); 
    
    if (currentCount > MAX_FRIENDS) {
        currentCount = MAX_FRIENDS;
    }

    for (int i = 0; i < currentCount; ++i) {
        cout << "\n--- Entering Details for Friend " << (i + 1) << " ---";
        friendArray[i].acceptDetails();
    }

    Services appServices(friendArray, currentCount);

    int choice;
    do {
        cout << "\n===== FRIEND MANAGEMENT SYSTEM =====";
        cout << "\n1. Display All Friends";
        cout << "\n2. Search by ID";
        cout << "\n3. Search by Name";
        cout << "\n4. Display Friends with Particular Hobby";
        cout << "\n5. Exit";
        cout << "\nEnter your choice (1-5): ";
        cin >> choice;
        while (cin.get() != '\n'); 

        switch (choice) {
            case 1:
                appServices.displayAllFriends();
                break;
            case 2:
                appServices.searchById();
                break;
            case 3:
                appServices.searchByName();
                break;
            case 4:
                appServices.displayByHobby();
                break;
            case 5:
                cout << "\nExiting... Goodbye!\n";
                break;
            default:
                cout << "\nInvalid Choice! Please enter a valid menu option.\n";
        }
    } while (choice != 5);

    return 0;
}
