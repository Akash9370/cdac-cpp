#include <iostream>
#include <cstring>
#include <limits>
#include "Account.h"
#include "Saving.h"
#include "current.h"
#include "demat.h"

using namespace std;

const int MAX_ACCOUNTS = 100;

// Helper function to locate an account by ID
Account* findAccount(Account* bank[], int total, int id) {
    for (int i = 0; i < total; ++i) {
        if (bank[i] != nullptr && bank[i]->getAccountId() == id) {
            return bank[i];
        }
    }
    return nullptr;
}

int main() {
    Account* bank[MAX_ACCOUNTS] = {nullptr};
    int totalAccounts = 0;
    int choice = 0;
    int nextId = 1001;

    do {
        cout << "\n================ XYZ BANK SYSTEM MENU ================\n";
        cout << "1. Add New Account\n";
        cout << "2. Display Account Balance by ID\n";
        cout << "3. Close Account\n";
        cout << "4. Count Type of Account\n";
        cout << "5. Withdraw Amount\n";
        cout << "6. Deposit Amount\n";
        cout << "7. Change PIN\n";
        cout << "0. Exit\n";
        cout << "Select Option: ";
        
        while (!(cin >> choice)) {
            cout << "Invalid menu choice! Enter a number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch (choice) {
            case 1: {
                if (totalAccounts >= MAX_ACCOUNTS) {
                    cout << "Bank account storage limit reached.\n";
                    break;
                }

                int typeChoice;
                cout << "Select Type (1. Savings, 2. Current, 3. Demat): ";
                cin >> typeChoice;

                if (typeChoice < 1 || typeChoice > 3) {
                    cout << "Invalid Account Type selected.\n";
                    break;
                }

                char f[50], l[50], mob[20], em[50];
                int pin;
                double bal;

                cout << "Enter First Name: "; cin >> f;
                cout << "Enter Last Name: "; cin >> l;
                cout << "Enter Mobile: "; cin >> mob;
                cout << "Enter Email: "; cin >> em;
                cout << "Set 4-digit PIN: "; cin >> pin;
                cout << "Enter Initial Deposit: "; cin >> bal;

                Account* tempAcc = nullptr;

                if (typeChoice == 1) { // Savings Account
                    if (bal < 20000.0) {
                        cout << "Creation failed! Savings Account requires a minimum deposit of 20000.\n";
                        break;
                    }
                    char chq[50];
                    cout << "Enter Chequebook Number: "; cin >> chq;
                    tempAcc = new SavingsAccount(nextId++, f, l, mob, em, pin, bal, chq);

                } else if (typeChoice == 2) { // Current Account
                    if (bal < 1000.0) {
                        cout << "Creation failed! Current Account requires a minimum deposit of 1000.\n";
                        break;
                    }
                    int tpd;
                    cout << "Enter allowed transactions per day: "; cin >> tpd;
                    tempAcc = new CurrentAcc(nextId++, f, l, mob, em, pin, bal, tpd);

                } else if (typeChoice == 3) { // Demat Account
                    tempAcc = new DematAccount(nextId++, f, l, mob, em, pin, bal);
                    
                    char addShareChoice;
                    cout << "Add share details now? (y/n): ";
                    cin >> addShareChoice;

                    if (addShareChoice == 'y' || addShareChoice == 'Y') {
                        Share s;
                        char sName[50], bDate[20], sDate[20];
                        int qty;
                        double bp, sp;

                        cout << "Share Name: "; cin >> sName;
                        cout << "Quantity: "; cin >> qty;
                        cout << "Buy Price: "; cin >> bp;
                        cout << "Buy Date (YYYY-MM-DD): "; cin >> bDate;
                        cout << "Sell Price: "; cin >> sp;
                        cout << "Sell Date (YYYY-MM-DD): "; cin >> sDate;

                        s.setDetails(sName, qty, bp, bDate, sp, sDate);
                        dynamic_cast<DematAccount*>(tempAcc)->addShare(s);
                    }
                }

                bank[totalAccounts++] = tempAcc;
                cout << "\nAccount created successfully! Assigned Account ID: " << tempAcc->getAccountId() << "\n";
                break;
            }
            case 2: {
                int id;
                cout << "Enter Account ID: "; 
                cin >> id;
                Account* acc = findAccount(bank, totalAccounts, id);
                if (acc) {
                    cout << "\nCurrent Balance for Account ID " << id << " is: ₹" << acc->getBalance() << "\n";
                    acc->display();
                } else {
                    cout << "Account not found.\n";
                }
                break;
            }
            case 3: {
                int id;
                cout << "Enter Account ID to Close: "; 
                cin >> id;
                int foundIndex = -1;

                for (int i = 0; i < totalAccounts; ++i) {
                    if (bank[i] != nullptr && bank[i]->getAccountId() == id) {
                        foundIndex = i;
                        break;
                    }
                }

                if (foundIndex != -1) {
                    delete bank[foundIndex];
                    for (int i = foundIndex; i < totalAccounts - 1; ++i) {
                        bank[i] = bank[i + 1];
                    }
                    bank[--totalAccounts] = nullptr;
                    cout << "Account " << id << " closed successfully.\n";
                } else {
                    cout << "Account not found.\n";
                }
                break;
            }
            case 4: {
                int typeChoice;
                cout << "Select Type to Count (1. Savings, 2. Current, 3. Demat): ";
                cin >> typeChoice;

                int count = 0;
                for (int i = 0; i < totalAccounts; ++i) {
                    if (bank[i] != nullptr) {
                        if (typeChoice == 1 && dynamic_cast<SavingsAccount*>(bank[i]) != nullptr) {
                            count++;
                        } else if (typeChoice == 2 && dynamic_cast<CurrentAcc*>(bank[i]) != nullptr) {
                            count++;
                        } else if (typeChoice == 3 && dynamic_cast<DematAccount*>(bank[i]) != nullptr) {
                            count++;
                        }
                    }
                }

                const char* typeName = (typeChoice == 1) ? "SAVINGS" : (typeChoice == 2) ? "CURRENT" : (typeChoice == 3) ? "DEMAT" : "UNKNOWN";
                cout << "Total " << typeName << " accounts active: " << count << "\n";
                break;
            }
            case 5: {
                int id, inputPin;
                double amt;
                cout << "Enter Account ID: "; cin >> id;
                Account* acc = findAccount(bank, totalAccounts, id);
                if (acc) {
                    cout << "Enter PIN: "; cin >> inputPin;
                    cout << "Enter Amount to Withdraw: "; cin >> amt;
                    acc->withdraw(amt, inputPin);
                } else {
                    cout << "Account not found.\n";
                }
                break;
            }
            case 6: {
                int id;
                double amt;
                cout << "Enter Account ID: "; cin >> id;
                Account* acc = findAccount(bank, totalAccounts, id);
                if (acc) {
                    cout << "Enter Amount to Deposit: "; cin >> amt;
                    acc->deposit(amt);
                } else {
                    cout << "Account not found.\n";
                }
                break;
            }
            case 7: {
                int id, oldPin, newPin;
                cout << "Enter Account ID: "; cin >> id;
                Account* acc = findAccount(bank, totalAccounts, id);
                if (acc) {
                    cout << "Enter Old PIN: "; cin >> oldPin;
                    if (acc->validatePin(oldPin)) {
                        cout << "Enter New PIN: "; cin >> newPin;
                        acc->setPin(newPin);
                        cout << "PIN updated successfully.\n";
                    } else {
                        cout << "Incorrect PIN.\n";
                    }
                } else {
                    cout << "Account not found.\n";
                }
                break;
            }
            case 0:
                cout << "Exiting system. Cleaning allocated memory...\n";
                for (int i = 0; i < totalAccounts; ++i) {
                    delete bank[i];
                    bank[i] = nullptr;
                }
                totalAccounts = 0;
                break;
            default:
                cout << "Invalid menu choice.\n";
        }
    } while (choice != 0);

    return 0;
}