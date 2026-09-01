#include<iostream>
extern void external_func();

int main(){
	std::cout<<"this is an internal textr"<<std::endl;
	//using external function from support.cpp
	external_func();

        return 0;
}
