#include "student.h"
#include "services.h"
#include <iostream>

using namespace std;

int main() {
    const int MAX_CAPACITY = 100;
    student* studentArray[MAX_CAPACITY] = {nullptr};

    // Mock testing entries
    StudentService::addStudent(studentArray, 10, "Rahul", 20, 85, 90, 78);
    StudentService::addStudent(studentArray, 20, "Sneha", 21, 92, 88, 95);

    int choice;
    
do {


      
        cout << "\n===== STUDENT MANAGEMENT SYSTEM =====\n";
        cout << "1. Display All Students\n";
        cout << "2. Search by ID\n";
        cout << "3. Search by Name\n";
        cout << "4. Calculate GPA of a Specific Student\n";
        cout << "5. Add New Student\n";
        cout << "6. Delete Student by ID\n";
        cout << "7. Exit\n";
        cout << "Enter Choice (1-7): ";
        cin >> choice;
    
        switch (choice) {
            case 1:
                StudentService::displayAll(studentArray);
                break;
            case 2: 
                int searchId;
                cout << "Enter Student ID to find: ";
                cin >> searchId;
                StudentService::searchById(studentArray, searchId);
                break;
            
            case 3: 
                char searchName[50];
                cout << "Enter Student Name to find: ";
                cin.ignore();
                cin.getline(searchName, 50);
                StudentService::searchByName(studentArray, searchName);
                break;
            
            case 4: 
                int targetId;
                cout << "Enter the specific Student ID for GPA calculation: ";
                cin >> targetId;
                StudentService::calculateGpaOfStudent(studentArray, targetId);
                break;
            
            case 5: 
                int id, age;
                char name[50];
                double m1, m2, m3;
                cout << "Enter ID: "; cin >> id;
                cout << "Enter Name: "; cin.ignore(); cin.getline(name, 50);
                cout << "Enter Age: "; cin >> age;
                cout << "Enter Marks (m1 m2 m3): "; cin >> m1 >> m2 >> m3;
                
                StudentService::addStudent(studentArray, id, name, age, m1, m2, m3);
                break;
            
            case 6: 
                int delId;
                cout << "Enter ID to remove: ";
                cin >> delId;
                StudentService::deleteStudent(studentArray, delId);
                break;
            
            case 7:
                cout << "bye\n";
                for (int i = 0; i < StudentService::currentSize; ++i) {
                    delete studentArray[i];
                    studentArray[i] = nullptr;}
                
                    break;
            default:
                cout << "Invalid menu selection option.\n";
        
    }
   
}while (choice != 7);

 return 0;

}

