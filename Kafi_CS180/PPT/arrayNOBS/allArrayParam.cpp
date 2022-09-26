//@author: Kafi Rahman
// Individual array elements are passed by value in C++

#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

// adds the first two parameters and stores the result in the
// third parameter
void sum(int first, int second, int &res);

// the main function
int main()
{
  const int SIZE = 3; // size of the array

  int value[SIZE] = {95, 5, 0};

  sum(value[0], value[1], value[2]); // individual array elements are passed as parameters

  cout << "Sum: " << value[2] << endl;

  return 0;
}

void sum(int first, int second, int &res)
{
  res = first + second;
}
