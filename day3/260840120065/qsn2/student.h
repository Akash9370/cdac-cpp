#ifndef STUDENT_H
#define STUDENT_H
#include <string>
class student{
	private:
		int sid,age;
		double m1,m2,m3,gpa;
		std::string sname;
	
	public:
		//default constructor
		student();
     
	    //  Parameterized Constructor
              student(int id, std::string name, int a, double mark1, double mark2, double mark3)  ;
   
 // 		 Setters
    void setSid(int id) ;
    void setSname(std::string name) ;
    void setAge(int a) ;
    void setM1(double mark1) ;
    void setM2(double mark2) ;
    void setM3(double mark3) ;
    void setGpa(double gpa);




    // Getters
    int getSid() const ;
    std::string getSname() const;
    int getAge() const ;
    double getM1() const;
    double getM2() const;
    double getM3() const;
    double getGpa() const;

    // Percentage
    double calculatePercentage(double m1,double m2,double m3) const;

    // Display
    void display() const;
    
    


};










#endif
