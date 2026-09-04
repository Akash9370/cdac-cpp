#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"

class Triangle :public Shape{
    double s1,s2,h,b;
    public:
        Triangle(int id, char* c, double s1, double s2, double h,double b);
        double calculateArea() const override;
        double calculatePerimeter() const override;
        void display();
        ~Triangle();
};

#endif