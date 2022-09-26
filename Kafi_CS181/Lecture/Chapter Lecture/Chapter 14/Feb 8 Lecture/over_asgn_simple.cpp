// @author: Kafi Rahman
// The purpose of the program is to store student record information
// by using a collection class

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
};


// display function call uses the copy constructor
void display_point_object(Point & param)
{
  cout<<"Displaying: " << param.getX() << " " 
      << param.getY() << endl;
}

//Point returnObject()
//{
//  Point variable(150, 150);
//  cout << "Address: " << &variable << endl;
//  return variable;
//}

///////////////////////////////////////////////////
int main()
{
  Point center(50, 50);
  Point left = center;
  Point right;
  
  // right.operator=(left); 
  right = left;
  
  // display the content of the right point
  // during a function call when we pass an object as an argument
  // the formal parameter is going to be initialized by using
  // a copy constructor call

  display_point_object(right);
  
  return 0; 
}
 
