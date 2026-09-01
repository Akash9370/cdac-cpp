#include "Friend.h"
#include <iostream>
#include <cstring>

using namespace std;

// Initialize the static ID counter
int Friend::idCounter = 1;

Friend::Friend() {
    id = idCounter;
    idCounter++;

    hobbieCount = 0;
    hobbies = nullptr;
    
    mobileCount = 0;
    mobiles = nullptr;
    
    mail = nullptr;

    name[0] = '\0';
    bday[0] = '\0';
}

Friend::~Friend() {
    if (hobbies != nullptr) {
        for (int i = 0; i < hobbieCount; ++i) {
            delete[] hobbies[i];
        }
        delete[] hobbies;
    }
    if (mobiles != nullptr) {
        for (int i = 0; i < mobileCount; ++i) {
            delete[] mobiles[i];
        }
        delete[] mobiles;
    }
    if (mail != nullptr) {
        delete[] mail;
    }
}

void Friend::acceptDetails() {
    if (mail != nullptr) {
        delete[] mail;
        mail = nullptr;
    }

    cout << "Enter Name: ";
    cin.getline(name, MAX_STR_LEN);

    cout << "How many hobbies does this friend have? ";
    cin >> hobbieCount;
    while (cin.get() != '\n'); 

    if (hobbieCount > 0) {
        hobbies = new char*[hobbieCoun double calcSal();
t];
        for (int i = 0; i < hobbieCount; ++i) {
            char tempHobby[MAX_STR_LEN];
            cout << "  Enter hobby " << (i + 1) << ": ";
            cin.getline(tempHobby, MAX_STR_LEN);
            
            hobbies[i] = new char[strlen(tempHobby) + 1];
            strcpy(hobbies[i], tempHobby);
        }
    }

    cout << "How many mobile numbers does this friend have? ";
    cin >> mobileCount;
    while (cin.get() != '\n'); 

    if (mobileCount > 0) {
        mobiles = new char*[mobileCount];
        for (int i = 0; i < mobileCount; ++i) {
            char tempMob[30];
            cout << "  Enter mobile number " << (i + 1) << ": ";
            cin.getline(tempMob, 30);
            
            mobiles[i] = new char[strlen(tempMob) + 1];
            strcpy(mobiles[i], tempMob);
        }
    }

    char tempMail[MAX_STR_LEN];
    cout << "Enter Email: ";
    cin.getline(tempMail, MAX_STR_LEN);
    mail = new char[strlen(tempMail) + 1];
    strcpy(mail, tempMail);

    cout << "Enter Birthdate (DD/MM/YYYY): ";
    cin.getline(bday, 20);
}

void Friend::displayDetails() const {
    cout << "\n--------------------------------------------";
    cout << "\nID            : " << id;
    cout << "\nName          : " << name;
    
    cout << "\nHobbies       : ";
    if (hobbieCount == 0) cout << "None";
    for (int i = 0; i < hobbieCount; ++i) {
        cout << hobbies[i] << (i + 1 < hobbieCount ? ", " : "");
    }

    cout << "\nMobile No(s)  : ";
    if (mobileCount == 0) cout << "None";
    for (int i = 0; i < mobileCount; ++i) {
        cout << mobiles[i] << (i + 1 < mobileCount ? ", " : "");
    }

    cout << "\nEmail         : " << (mail != nullptr ? mail : "None");
    cout << "\nBirthdate     : " << bday;
    cout << "\n--------------------------------------------\n";
}

int Friend::getId() const { return id; }
const char* Friend::getName() const { return name; }

bool Friend::checkHobby(const char* hobby) const {
    for (int i = 0; i < hobbieCount; ++i) {
        if (strcmp(hobbies[i], hobby) == 0) return true;
    }
    return false;
}
