#include<iostream>
using namespace std;


int main(){
    int a = 5;
    int b = 10;

    const int* ptr1 = &a;  // pointer to const int — *ptr1 is read-only
    int* const ptr2 = &a;  // const pointer to int — ptr2 cannot point elsewhere

    // Trying to modify the value through ptr1 → ERROR!
   //*ptr1 = 20;  //  Error: cannot assign to *ptr1 because it is const
    cout<<"before doing ptr1 = &b; value of ptr 1 is where value of b is 10  "<<*ptr1<<endl;
    // You can change ptr1 to point somewhere else though (pointer itself is non-const)
    ptr1 = &b;  //  OK: ptr1 can point to another int
    cout<<"after doing ptr1 = &b; value of ptr 1 is (value of b is 10): "<<*ptr1<<endl;

    // Trying to change ptr2 to point somewhere else → ERROR!
    //ptr2 = &b;  //  Error: ptr2 is const pointer and cannot be reassigned

    // But you can change the value of what ptr2 points to
    cout<<"before doing *ptr2=30 value of ptr2 is"<<*ptr2<<endl;
    *ptr2 = 30;  //  OK: modifying value through ptr2 is allowed
    cout<<"after doing *ptr2=30 value of ptr2 is"<<*ptr2<<endl;

    std::cout << "a = " << a << std::endl;  // Output: a = 30
    std::cout << "b = " << b << std::endl;  // Output: b = 10

    return 0;

}
