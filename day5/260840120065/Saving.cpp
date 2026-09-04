#include <iostream>
#include <cstring>
#include <limits>
#include "Saving.h"
#include <iostream>
#include <cstring>
#include <limits>
#include "Saving.h"

SavingsAccount::SavingsAccount()
    : Account(), chequebookNumber(nullptr) {
    interestRate = 4.0;
    minBalance = MIN_BAL_saving;
}

SavingsAccount::SavingsAccount(int id, const char* f, const char* l, const char* mob, const char* em, int p, double bal, const char* chqNo,double ir,double minBal  )
    : Account(id, f, l, mob, em, p, bal, ir, minBal) {
    minBalance = minBal;
    interestRate = ir;
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


