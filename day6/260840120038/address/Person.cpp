#include<iostream>
#include "Address.h"
#include "Person.h"
#include<cstring>
using namespace std;


int Person::idCounter=999;

Person::Person() {
    id = generateId();
    name = new char[100];
}
int Person::generateId() {
    return ++idCounter;
}
Person::Person( char* name, char* street, char* city, char* state, int pin) :id(generateId()) ,addr(street, city, state, pin){
    
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    // addr = Address(street, city, state, pin); // Creating Address object
    
}

Person::~Person() {
    delete[] name;
}

void Person::displayPerson() {
    cout << "ID: " << id << endl;
    cout << "Name: " << name << endl;
    addr.DisplayAddress();
}

void Person::modifyaddress(char* street, char* city, char* state, int pin) {
    addr.ModifyAddress(street, city, state, pin);
}

int Person::getId() {
    return id;
}

char* Person::getName() {
    return name;
}


char* Person::getCity() {
    return addr.getCity(); 
}
