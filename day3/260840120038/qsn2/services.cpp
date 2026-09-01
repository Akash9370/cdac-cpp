#include "services.h"
#include <iostream>
#include <cstring>
//#include "student.h"

using namespace std;

int StudentService::currentSize = 0;

// Central formula definition inside the service logic block
void StudentService::calculateGPA(student* studentobj) {
    if (studentobj != nullptr) {
        double calculatedGpa = (1.0 / 3.0) * studentobj->getM1() + 
                               (1.0 / 2.0) * studentobj->getM2() + 
                               (1.0 / 4.0) * studentobj->getM3();
        studentobj->setGpa(calculatedGpa);
    }
}

bool StudentService::addStudent(student* studentsarr[], int sid, const char* name, int age, double m1, double m2, double m3) {
    if (currentSize >= MAX_CAPACITY) {
        cout << "Error: Directory capacity full!\n";
        return false;
    }
    
    studentsarr[currentSize] = new student(sid, name, age, m1, m2, m3);
    calculateGPA(studentsarr[currentSize]); 
    
    currentSize++; 
    cout << "Student added successfully!\n";
    return true;
}

bool StudentService::deleteStudent(student* studentsarr[], int id) {
    for (int i = 0; i < currentSize; ++i) {
        if (studentsarr[i] != nullptr && studentsarr[i]->getSid() == id) {
            delete studentsarr[i];
            
            for (int j = i; j < currentSize - 1; ++j) {
                studentsarr[j] = studentsarr[j + 1];
            }
            studentsarr[currentSize - 1] = nullptr; 
            
            currentSize--; 
            cout << "Student with ID " << id << " deleted successfully!\n";
            return true;
        }
    }
    cout << "Error: Student with ID " << id << " not found for deletion.\n";
    return false;
}

void StudentService::displayAll(student* studentsarr[]) {
    if (currentSize == 0) {
        cout << "No student records found.\n";
        return;
    }
    cout << "\n--- Student Directory (Count: " << currentSize << ") ---\n";
    for (int i = 0; i < currentSize; ++i) {
        if (studentsarr[i] != nullptr) {
            studentsarr[i]->display();
        }
    }
}

void StudentService::searchById(student* studentsarr[], int id) {
    for (int i = 0; i < currentSize; ++i) {
        if (studentsarr[i] != nullptr && studentsarr[i]->getSid() == id) {
            cout << "\nStudent Record Found:\n";
            studentsarr[i]->display();
            return;
        }
    }
    cout << "No record found matching ID: " << id << "\n";
}

void StudentService::searchByName(student* studentsarr[], const char* name) {
    bool found = false;
    for (int i = 0; i < currentSize; ++i) {
        if ((studentsarr[i] != nullptr && studentsarr[i]->getSname()== name)) {
            cout << "\nStudent Record Found:\n";
            studentsarr[i]->display();
            found = true;
        }
    }
    if (!found) cout << "No record found matching Name: " << name << "\n";
}

// Looks up a targeted ID, triggers calculateGPA(), and displays the specific outcome
void StudentService::calculateGpaOfStudent(student* studentsarr[], int id) {
    for (int i = 0; i < currentSize; ++i) {
        if (studentsarr[i] != nullptr && studentsarr[i]->getSid() == id) {
            calculateGPA(studentsarr[i]); // Re-calculate to match newest values
            cout << "\n--- GPA Result for Targeted ID ---\n";
            cout << "Student Name: " << studentsarr[i]->getSname() << "\n";
            cout << "Computed GPA : " << studentsarr[i]->getGpa() << "\n";
            return;
        }
    }
    cout << "Calculation Failed: Student with ID " << id << " does not exist.\n";
}

