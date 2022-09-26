// This program demonstrates a simple recursive function.
#include <iostream>
using namespace std;

// Function prototype
int sumTo(int);

int main()
{
   int n=0;
   cout<<"\nEnter a positive interger: ";
   cin>>n;
   int sum = sumTo(n); // the sum to n is returned
   
   cout <<"Sum from 1 to " << n <<" is: " << sum << endl;
   
   return 0;
}


// val = 3 + sumTo(2) = 3
// return val
   // val = 2 + sumTo(1) = 1
   // return val
         // val = 1 + sumTo(0) = 0
         // return val
               // return 0

//***********************************************************
int sumTo(int n) 
{
   // 1: anchor: loop terminating condition
   if(n <=0)
      return 0;
   else 
   {
      // 2: body of the recurstion: do something with the value
      cout << "Recursive function for n = " << n << endl;
      
      // 3: recursion call: update and repeat
      int val = n + sumTo(n - 1); 
      return val;
   }
}
 


