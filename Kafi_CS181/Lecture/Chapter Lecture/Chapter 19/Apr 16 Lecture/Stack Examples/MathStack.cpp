// Implementation file for the MathStack class
#include "MathStack.h"

//***********************************************
// Member function add. add pops                *
// the first two values off the stack and       *
// adds them. The sum is pushed onto the stack. *
//***********************************************

void MathStack::add()
{
   int num1, num2;

   // Pop the first two values off the stack.
   pop(num1);
   pop(num2);

   // Add the two values, store in sum.
   int sum = num1 + num2;

   // Push sum back onto the stack.
   push(sum);
}

//***********************************************
// Member function sub. sub pops the            *
// first two values off the stack. The          *
// second value is subtracted from the          *
// first value. The difference is pushed        *
// onto the stack.                              *
//***********************************************

void MathStack::sub()
{
   int num1, num2;

   // Pop the first two values off the stack.
   pop(num1);
   pop(num2);

   // Subtract num from diff.
   int res = num1 - num2;

   // Push diff back onto the stack.
   push(res);
}