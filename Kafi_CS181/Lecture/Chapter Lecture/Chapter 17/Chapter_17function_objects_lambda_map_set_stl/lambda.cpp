#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
   // Create a vector of ints.
   vector<string> v = { "abcde","abcd" };

   // Use a lambda expression to create a function object.
   auto greaterFive = [](string x) {return x.size() >=5; };

   // Get the number of elements that even.
   int greaterNames = count_if(v.begin(), v.end(), greaterFive);

   // Display the results.
   cout << "The vector contains " << greaterNames << " even numbers.\n";
   return 0;
}
