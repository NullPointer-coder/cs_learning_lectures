#include <iostream>
#include <array>
using namespace std;
int main()
{
//initialize
array<int, 5> numbers{1, 2, 3, 4, 5};
array<string, 4> names{"Jamie", "Ashley","Doug", "Claire"};

//iterator
array<string, 3>::reverse_iterator it;
//output reversely
for(auto it = numbers.rbegin(); it != numbers.rend(); it++)
{
  cout << *it << endl;
}
return 0;
}
