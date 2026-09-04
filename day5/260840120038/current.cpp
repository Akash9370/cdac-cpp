#include"current.h"
#include<iostream>
#include<cstring>
#include <limits>

CurrentAcc::CurrentAcc() {
    interestRate = 1.0;
    minBalance = MIN_BAL_current;
}

    


CurrentAcc::CurrentAcc(int id, const char* f, const char* l, const char* mob, const char* em, int p, double bal, int tpd,double ir,double minBal) {
    accountId = id;
    pin = p;
    balance = bal;
    transactionsPerDay = tpd;
    minBalance = minBal;
    interestRate = ir;
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

