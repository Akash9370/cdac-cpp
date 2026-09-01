#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>

const int MAX_STR_LEN=100;
static float baseHours=180;
class Employee
{
	private:
	        static int idCounter; 
		char* Ename;
		double sal;
		float Ehours;
		double baseSal;
		double Eid;
		float bonus;
		
		float overtime;
                float salBonus;
                float salBonusOT;
	        

	public:
		Employee();
		~Employee();

		//setter;
		
		double  generateID();
		double calcSal();
		double calcSal(float bonusAmount);                     
                double calcSal(float bonusAmount, float overtimeHours); 
                
                
		void acceptEmp();
		void displayEmp() const;
		float getBonus();
		
		friend std::istream& operator>>(std::istream& in, Employee& emp);
                friend std::ostream& operator<<(std::ostream& out, const Employee& emp);



		








};









#endif
