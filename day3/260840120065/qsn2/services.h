#ifndef SERVICE_H
#define SERVICE_H

#include "student.h"

class StudentService {
private:
    static const int MAX_CAPACITY = 100;

public:
    static int currentSize; 

    // Core Calculation Logic
    static void calculateGPA(student* studentobj);

    // Record Management Operations
    static bool addStudent(student* studentsarr[], int sid, const char* name, int age, double m1, double m2, double m3);
    static bool deleteStudent(student* studentsarr[], int id);

    // Query & Output Display Actions
    static void displayAll(student* studentsarr[]);
    static void searchById(student* studentsarr[], int id);
    static void searchByName(student* studentsarr[], const char* name);
    
    // Updated signature: calculates GPA for a specific student ID found in the array
    static void calculateGpaOfStudent(student* studentsarr[], int id);
};

#endif

