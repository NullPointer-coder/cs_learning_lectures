#include <iostream>
#include <array>
using namespace std;
int main()
{
//initialize
array<int, 5> numbers{1, 2, 3, 4, 5};
array<string, 4> names{"Jamie", "Ashley","Doug", "Claire"};

//iterator
array<int, 5>::iterator it;
//Display using iterator
for(auto it = numbers.begin(); it != numbers.end(); it++)
{
  cout << *it *2 << " ";
}
cout << endl;
//Display using iterator reverse
for(auto it = numbers.end() - 1; it >= numbers.begin(); it--)
{
  cout << *it << " ";
}

cout <<endl <<endl;

// const iterator
array<int, 5>::const_iterator itss;
//Display using iterator
for(auto itss = numbers.cbegin(); itss != numbers.cend(); itss++)
{
  cout << *itss * 2  << " " ;
}
cout << endl;
//Display using iterator reverse
for(auto itss = numbers.end() - 1; itss >= numbers.begin(); itss--)
{
  cout << *itss << " ";
}

cout << endl << endl;

// reverse iterator
array<string, 4> :: reverse_iterator its;
//Display using reverse iterator
for(auto its = names.rbegin(); its != names.rend(); its++)
{
  cout << *its << " ";
}
cout << endl;
return 0;
}
