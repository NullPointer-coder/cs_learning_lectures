// This program demonstrates a recursive function
// that calculates Fibonacci numbers.
#include <iostream>
using namespace std;


/**
In this recursive version of the binary search, we create new instances
of the recursive function and modify the start_index and end_index in order
to zoom into the location of the array where the search element 
can be located
*/

int BinarySearch(int array[], int start_index, int end_index, int element);


int main()
{
   int array[] = {1, 4, 7, 9, 16, 56, 70};
   int n = 7; // number of elements in the array
   int element = 9; // the element that we are looking for in the aray
   
   int found_index = BinarySearch(array, 0, n-1, element);
   if(found_index == -1 ) 
   {
      cout<< "Element not found in the array " << endl;
   }
   else 
   {
      cout << "Element found at index :" << found_index << endl;
   }
   return 0;
}




int BinarySearch(int array[], int start_index, int end_index, int element){
   
   // when end_index < start_index is true, that would indicate
   // that the element has not been found
   
   if (end_index <start_index) return -1; // one base case
   
   // calculate the middle value
   int middle = (start_index + end_index)/ 2;
   
   // if the value is found, we stop
   // this is one base case
   if (array[middle] == element)
   {
     return middle;
   } // second base case
   if (array[middle] > element) 
   {
     return BinarySearch(array, start_index, middle-1, element);
   }// the element is on the left side of the middle
   else 
   {
     return BinarySearch(array, middle+1, end_index, element);
   }// the element is on the right side of the middle value
      
   
}
