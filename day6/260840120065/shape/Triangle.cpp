#include "Triangle.h"
#include <iostream>

using namespace std;
Triangle::Triangle(int id, char*c , double s1, double s2, double h,double b): Shape(c, id), s1(s1), s2(s2), h(h), b(b){    //to test (id,c)
    cout << "In Triangle constructor...." << endl;
    
// {
//     len = l;
//     br = b;
}
double Triangle::calculateArea() const {
    cout << "in triangle. calculate area" << endl;
  return 0.5 * this->b * this->h;
}
double Triangle::calculatePerimeter() const  {
  return this->s1 + this->s2 + this->b;
}

void Triangle::display(){
  Shape::display();
  cout << "side 1 : " << s1 
       << "side 2 : " << s2 
       << "base : " << b 
       << "height : " << h << endl;
  cout << "------------------" << endl;
}

Triangle::~Triangle(){
    cout << "in triangle destructor...." << endl;
}
    