//@author: Kafi Rahman
// advantage of using parallel arrays in C++

#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

// the main function
int main()
{
  const int SIZE = 4; // size of the array
  // values for the arrays
  const char grades[] = {'A', 'B', 'A', 'C'};
  const double average[] = {98.5, 88, 92.5, 78.5};
  const string names[] = {"Sue", "Joe", "Ann", "Deb"};

  // using one loop to access all the elements of the parallel array
  for (int i = 0; i < SIZE; i++)
  {
    cout << names[i] << "\tAvg: " << average[i] << "\t\tGrade: " << grades[i] << endl;
  }

  return 0;
}