#ifndef SAVING_H
#define SAVING_H
#include "Account.h"


class SavingsAccount:public Account{

    private:
    char* chequebookNumber;

public:
    SavingsAccount();
    SavingsAccount(int id, const char* f, const char* l, const char* mob, const char* em, int p, double bal, const char* chqNo);
    ~SavingsAccount() override;
    
    const char* getType() const override { return "SAVINGS"; }
    void acceptData() override;
    void display() const override;



};


#endif