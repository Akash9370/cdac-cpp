#include<iostream>
#include"student.h"
using namespace std;
int main()
{



	// Testing Default Constructor
    student s1;
    cout << "Testing Default Constructor:";
    s1.display();

    // Testing Parameterized Constructor
    student s2(101, "Arin", 20, 85.5, 90.0, 78.0);
    cout << "\nTesting Parameterized Constructor:";
    s2.display();

    // Testing Setters and Getters
    cout << "\nModifying s1 using setter methods...\n";
    s1.setSid(102);
    s1.setSname("akash");
    s1.setAge(21);
    s1.setM1(92.0);
    s1.setM2(88.5);
    s1.setM3(95.0);

    cout << "Updated Name of s1  : " << s1.getSname() << "\n";
    s1.display();
    
    
    //calling object using pointer
    student* p=new student(77,"pointer",18,100,100,100);
    p->display();
    p->setSid(69);
    cout<<"after uploading sid from 77 to 69"<<endl;
    p->display();
    return 0;

}
