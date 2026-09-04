#ifndef ADDRESS_H
#define ADDRESS_H


class Address{
   
         private:
            char * street;  //char street[100]
            char* city;
            char* state;
            int pin;
          
         public:
            
            Address();
            Address(char* street, char* city, char* state, int pin);
            
            ~Address();
             void ModifyAddress(char* street, char* city, char* state, int pin);
             void DisplayAddress();
             char* getCity();

              







};



#endif