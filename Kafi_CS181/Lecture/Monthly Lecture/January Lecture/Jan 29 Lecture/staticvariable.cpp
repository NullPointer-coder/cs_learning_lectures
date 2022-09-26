#include <iostream>
using namespace std;

 
class Tree // class of a Tree
{ 
    
    int branch;
    
  public:
    static int number_of_objects;
    Tree()
    {
      number_of_objects ++;
    }
    static int getNumberOfObjects() ;
}; // end of the structure definition

int Tree:: number_of_objects = 0;

int Tree:: getNumberOfObjects()
{
  return number_of_objects; 
}

// driver function
int main()
{
  Tree palm_tree; // one object has been declared
  Tree elm_tree; // one object has been declared
  Tree oak_tree; // one object has been declared
  cout<<Tree::number_of_objects << endl;
  return 0; 
}