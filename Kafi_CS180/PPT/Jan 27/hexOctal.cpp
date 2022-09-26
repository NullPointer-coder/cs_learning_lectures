// This program shows hex and octal literals

#include <iostream>
using namespace std;

int main()
{
  unsigned value_1 = 0xa;
  unsigned value_2 = 010;

  cout << "value_1 in decimal is: " << dec << value_1 << endl;
  cout << "value_2 in decimal is: " << dec << value_2 << endl;
  
  
  cout << "value_1 in hex is: " << hex << value_1 << endl;
  cout << "value_2 in octal is: " << oct << value_2 << endl;
  
  
  return 0;
}
 