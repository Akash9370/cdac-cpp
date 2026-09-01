
#include <iostream>
#include<cstring>
#include "employee.h"

using namespace std;

int Employee::idCounter =0; 
Employee::Employee(){
	idCounter++;
	Eid=generateID();
	Ename=nullptr;
	sal=0;
	Ehours=0;
	baseSal=0;
	bonus=0;
	overtime=0;
        salBonus=0;
        salBonusOT=0;
	
}

Employee::~Employee(){

	if(Ename!=nullptr){
		delete[] Ename;
	}
}

double Employee::generateID(){
	double temp= 1000+idCounter;
	return temp;
}
/*
double Employee::calcSal(){
	double salary;
	float overtime=Ehours-baseHours;
	if (overtime<0){
	salary= baseSal+(overtime*100);
	return salary;
	}
	salary=baseSal+(overtime*1000);//overtime per hr 1000
	return salary;
}



double Employee::calcSal(){
	double salary;
	float overtime=Ehours-baseHours;
	if (overtime<0){
	salary= baseSal+(overtime*100);
	return salary;
	}
	salary=baseSal+(overtime*1000);//overtime per hr 1000
	return salary;
}*/



// Mode 1: Calculates basic salary only
double Employee::calcSal() {
    return baseSal;
}

// Mode 2: Calculates salary with bonus (No overtime cash)
double Employee::calcSal(float bonusAmount) {
    return baseSal + bonusAmount;
}

// Mode 3: Calculates salary with bonus AND overtime cash
double Employee::calcSal(float bonusAmount, float overtimeHours) {
    // 1000 per hour extra for overtime as per your original logic
    double overtimePay = (overtimeHours > 0) ? (overtimeHours * 1000) : 0; 
    return baseSal + bonusAmount + overtimePay;
}


void Employee::acceptEmp() {

        if (Ename != nullptr) {
        delete[] Ename;
        Ename = nullptr;
    }
    
    char tempName[MAX_STR_LEN];

    cout << "Enter Name: ";
    cin.getline(tempName, MAX_STR_LEN);
    Ename=new char[strlen(tempName)+1];
    strcpy(Ename,tempName);

    
    
    cout << "How many hours have you worked in this month ";
    cin >> Ehours;
    while (cin.get() != '\n'); // to clear prev garbage from cin 

  


    cout << "Enter Basic pay of the employee : ";
    cin>>baseSal;
    while (cin.get() != '\n'); // to clear prev garbage from cin 
    
    overtime=Ehours-baseHours;
    sal=calcSal();
    bonus=getBonus();
    salBonus=calcSal(bonus);
    salBonusOT=calcSal(bonus,overtime);
    
    cout<<"employee"<<Eid<<"  Created."<<endl;
}

void Employee::displayEmp() const{
cout << "\n--------------------------------------------";
    cout << "\nID            : " << Eid;
    cout << "\nName          : " <<Ename;
    

    

    cout << "\n hours worked: : "<< Ehours;
    cout << "\nBaseSal " << baseSal;
    cout<<"\n salary base: "<< sal;
    cout<<"\n salary with bonus"<<salBonus;
    cout<<"\n salary with bonus + overtime "<<salBonusOT;
    cout << "\n--------------------------------------------\n";
}


float Employee::getBonus(){
    float overtime=Ehours-baseHours;
    if (overtime>=0){
    bonus=overtime*(0.01*baseSal);
    return bonus;
    }
    
    return bonus=0;

}


istream& operator>>(istream& in, Employee& emp) {
      emp.acceptEmp();
      return in;



}

ostream& operator<<(ostream& out, const Employee& emp) {
         emp.displayEmp();
         return out;
}


