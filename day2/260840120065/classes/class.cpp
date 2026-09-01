#include<iostream>
using namespace std;
#include<string>

class Student{
	private:
		int sid,age,m1,m2,m3;
		string sname;
	
	public:
		//default constructor
		Student() {
			cout<<"this is a default constructor"<<endl;
        sid = 0;
        sname = "Unknown";
        age = 0;
        m1 = 0.0;
        m2 = 0.0;
        m3 = 0.0;
    }
     
	    //  Parameterized Constructor
              Student(int id, string name, int a, double mark1, double mark2, double mark3) {
		      cout<< " this is a parameterized constructor "<< endl;
        sid = id;
        sname = name;
        age = a;
        m1 = mark1;
        m2 = mark2;
        m3 = mark3;
    }
 // 		 Setters
    void setSid(int id) { sid = id; }
    void setSname(string name) { sname = name; }
    void setAge(int a) { age = a; }
    void setM1(double mark1) { m1 = mark1; }
    void setM2(double mark2) { m2 = mark2; }
    void setM3(double mark3) { m3 = mark3; }



    // Getters
    int getSid() const { return sid; }
    string getSname() const { return sname; }
    int getAge() const { return age; }
    double getM1() const { return m1; }
    double getM2() const { return m2; }
    double getM3() const { return m3; }

    // Percentage
    double calculatePercentage() const {
        return (m1 + m2 + m3) / 3.0;
    }

    // Display
    void display() const {
        cout << "\n Student Details\n";
        cout << "Student ID : " << sid << "\n";
        cout << "Name       : " << sname << "\n";
        cout << "Age        : " << age << "\n";
        cout << "Marks      : Subject 1: " << m1 << ", Subject 2: " << m2 << ", Subject 3: " << m3 << "\n";
        cout << "Percentage : " << calculatePercentage() << "%\n";
    }




};






int main()
{



	// Testing Default Constructor
    Student s1;
    cout << "Testing Default Constructor:";
    s1.display();

    // Testing Parameterized Constructor
    Student s2(101, "Arin", 20, 85.5, 90.0, 78.0);
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

    return 0;

}
