#include <iostream>
#include <set>

using namespace std;

int main()
{
  set<int> numbers;
  numbers.insert(10);
  numbers.insert(20);
  numbers.insert(30);

  //display elements
  for(int element: numbers)
  {
    cout << element << endl;
  }

  //using iterator
  set<int>::iterator it;

  for (it = numbers.begin(); it != numbers.end(); it++)
  {
    cout << *it << endl;
  }
  //find something
  if(numbers.count(10))
  {
    cout << "Found it!";
  }
  else
  {
    cout << "not found";
  }

}