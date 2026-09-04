#include <iostream>
#include <cstring>
#include "demat.h"

Share::Share() {
    name = nullptr;
    quantity = 0;
    buyPrice = 0.0;
    buyDate = nullptr;
    sellPrice = 0.0;
    sellDate = nullptr;
}

void Share::setDetails(const char* n, int qty, double bp, const char* bd, double sp, const char* sd) {
    delete[] name;
    name = new char[strlen(n) + 1];
    strcpy(name, n);

    quantity = qty;
    buyPrice = bp;

    delete[] buyDate;
    buyDate = new char[strlen(bd) + 1];
    strcpy(buyDate, bd);

    sellPrice = sp;

    delete[] sellDate;
    sellDate = new char[strlen(sd) + 1];
    strcpy(sellDate, sd);
}

Share::~Share() {
    delete[] name;
    delete[] buyDate;
    delete[] sellDate;
}

DematAccount::DematAccount() {
    interestRate = 0.0;
    minBalance = 0.0;
    shareCount = 0;
    capacity = 10;
    shares = new Share[capacity];
}

DematAccount::DematAccount(int id, const char* f, const char* l, const char* mob, const char* em, int p, double bal) {
    accountId = id;
    pin = p;
    balance = bal;
    interestRate = 0.0;
    minBalance = 0.0;
    shareCount = 0;
    capacity = 10;

    fname = new char[strlen(f) + 1];
    strcpy(fname, f);

    lname = new char[strlen(l) + 1];
    strcpy(lname, l);

    mobile = new char[strlen(mob) + 1];
    strcpy(mobile, mob);

    email = new char[strlen(em) + 1];
    strcpy(email, em);

    shares = new Share[capacity];
}

DematAccount::~DematAccount() {
    delete[] shares;
}

void DematAccount::acceptData() {
    Account::acceptData();

    char addShareChoice;
    std::cout << "Add share details now? (y/n): ";
    std::cin >> addShareChoice;

    if (addShareChoice == 'y' || addShareChoice == 'Y') {
        Share s;
        char sName[50], bDate[20], sDate[20];
        int qty;
        double bp, sp;

        std::cout << "Share Name: "; std::cin >> sName;
        std::cout << "Quantity: "; std::cin >> qty;
        std::cout << "Buy Price: "; std::cin >> bp;
        std::cout << "Buy Date (YYYY-MM-DD): "; std::cin >> bDate;
        std::cout << "Sell Price: "; std::cin >> sp;
        std::cout << "Sell Date (YYYY-MM-DD): "; std::cin >> sDate;

        s.setDetails(sName, qty, bp, bDate, sp, sDate);
        addShare(s);
    }
}

void DematAccount::addShare(const Share& s) {
    if (shareCount < capacity) {
        shares[shareCount].setDetails(s.name, s.quantity, s.buyPrice, s.buyDate, s.sellPrice, s.sellDate);
        shareCount++;
    } else {
        std::cout << "Share storage limit reached for this account.\n";
    }
}

void DematAccount::display() const {
    std::cout << "\n--- DEMAT ACCOUNT DETAILS ---\n";
    Account::display();
    std::cout << "Holdings/Shares Portfolio:\n";
    if (shareCount == 0) {
        std::cout << "  No active holdings linked to this account.\n";
    } else {
        for (int i = 0; i < shareCount; ++i) {
            std::cout << "  [" << (i + 1) << "] Share: " << shares[i].name 
                      << " | Qty: " << shares[i].quantity 
                      << " | Buy Price: " << shares[i].buyPrice 
                      << " | Buy Date: " << shares[i].buyDate 
                      << " | Sell Price: " << shares[i].sellPrice 
                      << " | Sell Date: " << shares[i].sellDate << "\n";
        }
    }
}