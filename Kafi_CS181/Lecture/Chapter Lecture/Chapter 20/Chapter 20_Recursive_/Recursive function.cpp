// This program demonstrates a simple recursive function.
#include <iostream>
using namespace std;

// Function prototype
void message(int);

int main()
{  int n=0;
   cout<<"\nHow many iteration of the loop: ";
   cin>>n;
   message(n); // the message will display n times
   
   return 0;
}


//***********************************************************
void message(int times)
{  // 1: anchor: loop terminating condition
   if(times <=0)
   {  cout <<"Done" << endl; 
   }
   else 
   {
      // 2: body of the recurstion: do something with the value
      cout << "This is a recursive function: " << times << endl;
      
      // 3: recursion call: update and repeat
      message(times - 1);
   } 
}



