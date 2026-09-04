#ifndef SHAPE_SERVICE_H
#define SHAPE_SERVICE_H

#include <iostream>
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"

using namespace std;

class ShapeService{
    static Shape *sarr[100];
    public:
        static bool addNewShape(Shape **s, int &count, int ch){
            char color[10]; 
            int id;
            double len, br, radius, s1, s2, h, b;
            cout << "enter color : " ;
            cin >> color;
            cout << "Enter id : ";
            cin >> id;
            if(ch == 1){
               cout << "enter len : ";
               cin >> len;
               cout << "enter breadth : ";
               cin >> br;
               s[count++] = new Rectangle(id, color, len, br);
            }
            else if(ch == 2){
               cout << "enter radius : ";
               cin >> radius;
               s[count++] = new Circle(id, color, radius);
            }
            else if(ch == 3){
                //TODO:  accept triangle data here
                cout << "enter side 1 : ";
                cin >> s1;
                cout << "enter side 2 : ";
                cin >> s2;
                cout << "enter base : ";
                cin >> b;
                cout << "enter height : ";
                cin >> h;
                s[count++] = new Triangle(id, color, s1, s2, h, b);
            }
            else{
                cout << "Invalid choice" << endl;
                return false;
            }

            return true;
        }

        static void displayAll(Shape **s, int count){
            for(int i = 0; i < count; ++i){
                s[i]->display();
            }
        }

        static int searchById(Shape **s, int count, int id){
            for(int i = 0; i <count; ++i){
                if(s[i]->getId() == id){
                    return i;
                }
            }
            return -1;
        }
        
        static double findAreaById(Shape **s, int count, int id){
            int pos = searchById(s, count, id);
            if(pos == -1) return 0;
            return s[pos]->calculateArea();
        }

        static double findPerimeterById(Shape **s, int count, int id){
            int pos = searchById(s, count, id);
            if(pos == -1) return 0;
            return s[pos]->calculatePerimeter();
        }

        static void countAll(Shape **s, int count){
            int tCount =0, rCount=0, cCount=0;
            for(int i =0; i < count; ++i){
                if(dynamic_cast<Rectangle* >(s[i])) rCount++;
                else if(dynamic_cast<Circle* >(s[i])) cCount++;
                else if(dynamic_cast<Triangle* >(s[i])) tCount++;
                else cout << "Unknown shape" << endl;
            }
            cout << "Triangle count: " << tCount << endl;
            cout << "Rectangle count: " << rCount << endl;
            cout << "Circle count: " << cCount << endl;
        }


         static void countByType(Shape **s, int count){

            int tCount =0, rCount=0, cCount=0;
            for(int i =0; i < count; ++i){
                if(dynamic_cast<Rectangle* >(s[i])) rCount++;// Rectangle* rec=dynamic_cast<Rectangle* >(s[i]); rec->display();
                else if(dynamic_cast<Circle* >(s[i])) cCount++;
                else if(dynamic_cast<Triangle* >(s[i])) tCount++;
                else cout << "Unknown shape" << endl;
            }
            cout << "Triangle count: " << tCount << endl;
            cout << "Rectangle count: " << rCount << endl;
            cout << "Circle count: " << cCount << endl;
        }

        static void displayByType(Shape **s, int count, int type){


            for(int i =0; i < count; ++i){
                if(dynamic_cast<Rectangle* >(s[i])&&type==1) {
                    Rectangle* rec=dynamic_cast<Rectangle* >(s[i]); rec->display();
                } // Rectangle* rec=dynamic_cast<Rectangle* >(s[i]); rec->display();
                else if(dynamic_cast<Circle* >(s[i])&&type==2) {
                    Circle* rec=dynamic_cast<Circle* >(s[i]); rec->display();
                }
                else if(dynamic_cast<Triangle* >(s[i])&&type==3) {Triangle* rec=dynamic_cast<Triangle* >(s[i]); rec->display();}
                
            }

        }


};

#endif