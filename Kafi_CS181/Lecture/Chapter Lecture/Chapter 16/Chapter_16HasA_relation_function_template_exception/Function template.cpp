#include <iostream>

using namespace std;

// Only one data type class
template <class T>
T mutiplcation(T num1, T num2)
{
  T result = num1 * num2;
  return result;
}

int main()
{
  double num1;
  double num2;
  cout << mutiplcation( num1,  num2) ;
  return 0;
}
-----------------------------------------------------------------------
// multiple data types
template<class T1, class T2>
double mpg(T1 miles, T2 gallons)
{
  return miles/gallons;
}

int main()
{
  cout << mpg(100,5.5) <<endl;
}
