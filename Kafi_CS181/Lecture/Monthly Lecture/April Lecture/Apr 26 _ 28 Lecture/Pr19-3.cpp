// This program demonstrates a recursive function to
// calculate the factorial of a number.
#include <iostream>
using namespace std;

// Function prototype
int factorial(int);

int main()
{
   int number;

   // Get a number from the user.
   cout << "Enter an integer value and I will display\n";
   cout << "its factorial: ";
   cin >> number;
   
   // Display the factorial of the number.
   cout << "The factorial of " << number << " is ";
   cout << factorial(number) << endl;
   return 0;
}


// val = 3 * factorial(2) = 2
// return val = 6
   // val = 2 * factorial(1) = 1
   // return val = 2
      // val = 1 * factorial(0) = 1
      // return val = 1
         // return 1


//*************************************************************
// Definition of factorial. A recursive function to calculate *
// the factorial of the parameter n.                          *
//*************************************************************

int factorial(int n) 
{
   // 1: anchor or the base case 
   if (n == 0)
      return 1;                       
   else 
   {
      // 2&3: body and recursive call
      int val = n * factorial(n - 1); 
      return val;
   }
   
}