#include "Account.h"
#include <iostream>
#include<cstring>
#include <limits>
using namespace std;


Account::Account(){

    accountId = 0;
    fname = NULL;
    lname = NULL;
    mobile = NULL;
    email = NULL;
    pin = 0;
    balance = 0.0;
    interestRate = 0.0;
    minBalance = 0.0;
}


Account::Account(int id, const char* f, const char* l, const char* mob, const char* em, int p, double bal, double ir, double minB) {
    accountId = id;
    pin = p;
    balance = bal;
    interestRate = ir;
    minBalance = minB;

    fname = new char[strlen(f) + 1];
    strcpy(fname, f);

    lname = new char[strlen(l) + 1];
    strcpy(lname, l);

    mobile = new char[strlen(mob) + 1];
    strcpy(mobile, mob);

    email = new char[strlen(em) + 1];
    strcpy(email, em);
}



Account::~Account() {
    delete[] fname;
    delete[] lname;
    delete[] mobile;
    delete[] email;
}

void Account::acceptData() {
    char temp[100];

    std::cout << "Enter First Name: ";
    std::cin >> temp;
    delete[] fname;
    fname = new char[strlen(temp) + 1];
    strcpy(fname, temp);

    std::cout << "Enter Last Name: ";
    std::cin >> temp;
    delete[] lname;
    lname = new char[strlen(temp) + 1];
    strcpy(lname, temp);

    std::cout << "Enter Mobile: ";
    std::cin >> temp;
    delete[] mobile;
    mobile = new char[strlen(temp) + 1];
    strcpy(mobile, temp);

    std::cout << "Enter Email: ";
    std::cin >> temp;
    delete[] email;
    email = new char[strlen(temp) + 1];
    strcpy(email, temp);

    std::cout << "Set 4-digit PIN: ";
    std::cin >> pin;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Enter Initial Deposit: ";
    std::cin >> balance;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}


int Account::getAccountId() const { return accountId; }
int Account::getPin() const { return pin; }
double Account::getBalance() const { return balance; }



bool Account::validatePin(int inputPin) const {
    return pin == inputPin;
}

void Account::setPin(int newPin) {
    pin = newPin;
}

void Account::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        std::cout << "Deposit successful. Updated Balance: " << balance << "\n";
    } else {
        std::cout << "Invalid deposit amount.\n";
    }
}

bool Account::withdraw(double amount, int inputPin) {
    if (!validatePin(inputPin)) {
        std::cout << "Error: Incorrect PIN.\n";
        return false;
    }
    if (balance - amount < minBalance) {
        std::cout << "Error: Transaction declined. Minimum balance constraint (" << minBalance << ") violated.\n";
        return false;
    }
    balance -= amount;
    std::cout << "Withdrawal successful. Remaining Balance: " << balance << "\n";
    return true;
}

void Account::display() const {
    std::cout << "Account ID: " << accountId << "\n"
              << "Name: " << (fname ? fname : "") << " " << (lname ? lname : "") << "\n"
              << "Mobile: " << (mobile ? mobile : "") << " | Email: " << (email ? email : "") << "\n"
              << "Balance: " << balance << " | Interest Rate: " << interestRate << "%\n"
              << "Minimum Balance Requirement: " << minBalance << "\n";
}