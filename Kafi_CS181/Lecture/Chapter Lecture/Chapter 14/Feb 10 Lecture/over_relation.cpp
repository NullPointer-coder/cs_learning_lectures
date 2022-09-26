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
    Point(int x_val = 0, int y_val =0)
    {   x = x_val;
        y = y_val;
    }
    // copy constructor, overloading is unnecessary
    Point(const Point & p_obj)
    {   x = p_obj.x; 
        y = p_obj.y;
        cout<<endl<<"Copy constructor has been called"<<endl; 
    } 
    
    Point operator=(const Point &p_obj)
    {   x = p_obj.x; 
        y = p_obj.y;
      
        cout<<endl<<"Assignment operator has been called"<<endl; 
        return *this; // temporary variable will be created
    }       

    bool operator <(const Point &p_obj)
    {   if (x< p_obj.x)
          return true;
        else if(x == p_obj.x)
          return y<p_obj.y;
        // otherwise;
        return false;
      
    }
    
    bool operator> (const Point &p_obj)
    {   if (x> p_obj.x)
          return true;
        else if(x == p_obj.x)
          return y>p_obj.y;
        // otherwise;
        return false;
      
    }
    
    bool operator == (const Point &p_obj)
    {   if (x== p_obj.x && y == p_obj.y)
          return true;
        // otherwise;
        return false;
      
    }
     
    int getX()  { return x;}
    int getY()  { return y;}
    void setX(int x_param){ x = x_param; }
    void setY(int y_param){ y = y_param; }
};


///////////////////////////////////////////////////
int main()
{
  Point center_point (1000, 500);
  Point right_point (1000, 500);
  
  // center_point.operator<(right_point)
  if(center_point < right_point) // operator overloading
  {
    cout<<"Center is to the left or down with respect to the right point" << endl;
  }
    
  //else if(center_point.operator==(right_point)) // operator overloading: actual call
  else if(center_point == right_point) // operator overloading
  {
    cout<<"Center is equal to the right point" << endl;
  }
  else if(center_point > right_point) // operator overloading
  {
    cout<<"Center is to the right or up with respect to the right point";
  }
  return 0;   
}
 
