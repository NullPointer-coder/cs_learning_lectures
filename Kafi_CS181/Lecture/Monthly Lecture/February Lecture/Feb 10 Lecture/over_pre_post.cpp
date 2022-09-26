// @author: Kafi Rahman

#include <iomanip>
#include <iostream>
#include <string>

using namespace std;


class Point
{ int x, y;

  public:
    // constructor, also default constructor
    Point(int x_val = 0, int y_val =0)
    {   x = x_val;
        y = y_val;
    }
       
    Point operator++() // prefix
    { x++;
      y++;
      Point current (x, y);
      return current; 
    }
    
    Point operator++(int) // postfix
    { Point current (x, y);
      x++;
      y++;
      return current;  
    }
     
    int getX()  { return x;}
    int getY()  { return y;}
    void setX(int x_param){ x = x_param; }
    void setY(int y_param){ y = y_param; }
    
    string to_string()
    {  return "\t(x, y) = {" + std::to_string(x) + ", " + std::to_string(y) + "}";
    }
  };
 

///////////////////////////////////////////////////
int main()
{ 
  
  Point right (10, 20);
  Point left;  
  //left= right.operator++(0); // postfix
  left = right++; 
  
  cout<<"left "<<left.to_string()<<endl;
  cout<<"right "<< right.to_string() <<endl<<endl;
  
  left ++; //left.operator++(0);
  cout<<"left "<<left.to_string()<<endl<<endl;
  
  //left= right.operator++(); // prefix
  left = ++ right; 
  
  cout<<"left "<<left.to_string()<<endl;
  cout<<"right "<< right.to_string() <<endl;  
    
  return 0;   
}
 
