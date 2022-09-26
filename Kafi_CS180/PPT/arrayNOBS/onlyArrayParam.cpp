//@author: Kafi Rahman
// array is passed by reference in C++

#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

// adds the first two elements of the array and stores the result in the
// third element of the array
void sum(int array[]);

// the main function
int main()
{
  const int SIZE = 3; // size of the array

  int value[SIZE] = {95, 5, 0};

  sum(value); // calling the function with the array as the actual parameter

  cout << "Sum: " << value[2] << endl;

  return 0;
}

void sum(int array[])
{
  array[2] = array[0] + array[1];
}
