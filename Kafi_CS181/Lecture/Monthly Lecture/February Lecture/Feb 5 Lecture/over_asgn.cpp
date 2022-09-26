// @author: Kafi Rahman
// The purpose of the program is to store student record information
// by using a collection class

#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <vector>

using namespace std;


class SomeClass
{ private:
    int *value;
  
  public:
    // constructor, also default constructor
    SomeClass(int val = 0)
    {   value = new int;
        *value = val;
    }
    // copy constructor
    SomeClass(const SomeClass &objParam)
    {    value = new int;
        *value = *(objParam.value); 
      
        cout<<endl<<"Copy constructor has been called"<<endl; 
    } 
    
    void operator=(const SomeClass &objParam)
    {   //value = objParam.value; // dangerous
    
        *value = *(objParam.value); 
        cout<<endl<<"Assignment operator has been called"<<endl; 
    }     

     
    int getVal();
    void setVal(int);
   
    ~SomeClass()
    { cout<<"\nFreeing memory .."; 
      delete value;  
    }
  
};


int SomeClass::getVal()
{  return *value;
}

void SomeClass::setVal(int val)
{  *value = val;
}

// display function call is copy constructor
void displayObject(SomeClass param)
{
  // change to the param object is not going
  // to affect the sumeObjectOne object
  param.setVal(100); 
  cout<< param.getVal() << endl;
}

///////////////////////////////////////////////////
int main()
{
  SomeClass someObjectOne(20);
  SomeClass sObject = someObjectOne;
  SomeClass someObjectTwo ;
  
  cout<<"Before, The value is: "<< someObjectTwo.getVal();
  
  //someObjectTwo.operator=(someObjectOne); 
  someObjectTwo = someObjectOne; // assignment operator
  
  someObjectOne.setVal(10);
  
  cout<<"\n\nAfter, The value is: "<< someObjectTwo.getVal(); 
  
  // when a call a function and pass an object as an argument
  // the formal parameter is going to be initialized by using
  // a copy constructor call
  displayObject(someObjectOne);
  
  return 0; 
}
 
