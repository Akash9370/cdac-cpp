#include<iostream>
using namespace std;
#include<cstring>

int main(){
    char ch='a';
    char str[50],*name;
    cout<<"enter a string";
    //cin>>str;    //acept the string upto 1st space chracter ot \n character
   cin.getline(str,'\n');   //to accept string with spaces
    int length=strlen(str);
    name=new char[length+1];
    strcpy(name,str);
    cout<<"Name : "<<name;
    delete[] name;
    //try strcmp,stricompare  to compare string
    return 0;


}
