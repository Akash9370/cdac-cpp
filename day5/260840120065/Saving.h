#ifndef SAVING_H
#define SAVING_H
#include "Account.h"


class SavingsAccount:public Account{

    private:
    char* chequebookNumber;

public:
    SavingsAccount();
    // Saving.h
SavingsAccount(int id, const char* f, const char* l, const char* mob, const char* em, int p, double bal, const char* chqNo, double ir = 4.0, double minBal = MIN_BAL_saving);
    ~SavingsAccount() override;
    
    const char* getType() const override { return "SAVINGS"; }
    void acceptData() override;
    void display() const override;
    static constexpr double MIN_BAL_saving = 20000.0;
    
    



};



#endif