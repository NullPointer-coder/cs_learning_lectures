// @author: Kafi Rahman


#include <iomanip>
#include <iostream>
#include <string>

using namespace std; 


class Point
{ private:
    int x, y;
  
  public:
    // constructor, also default constructor
    Point(int px=0, int py =0)
    {   x = px; y = py;
    }
    // copy constructor
    Point(const Point &param)
    {  x = param.x;
       y = param.y; 
       cout<<endl<<"Copy constructor has been called"<<endl; 
    } 
    
    // overloading = operator
    void operator=(const Point &param)
    {   x = param.x;
        y = param.y; 
        cout<<endl<<"Assignment operator has been called"<<endl; 
    }
     
    int getX() { return x;}
    int getY() { return y;}
    void setXY(int px, int py)
    {  x = px; y = py;
    }
    string to_string() const
    {  return "\nx= " + std::to_string(x) + " y= " + std::to_string(y);
    }
};



// this function creates a Point object
Point create_point_object()
{ Point variable(150, 150);
  //cout << "Address: " << &variable << endl;
  return variable;
}


///////////////////////////////////////////////////
int main()
{
  
  
  /**
  Semantically it behaves like copy, but there is something that is called 
  return value optimization (RVO) that does to use the copy constructor.

  left_point would be created as if it was created like the following
  Point left_point (150, 150); // RVO -- optimized by the compiler
  **/
  
  Point left_point = create_point_object();
   
  
  /** 
  instance of Point object created and then copied to center_point
  the old instance would be destroyed
  **/
  Point center_point;
  center_point = create_point_object(); 
  
  /**
  Please note, there's no guarantee that RVO will kick in. 
  The compiler still has freedom to copy, and it must check for a presence of a valid copy constructor 
  even if it chooses not to use it.
  **/
  
  
  return 0; 
}
 
