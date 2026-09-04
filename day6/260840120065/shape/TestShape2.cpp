#include <iostream>
#include "Shape.h"
#include "Rectangle.h"
#include "ShapeService.h"

using namespace std;

int main(){
    Shape *sArr[100];
    int count = 0, id;
    int choice = 0;
    double area;//or perimeter
    
    cout<<count;
    do{
      cout << "1. add new shape\n 2.calculate area by id\n 3.calculate perimeter by id\n ";
      cout << "4. display count of given type\n 5. display all\n 6.count all types\n 7.display by type\n 0. exit\n";
      cin >> choice;
      int subChoice = 0;
      bool status = false;
      switch(choice){
        case 1:
            // add new shape
            cout << "1. rectangle\n 2.circle\n 3. triangle\n";
            cin >> subChoice;
            status = ShapeService::addNewShape(sArr , count, subChoice);
            if(status){
                cout << "Shape added..." << endl;
            }
            else{
                cout << "Not added..."<< endl;
            }
            break;
        case 2:
            // 2.calculate area by id
            cout << "enter id : ";
            cin >> id;
            area = ShapeService::findAreaById(sArr, count, id);
            cout << "Area : " << (area > 0 ? area  : -1) << endl;
            break;
        case 3:
             cout << "enter id : ";
            cin >> id;
            area = ShapeService::findPerimeterById(sArr, count, id);
            cout << "Perimeter : " << (area > 0 ? area  : -1) << endl;
            
            break;
        case 4:
            // 4. display count of given type
            
            ShapeService::countByType(sArr, count);
            break;
        case 5:
            // display all shape
            ShapeService::displayAll(sArr, count);
            break;
        case 6:
            ShapeService::countAll(sArr, count);
            break;
        case 7:
            int type;
            cout <<  "which type of shapes you wanna display?  1. rectangle\n 2.circle\n 3. triangle\n";
            cin >> type;
            ShapeService::displayByType(sArr, count, type);
        case 0:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Wrong choice\n";
      }
      
    }while(choice != 0);
    return 0;
}