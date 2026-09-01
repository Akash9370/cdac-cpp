#include <iostream>
#include <cstring>
#include <limits>
#include "Saving.h"

SavingsAccount::SavingsAccount() {
    chequebookNumber = nullptr;
    interestRate = 4.0;
    minBalance = 20000.0;
}

SavingsAccount::SavingsAccount(int id, const char* f, const char* l, const char* mob, const char* em, int p, double bal, const char* chqNo) {
    accountId = id;
    pin = p;
    balance = bal;
    interestRate = 4.0;
    minBalance = 20000.0;

    fname = new char[strlen(f) + 1];
    strcpy(fname, f);

    lname = new char[strlen(l) + 1];
    strcpy(lname, l);

    mobile = new char[strlen(mob) + 1];
    strcpy(mobile, mob);

    email = new char[strlen(em) + 1];
    strcpy(email, em);

    chequebookNumber = new char[strlen(chqNo) + 1];
    strcpy(chequebookNumber, chqNo);
}

SavingsAccount::~SavingsAccount() {
    delete[] chequebookNumber;
}

void SavingsAccount::acceptData() {
    Account::acceptData();
    char chq[50];
    std::cout << "Enter Chequebook Number: ";
    std::cin >> chq;

    delete[] chequebookNumber;
    chequebookNumber = new char[strlen(chq) + 1];
    strcpy(chequebookNumber, chq);
}

void SavingsAccount::display() const {
    std::cout << "\n--- SAVINGS ACCOUNT DETAILS ---\n";
    Account::display();
    std::cout << "Chequebook Number: " << (chequebookNumber ? chequebookNumber : "N/A") << "\n";
}