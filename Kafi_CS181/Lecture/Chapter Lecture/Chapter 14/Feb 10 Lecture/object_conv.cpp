// @author: Kafi Rahman

#include <iomanip>
#include <iostream>
#include <string>

using namespace std;


class FeetInches
{ int feet;
  int inch;
  public:
    FeetInches(int f = 0, int i = 0)
    {  feet = f + i / 12;
       inch = i % 12;
    }
    
    operator int() 
    { cout<<"int operator function called ..." << endl; 
      return feet * 12 + inch;
    }
    
    operator float() 
    { cout<<"float operator function called ..." << endl; 
      return static_cast<float>(feet * 12 + inch);
    }
    
    operator string()
    {
      cout<<"string operator function called ..." << endl; 
      return std::to_string(feet * 12 + inch);
    }
    
    int getFeet() { return feet;}
    int getInch() { return inch;}   
    void setFeet(int f) { feet = f;}
    void setInches(int i)
    {   feet +=  i / 12;
        inch = i % 12;
    }

};


///////////////////////////////////////////////////
int main()
{
  FeetInches feetObject(5, 6);
  
  int inch = feetObject;
  long golly = static_cast<int>(feetObject); 
  
  float f_inch = feetObject;
  double d_inch = static_cast<float>(feetObject); 
  
  string inch_str = feetObject;
  
  cout<<"int inch: "<< inch <<" Float inch: "<<showpoint<<f_inch << endl;
  
  
  cout<<"String inch: "<< inch_str << endl; 
  return 0;   
}
 
