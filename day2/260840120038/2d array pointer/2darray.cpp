#include<iostream>
using namespace std; 

//to enter data
void acceptData(int** arr,int rows,int cols)
{
	cout<<"enter elements for " <<rows<< " X "<< cols<<" : "<<endl;
        for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			cout<<"enter element "<<i<<"X"<<j<<" : "<<endl;
			cin>>arr[i][j];


		}



	}

}	


// to dispaly 2d array
void displayData(int** arr,int rows,int cols)
{
        cout<<"elements of  " <<rows<< " X "<< cols<<"array is  : "<<endl;
        for(int i=0;i<rows;i++){
                for(int j=0;j<cols;j++){
                       
                        cout<<arr[i][j]<<"\t";


                }
            cout<<endl;


        }

}


// max element of 2d matrix
int findMax(int** arr,int rows,int cols){
  int mx= arr[0][0];
 for(int i=0;i<rows;i++)

 {
     for(int j=0;j<cols;j++)

     {
      if(arr[i][j]>mx){
	mx=arr[i][j];}	      
		      
     }
 }
  return mx;
}


//min element of 2d matrix
int findMin(int** arr,int rows,int cols){
  int mn= arr[0][0];
 for(int i=0;i<rows;i++)

 {
     for(int j=0;j<cols;j++)

     {
      if(arr[i][j]<mn){
        mn=arr[i][j];}

     }
 }
  return mn;
}


//sum of all elements of array
int sumofAll(int** arr, int rows, int cols)
{
  int sum=0;
 for(int i=0;i<rows;i++)

 {
     for(int j=0;j<cols;j++)

     {
        sum=sum+arr[i][j];
     }
 }
  return sum;

}


//sum of each row
void  sumofrows(int** arr, int rows, int cols)
{
  
 for(int i=0;i<rows;i++){
	 int sum=0;
     for(int j=0;j<cols;j++)

     {
        sum=sum+arr[i][j];
     }
   cout<<"sum of row "<< i<< " is "<<sum<<endl;
 }
 
}


// sum of each cols
void  sumofcols(int** arr, int rows, int cols)
{

 for(int i=0;i<cols;i++){
         int sum=0;
     for(int j=0;j<rows;j++)

     {
        sum=sum+arr[j][i];
     }
   cout<<"sum of cols "<< i<< " is "<<sum<<endl;
 }

}


// rowise max element
void  rowMax(int** arr, int rows, int cols)
{

 for(int i=0;i<rows;i++){
         int Max=arr[i][0];
     for(int j=0;j<cols;j++)

     {
        if(Max<arr[i][j])
	{
         Max=arr[i][j];
	}
     }
   cout<<"Maximum of row "<< i<< " is "<<Max<<endl;
 }

}


//column wise max element
void  maxofcols(int** arr, int rows, int cols)
{

 for(int i=0;i<cols;i++){
         int Max=arr[0][i];
     for(int j=0;j<rows;j++)

     {
        if(arr[j][i]>Max){
		Max=arr[j][i];
	}
     }
   cout<<"max  of column "<< i<< " is "<<Max<<endl;
 }

}



int main(){ 
	int rows=3,cols=3;
	//making 2d array using pointers instead of arr[rows][cols]
	int **arr=new int*[rows];
        for(int i=0;i<cols;i++){
		arr[i]=new int[cols];
	}	
          int choice;
        do{

	cout<<"------------------------------------------"<<endl<<endl;
	cout<<"1. Accept data"<<endl<< 
	      "2. Display data"<<endl<<
              "3. Find maximum number"<<endl<<
              "4. Find minimum number"<<endl<<
              "5. Find addition of all numbers"<<endl<<
              "6. Find sum of each row"<<endl<<
              "7. Find sum of each column"<<endl<<
              "8. Find rowwies maximum"<<endl<<
              "9. Find columnise maximum"<<endl<<
	      "10. Exit"<<endl<<endl;

           
	   cin>>choice;
           
	   switch(choice){

		   case 1:
			   acceptData(arr,rows,cols);
			   break;
		   case 2:
                           displayData(arr,rows,cols);
			   break;
                   case 3:
                          cout<<"the max number in the array is:  "<<findMax(arr,rows,cols)<<endl;
			   break;
        
	   
		   case 4:
			  cout<<"the min number in the array is:" <<findMin(arr,rows,cols);
			   break;
               	case 5:
			   cout<<"sum is :"<<sumofAll(arr,rows,cols)<<endl;
			   break;
	 case 6:
			   sumofrows(arr,rows,cols);
			   break;
	case 7:
			   sumofcols(arr,rows,cols);
			   break;
	case 8:
		   	   rowMax(arr,rows,cols);
			   break;
	case 9:

			   maxofcols(arr,rows,cols);
			   break;
	case 10:
			   cout<<"exiting the program"<<endl;
			   break;
        default:
			   cout<<"invalid entry " <<endl;
			  

	
	   }} while(choice!=10);
return 0;
}
