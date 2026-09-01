#include<iostream>
using namespace std;

const int array_size=5;

// Takes input from the user to fill the array
void acceptdata(int arr[array_size]){
   for(int i=0;i<array_size;i++){
        cout<<"enter number "<<i+1<<endl;
        cin>>arr[i];
   }   
}

// Returns the index of the searched number, or -1 if not found
int searchNum(int arr[array_size],int num){
     for(int i=0;i<array_size;i++){
       if(num==arr[i]){
          return i;
       }
    }
    return -1;
}
 
// Replaces the value at a specific index with a new number
void modifydata(int pos,int num,int arr[array_size]){
    if (pos<array_size){
        arr[pos]=num;
        cout << "Number modified successfully!\n";
    } else {
        cout << "Invalid position!\n";
    }
}

// Calculates and returns the sum of all even numbers in the array
int evenAdd(int arr[array_size]){
    int sum=0;
    for(int i=0;i<array_size;i++){
        if (arr[i]%2==0){
            sum+=arr[i];
        }
    } 
    return sum;
}

// Checks if a single number is prime
bool isPrime(int num){
    if(num==1){
        return false;
    }
    for(int i=2;i<num;i++){
       if(num%i==0){
         return false;
       }  
    }
    return true;
}

// Prints all prime numbers and their total count
void primeSum(int arr[array_size]){
   int count=0;
   cout<<"prime numbers are  ";
   for(int i=0;i<array_size;i++){
        bool boolean=isPrime(arr[i]);
        if(boolean==true){
            count++;
            cout<<arr[i]<<"\t";
        }
   }
   cout<<"\ntotal number of prime is  "<< count<< endl;
}

// Prints all elements of the array
void displaydata(int arr[array_size]){
   for(int i=0;i<array_size;i++){
        cout<<arr[i]<<"\t";
   }
   cout << endl;
}

// Shifts elements left to remove a number and fills the end with 0
void deleteNumber(int num, int arr[array_size]) {
    int pos = searchNum(arr, num);
    
    if(pos != -1) {
        for(int i = pos; i < array_size - 1; i++) {
            arr[i] = arr[i+1];
        }
        arr[array_size - 1] = 0; 
        cout << "Number " << num << " deleted successfully!\n";
    } else {
        cout << "Number not found, cannot delete.\n";
    }
}

// Finds and prints the highest odd number in the array
void maxOddNumber(int arr[array_size]) {
    int maxOdd = -1; 
    
    for(int i=0; i<array_size; i++) {
        if(arr[i] % 2 != 0) { 
            if(arr[i] > maxOdd) {
                maxOdd = arr[i];
            }
        }
    }
    
    if(maxOdd != -1) {
        cout << "Maximum odd number is: " << maxOdd << endl;
    } else {
        cout << "No odd numbers found in the array.\n";
    }
}

// Finds the Nth largest distinct number without sorting the array
void findNthMax(int n, int arr[array_size]) {
    if(n <= 0 || n > array_size) {
        cout << "Invalid value for N.\n";
        return;
    }
    
    int currentMax = 2147483647; 
    
    for(int i = 1; i <= n; i++) {
        int nextMax = -2147483648; 
        bool found = false;
        
        for(int j = 0; j < array_size; j++) {
            if(arr[j] < currentMax && arr[j] > nextMax) {
                nextMax = arr[j];
                found = true;
            }
        }
        
        if(!found) {
            cout << "There is no " << n << "th maximum.\n";
            return;
        }
        
        currentMax = nextMax; 
    }
    
    cout << "The " << n << "th maximum is: " << currentMax << endl;
}

// Displays a menu and runs the program in a loop based on user choice
int main(){
   int intarr[array_size];
   int choice, num, pos, n;
   
   do {
   
        cout << "1. Accept Data\n";
        cout << "2. Display \n";
        cout << "3. Modify number at given position\n";
        cout << "4. Delete a given number\n";
        cout << "5. Search a number\n";
        cout << "6. Find addition of all even numbers\n";
        cout << "7. Display prime numbers and its count\n";
        cout << "8. Find maximum odd number\n";
        cout << "9. Find Nth maximum\n";
        cout << "0. EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                acceptdata(intarr);
                break;
            case 2:
                displaydata(intarr);
                break;
            case 3:
                cout << "Enter position to modify (0 to " << array_size-1 << "): ";
                cin >> pos;
                cout << "Enter new number: ";
                cin >> num;
                modifydata(pos, num, intarr);
                break;
            case 4:
                cout << "Enter number to delete: ";
                cin >> num;
                deleteNumber(num, intarr);
                break;
            case 5:
                cout << "Enter number to search: ";
                cin >> num;
                pos = searchNum(intarr, num);
                if(pos != -1)
                    cout << "Found at position " << pos << endl;
                else
                    cout << "Not found\n";
                break;
            case 6:
                cout << "Addition of even numbers is: " << evenAdd(intarr) << endl;
                break;
            case 7:
                primeSum(intarr);
                break;
            case 8:
                maxOddNumber(intarr);
                break;
            case 9:
                cout << "Enter N (e.g., 1 for max, 2 for 2nd max): ";
                cin >> n;
                findNthMax(n, intarr);
                break;
            case 0:
                cout << "Exiting program. Bye!" << endl;
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
   } while(choice != 0);
   
   return 0;
}
