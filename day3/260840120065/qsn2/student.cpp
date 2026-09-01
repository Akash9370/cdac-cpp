#include<iostream>
#include<string>
#include"student.h"
#include <cstring>

using namespace std;

		//default constructor
		student::student() {
			cout<<"this is a default constructor"<<endl;
        sid = 0;
        sname = "";
        age = 0;
        m1 = 0.0;
        m2 = 0.0;
        m3 = 0.0;
    }
     
	    //  Parameterized Constructor
              student::student(int id, string name, int a, double mark1, double mark2, double mark3) {
		      cout<< " this is a parameterized constructor "<< endl;
        sid = id;
        
        sname=name;
        age = a;
        m1 = mark1;
        m2 = mark2;
        m3 = mark3;
    }
 // 		 Setters
    void student::setSid(int id) { sid = id; }
    void student::setSname(string name) { sname = name; }
    void student::setAge(int a) { age = a; }
    void student::setM1(double mark1) { m1 = mark1; }
    void student::setM2(double mark2) { m2 = mark2; }
    void student::setM3(double mark3) { m3 = mark3; }
    void student::setGpa(double gpaa) {gpa=gpaa;}



    // Getters
    int student::getSid() const { return sid; }
    string student::getSname() const { return sname; }
    int student::getAge() const { return age; }
    double student::getM1() const { return m1; }
    double student::getM2() const { return m2; }
    double student::getM3() const { return m3; }
    double student::getGpa() const { return gpa; }

    // Percentage
    double student::calculatePercentage(double m1,double m2,double m3) const {
        return (m1 + m2 + m3) / 3.0;
    }

    // Display
    void student::display() const {
        cout << "\n Student Details\n";
        cout << "Student ID : " << sid << "\n";
        cout << "Name       : " << sname << "\n";
        cout << "Age        : " << age << "\n";
        cout << "Marks      : Subject 1: " << m1 << ", Subject 2: " << m2 << ", Subject 3: " << m3 << "\n";
        cout << "Percentage : " << calculatePercentage(m1,m2,m3)<<endl<<endl;
    }










