// from Gaddis program 7-19
// see how an array acts like a reference parameter

#include <iostream>
using namespace std;

/**
   write the contents of an array to screen
   @param values the array whose contents to show
   @param size the number of elements of the array to show
*/
void show_values(const int values[], unsigned size);

/**
   double the value of each array element
   @param values the array whose elements are to be doubled
   @param size the number of elements to double
*/
void double_values(int values[], unsigned size);

int main()
{
  const unsigned SIZE = 6;
  int numbers[SIZE]{5, 10, 15, 20, 25, 30};

  cout << "Before:" << endl;
  show_values(numbers, SIZE);

  double_values(numbers, SIZE);

  cout << "After:" << endl;
  show_values(numbers, SIZE);
  return 0;
}

void show_values(const int values[], unsigned size)
{
  //values[0] = 10; // array elements change

  // displaying all the elements of the array
  for (unsigned index = 0; index < size; index++)
  {
    cout << values[index] << ' ';
  }
  cout << endl;
}

void double_values(int values[], unsigned size)
{
  // doubling the value of each element of the array
  for (unsigned index = 0; index < size; index++)
  {
    values[index] = values[index] * 2;
  }
}
