#ifndef CURRENT_H
#define CURRENT_H
#include "Account.h"


class CurrentAcc: public Account{

    private:
    int transactionsPerDay;

    public:
    CurrentAcc();
    CurrentAcc(int id, const char* f, const char* l, const char* mob, const char* em, int p, double bal, int tpd);
    ~CurrentAcc() override{};


    const char* getType() const override { return "CURRENT"; }
    void acceptData() override;
    void display() const override;
    void updateDailyTransactionsLimit(int newLimit);



};


#endif