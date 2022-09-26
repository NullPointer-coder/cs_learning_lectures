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


class Point
{ public:
    // constructor, also default constructor
    Point(int x_val = 0, int y_val =0)
    {   x = x_val;
        y = y_val;
    }
       
    Point operator+(const Point & right_param)
    { 
      Point temp_point (x + right_param.x, y + right_param.y);
      return temp_point;
    }
    int getX()  { return x;} 
    int getY()  { return y;}
    void setX(int x_param){ x = x_param; }
    void setY(int y_param){ y = y_param; }
   
  private:
    int x, y;
};

///////////////////////////////////////////////////
int main()
{
  Point right (10, 20);
  Point left (20, 30);  
  Point center;
   
  //center = left.operator+(right); 
  center = left + right;
  
  cout<<"center(x,y) = {"<<center.getX()<<", "<<center.getY()<<"}"<<endl; 
  
  
  
  return 0;   
}
 
