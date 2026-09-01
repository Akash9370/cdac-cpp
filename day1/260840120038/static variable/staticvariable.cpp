#include<iostream>
using namespace std;
//static variable changes but general keeps as it is 
void function1()
{
  int a=10;
  static int b=20;
  cout<<"current variables a and b respectively : "<<a<<"  "  <<b<<endl;
  a++;
  b++;
  cout<<"a(normal): "<<a<<endl;
  cout<<"b(static): "<<b<<endl;
}
int main(){
	cout<<"checking changes with static and normal variable "<<endl;
	cout<<"calling fucntion  once : ";
	function1();
	cout<<endl<<"calling fucntion again:";
	function1();

        return 0;
}
