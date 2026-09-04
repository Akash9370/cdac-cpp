#ifndef CURRENT_H
#define CURRENT_H
#include "Account.h"


class CurrentAcc: public Account{

    private:
    int transactionsPerDay;

    public:
    CurrentAcc();
    // current.h
    CurrentAcc(int id, const char* f, const char* l, const char* mob, const char* em, int p, double bal, int tpd, double ir = 1.0, double minBal = MIN_BAL_current);
    ~CurrentAcc() override{};


    const char* getType() const override { return "CURRENT"; }
    void acceptData() override;
    void display() const override;
    void updateDailyTransactionsLimit(int newLimit);
    static constexpr double MIN_BAL_current = 1000.0;
    



};


#endif