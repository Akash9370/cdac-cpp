#ifndef DEMAT_H
#define DEMAT_H

#include "Account.h"

struct Share {
    char* name;
    int quantity;
    double buyPrice;
    char* buyDate;
    double sellPrice;
    char* sellDate;

    Share();
    void setDetails(const char* n, int qty, double bp, const char* bd, double sp, const char* sd);
    ~Share();
};

class DematAccount : public Account {
private:
    Share* shares;
    int shareCount;
    int capacity;

public:
    DematAccount();
    DematAccount(int id, const char* f, const char* l, const char* mob, const char* em, int p, double bal);
    ~DematAccount() override;

    const char* getType() const override { return "DEMAT"; }
    void acceptData() override;
    void addShare(const Share& s);
    void display() const override;
};

#endif