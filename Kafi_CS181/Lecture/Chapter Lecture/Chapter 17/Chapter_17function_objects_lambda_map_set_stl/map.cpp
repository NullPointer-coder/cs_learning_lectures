#include <iostream>
#include <map>
#include <utility>

using namespace std;

int main()
{
//initialize
  map<int, string> employees =
  {
      {101, "Chris Jones"}, {102, "Jessica Smith"},
      {103, "Amanda Stevens"}, {104, "Will Osborn"}
  };
// adding element
  employees.insert(make_pair(105, "Sam Huston"));
  employees.emplace(106,"Santa clown");
//deleting element
  employees.erase(102);
// Display each element.
for (pair<int, string> element : employees)
{
    cout << "ID: " << element.first << "\tName: ";
}

return 0;
}

