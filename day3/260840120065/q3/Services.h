#ifndef SERVICES_H
#define SERVICES_H

#include "Friend.h"

class Services {
private:
    Friend* friendarr; 
    int size;          

public:
    Services(Friend* arr, int currentSize);

    void displayAllFriends() const;
    void searchById() const;
    void searchByName() const;
    void displayByHobby() const;
};

#endif
