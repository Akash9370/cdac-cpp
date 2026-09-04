#include <iostream>
#include <cstring>
#include <string>
#include "Person.h"
#include "Address.h"

using namespace std;

int main() {
    static Person* parr[100];
    int count = 0;
    int choice;

    do {
        cout << "\nEnter your choice:\n"
             << "1. Add new Person\n"
             << "2. Display All Persons\n"
             << "3. Search by Id\n"
             << "4. Search by Name\n"
             << "5. Modify address\n"
             << "6. Find address by id of Person\n"
             << "7. Display all Persons staying in given city\n"
             << "0. Exit\n"
             << "Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                char name[100], street[100], city[100], state[100];
                int pin;

                cin.ignore(); // Clear buffer before reading line inputs
                cout << "Enter name: ";
                cin.getline(name, 100);
                cout << "Enter street: ";
                cin.getline(street, 100);
                cout << "Enter city: ";
                cin.getline(city, 100);
                cout << "Enter state: ";
                cin.getline(state, 100);
                cout << "Enter pin: ";
                cin >> pin;

                parr[count] = new Person(name, street, city, state, pin);
                count++;
                break;
            }
            case 2: {
                for (int j = 0; j < count; j++) {
                    parr[j]->displayPerson();
                }
                break;
            }
            case 3: {
                int searchId;
                cout << "Enter ID to search: ";
                cin >> searchId;
                for (int j = 0; j < count; j++) {
                    if (parr[j]->getId() == searchId) {
                        parr[j]->displayPerson();
                    }
                }
                break;
            }
            case 4: {
                char searchName[100];
                cin.ignore();
                cout << "Enter name to search: ";
                cin.getline(searchName, 100);
                for (int j = 0; j < count; j++) {
                    if (strcasecmp(parr[j]->getName(), searchName) == 0) {
                        parr[j]->displayPerson();
                    }
                }
                break;
            }
            case 5: {
                int searchID;
                cout << "Enter ID to modify address: ";
                cin >> searchID;
                for (int j = 0; j < count; j++) {
                    if (parr[j]->getId() == searchID) {
                        char newStreet[100], newCity[100], newState[100];
                        int newPin;
                        cin.ignore();
                        cout << "Enter new street: ";
                        cin.getline(newStreet, 100);
                        cout << "Enter new city: ";
                        cin.getline(newCity, 100);
                        cout << "Enter new state: ";
                        cin.getline(newState, 100);
                        cout << "Enter new pin: ";
                        cin >> newPin;

                        parr[j]->modifyaddress(newStreet, newCity, newState, newPin);
                    }
                }
                break;
            }
            case 6: {
                int searchID;
                cout << "Enter ID to find address: ";
                cin >> searchID;
                for (int j = 0; j < count; j++) {
                    if (parr[j]->getId() == searchID) {
                        parr[j]->displayPerson(); // Ensure displayPerson prints address details
                    }
                }
                break;
            }
            case 7: {
                char searchCity[100];
                cin.ignore();
                cout << "Enter city to search: ";
                cin.getline(searchCity, 100);
                for (int j = 0; j < count; j++) {
                    
                    if (strcasecmp(parr[j]->getCity(), searchCity) == 0) {
                        parr[j]->displayPerson();
                    }
                }
                break;
            }
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 0);

    
    for (int j = 0; j < count; j++) {
        delete parr[j];
    }
    return 0;
}