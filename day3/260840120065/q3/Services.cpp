#include "Services.h"
#include <iostream>
#include <cstring>

using namespace std;

Services::Services(Friend* arr, int currentSize) {
    friendarr = arr;
    size = currentSize;
}

void Services::displayAllFriends() const {
    if (size == 0) {
        cout << "\nNo records found to display.\n";
        return;
    }
    cout << "\n======= ALL FRIENDS DETAILS =======";
    for (int i = 0; i < size; ++i) {
        friendarr[i].displayDetails();
    }
}

void Services::searchById() const {
    int searchId;
    cout << "\nEnter ID to search: ";
    cin >> searchId;
    while (cin.get() != '\n'); 
    
    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (friendarr[i].getId() == searchId) {
            cout << "\nFriend Found!";
            friendarr[i].displayDetails();
            found = true;
            break; 
        }
    }
    if (!found) {
        cout << "\nFriend with ID " << searchId << " not found.\n";
    }
}

void Services::searchByName() const {
    char searchName[MAX_STR_LEN];
    cout << "\nEnter Name to search: ";
    cin.getline(searchName, MAX_STR_LEN);

    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (strcmp(friendarr[i].getName(), searchName) == 0) {
            cout << "\nFriend Found!";
            friendarr[i].displayDetails();
            found = true;
        }
    }
    if (!found) {
        cout << "\nFriend with Name \"" << searchName << "\" not found.\n";
    }
}

void Services::displayByHobby() const {
    char searchHobby[MAX_STR_LEN];
    cout << "\nEnter Hobby to search: ";
    cin.getline(searchHobby, MAX_STR_LEN);

    bool found = false;
    cout << "\nFriends who like \"" << searchHobby << "\":";
    for (int i = 0; i < size; ++i) {
        if (friendarr[i].checkHobby(searchHobby)) { // Uses checkHobby seamlessly
            friendarr[i].displayDetails();
            found = true;
        }
    }
    if (!found) {
        cout << "\nNo friends found with hobby \"" << searchHobby << "\".\n";
    }
}
