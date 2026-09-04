#ifndef PERSON_H
#define PERSON_H
#include<cstring>
#include "Address.h"
class Person{
   static int idCounter;	//static variable to generate unique id for each person (dont initialize it in header file, initialize it in cpp file)
   int id;
   char *name;
   Address addr;	//object of address class (HAS-A relationship)

   public:
    Person();
    Person( char* name, char* street, char* city, char* state, int pin);
    ~Person();

    void displayPerson();


    //getters

    int getId();
    char* getName();
    char* getCity();


    void modifyaddress(char* street, char* city, char* state, int pin);
    
    int generateId();
};




#endif