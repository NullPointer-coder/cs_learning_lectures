#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Sum
{
public:
   int operator()(int a, int b)
   {
      return a + b;
   }
};

class IsEven
{
public:
   bool operator()(int x)
   {
      return x % 2 == 0;
   }
};

int main()
{
   int x = 10;
   int y = 2;
   int z = 0;
   Sum sum;
   z = sum(x, y);
   cout << z << endl;

   vector<int> v = { 1, 2, 3, 4, 5, 6, 7, 8 };
   int evenNums = count_if(v.begin(), v.end(), IsEven());
   cout << "The vector contains " << evenNums << " even numbers.\n";

   return 0;
}
