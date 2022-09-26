#include <iostream>
using namespace std;

class Tree // class of a Tree
{ public: 
    static int number_of_objects;
    Tree()
    {  number_of_objects ++;
    }
    ~Tree()
    {  number_of_objects--;
    }

    static int getNumberOfObjects()
    {  return number_of_objects; 
    }
}; // end of the structure definition

int Tree:: number_of_objects = 0;

// to create a couple of objects
void create_forest()
{   Tree palm_tree; 
    Tree elm_tree; 
    Tree oak_tree; 
    cout<<Tree::number_of_objects << endl;
}

// driver function
int main()
{
  create_forest();
  Tree oak_tree; // one object has been declared
  cout<< Tree::getNumberOfObjects() << endl;
  return 0; 
}