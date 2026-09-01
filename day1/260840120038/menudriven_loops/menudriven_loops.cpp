#include<iostream>
using namespace std;

//returns true if the number is prime otherwise return false
bool isPrime(int num){
    
    for(int i=2;i<num;i++){
       if(num%i==0){
         return false;
       }  
    }
    return true;
}

//returns addition of digits of a number
int findDigitAddition(int num){
   int sum=0;
   while(num>0){
     int d=num%10;
     sum+=d;
     num=num/10;
   } 
   return sum;
}

// returns factorial of given number 
int fact(int num){

   int factorial=1;
   if(num==0)
   {
     return factorial;
   }
   for(int i=1;i<=num;i++)
   {  
      factorial=factorial*i;
   }

return factorial;
}

// tabvle of given number 
void table(int num)
{
for(int i=1;i<=10;i++)
    {
     cout<<num<<" * "<<i<<" = "<<num*i<<endl;
    
    }

}

int main(){
   int choice=0,num,result;
   bool status;
   do{
   cout<<"1. Check prime\n2. Factorial\n3. printtable\n4. find addition of digits of a number\n5. exit\nchoice:";
   cin>>choice;
   switch(choice){
   case 1:
         cout<<"enter number"<<endl;
         cin>>num;
         status=isPrime(num);
         if(status){
             cout<<num <<" is prime"<<endl;
         }else{
             cout<<num<<" is not prime"<<endl;
         }
         break;
   case 2:
         //todo factorial function
         cout<<"Enter the number to find factorial: "<<endl;
         cin>>num;
         cout<<"the factorial of : "<<num<<" is " <<fact(num)<<endl;
         break;
   case 3:
         //todo print table function //output is 5*1=5  5*2=10 ... 5*10=50
         cout<<"enter number to find table : "<<endl;
         cin>>num;
         table(num);
         break;
   case 4:
         cout<<"enter number"<<endl;
         cin>>num;
         result=findDigitAddition(num);
         cout<<"sum of digits is : "<<result<<endl;
         break;
   case 5: 
        cout<<"Thank you for using our code"<<endl;
   default:
         break;
   }  
   }while(choice!=5); 
   return 0;
}
