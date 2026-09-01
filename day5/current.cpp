#include"current.h"
#include<iostream>
#include<cstring>
#include <limits>

CurrentAcc::CurrentAcc() {
    interestRate = 1.0;
    minBalance = 1000.0;
}

CurrentAcc::CurrentAcc(int id, const char* f, const char* l, const char* mob, const char* em, int p, double bal, int tpd) {
    accountId = id;
    pin = p;
    balance = bal;
    interestRate = 1.0;
    minBalance = 1000.0;
    transactionsPerDay = tpd;

    fname = new char[strlen(f) + 1];
    strcpy(fname, f);

    lname = new char[strlen(l) + 1];
    strcpy(lname, l);

    mobile = new char[strlen(mob) + 1];
    strcpy(mobile, mob);

    email = new char[strlen(em) + 1];
    strcpy(email, em);

}

void CurrentAcc::acceptData() {
    Account::acceptData();
    char chq[50];

    std::cout<< "Enter number of transaction aloowed per day ";
    std::cin.clear();
    std::cin.ignore();
    std::cin >> transactionsPerDay;
    
   

}


void CurrentAcc::updateDailyTransactionsLimit(int newLimit) {
    transactionsPerDay = newLimit;
}


void CurrentAcc::display() const {
    std::cout << "\n--- CURRENT ACCOUNT DETAILS ---\n";
    Account::display();
    std::cout << "Allowed Transactions/Day: " << transactionsPerDay << "\n";
}