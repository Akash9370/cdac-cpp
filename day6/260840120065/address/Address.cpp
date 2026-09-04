#include<iostream>
#include "Address.h"
#include<cstring>

using namespace std;

Address::Address(){
    street = new char[100];
    city = new char[100];
    state = new char[100];
    pin = 0;
}

Address::Address(char* street1, char* city1, char* state1, int pin1){

    cout<<street1;
    street = new char[strlen(street1) + 1];
    strcpy(street, street1);
    cout<<"street val"<<street;
    
    city = new char[strlen(city1) + 1];
    strcpy(city, city1);
    
    state = new char[strlen(state1) + 1];
    strcpy(state, state1);
    
    this->pin = pin1;
}

Address::~Address(){
    delete[] street;
    delete[] city;
    delete[] state;
}

void Address::ModifyAddress(char* street, char* city, char* state, int pin){
    delete[] this->street;
    delete[] this->city;
    delete[] this->state;

    this->street = new char[strlen(street) + 1];
    strcpy(this->street, street);
    
    this->city = new char[strlen(city) + 1];
    strcpy(this->city, city);
    
    this->state = new char[strlen(state) + 1];
    strcpy(this->state, state);
    
    this->pin = pin;
}

void Address::DisplayAddress(){
    cout << "Street: " << street << endl;
    cout << "City: " << city << endl;
    cout << "State: " << state << endl;
    cout << "Pin: " << pin << endl;
}


char* Address::getCity(){
    return city;
}
