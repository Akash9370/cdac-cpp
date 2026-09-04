#ifndef SHAPE_H
#define SHAPE_H
#include<iostream>
using namespace std;
   class Shape{
   private:
      int id;
      char *color;
    public:
        Shape(char* c, int id);
        virtual ~Shape();
        virtual double calculateArea() const = 0;
        // double calculateArea(){
        //     cout << "In shape calculate area" << endl;
        //     return 0;
        // }
        int getId() const {
            return id;
        }
        virtual void display();
        virtual double calculatePerimeter() const = 0;
   };
#endif