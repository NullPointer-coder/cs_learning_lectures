// @author: Kafi Rahman


#include <iomanip>
#include <iostream>
#include <string>

using namespace std;


class Point
{ int x, y;
  
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
    string to_string()
    {  return "\nx= " + std::to_string(x) + " y= " + std::to_string(y);
    }
};


// Rectangle class: is comprised of two points
class Rectangle
{ 
  Point left_top, right_bottom;
  public:
  Rectangle()
  { left_top.setXY(0, 0);
    right_bottom.setXY(1024, 768);
  }
  
  Point get_left_top()
  { return left_top; // copy constructor call
  }
  
  Point get_right_bottom()
  { return right_bottom; // copy constructor call
  }
  
  string to_string()
  { return left_top.to_string() + " " + right_bottom.to_string();
  }
  
}; 

///////////////////////////////////////////////////
int main()
{
  Rectangle window;
  Point x_left_top = window.get_left_top(); // one copy constructor
  /**
  this will be a copy constructor call
  **/
  
  Point x_right_bottom;
  x_right_bottom = window.get_right_bottom(); 
  /**
  this will call the copy constructor
  and the overloaded assignment operator member function
  **/
  return 0; 
}
 
