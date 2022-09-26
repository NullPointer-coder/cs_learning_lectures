// This program demonstrates a recursive function for counting
// the number of times a character appears in a string.
#include <iostream>
#include <string>
using namespace std;

// Function prototype
int numChars(char, string, int);

int main()
{
   string str = "adde";

   // Display the number of times the letter
   // 'd' appears in the string.
   cout << "The letter d appears "
        << numChars('d', str, 0) << " times.\n";

   return 0;
}

//************************************************
// Function numChars. This recursive function    *
// counts the number of times the character      *
// search appears in the string str. The search  *
// begins at the subscript stored in subscript.  *
//************************************************

int numChars(char search, string str, int subscript)
{
   if (subscript >= str.length())
   {
      // Base case: The end of the string is reached.
      return 0;
   }

   int count = 0;

   // Recursive case: A matching character was found.
   if (str[subscript] == search)
      count = 1;

   // looking for search in the next subscript
   return count + numChars(search, str, subscript + 1);
}