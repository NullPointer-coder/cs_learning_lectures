// This program demonstrates a recursive function
// that calculates Fibonacci numbers.
#include <iostream>
using namespace std;

// Function prototype
int fib(int);

int main()
{
   cout << "The first 10 Fibonacci numbers are:\n";
   for (int x = 0; x < 10; x++)
   {
     cout << fib(x) << " ";
   }
   cout << endl;
   return 0;
}

//*****************************************
// Function fib. Accepts an int argument  *
// in n. This function returns the nth    *
// Fibonacci number.                      *
//*****************************************

int fib(int n)
{
   // Base case
   if (n <= 0)
   {
     return 0;
   }
                               
   else if (n == 1)
   {
     return 1;
   }
   // Recursive case
   return fib(n - 1) + fib(n - 2);
}
