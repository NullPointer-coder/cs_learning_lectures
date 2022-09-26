// @author: Kafi Rahman

#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

class Point
{   int x, y;
  public: 
    // constructor, also default constructor
    Point(int x_val = 0, int y_val =0)
    {   x = x_val;
        y = y_val;
    }
    
    friend ostream & operator << (ostream &out, const Point &c); // cout
    friend istream & operator >> (istream &in,  Point &c);  // cin
  
         
    int getX() const  { return x;}
    int getY() const { return y;}
    void setX(int x_param){ x = x_param; }
    void setY(int y_param){ y = y_param; }
    
}; 

  

 // overloading cout<< in order to display object values
ostream & operator << (ostream &out, const Point &p) 
{ 
  out << "(x, y) = {"<<p.x<<", "<<p.y<<"}";
  return out; 
} 

// oceraloding cin>> in order to input an object values
istream & operator >> (istream &in,  Point &p) 
{ 
  cout << "Enter X: "; 
  in >> p.x; 
  
  cout << "Enter Y: "; 
  in >> p.y;
   
  return in; 
} 
 


///////////////////////////////////////////////////
int main()
{
  Point left_point; 
  
  cout<<"Input values for the left point" << endl;
  cin>>left_point;
  
  cout<<endl<<endl<< "Displaying the input values " << endl;
  cout<<left_point<<endl;
  
  return 0;    
}
 
