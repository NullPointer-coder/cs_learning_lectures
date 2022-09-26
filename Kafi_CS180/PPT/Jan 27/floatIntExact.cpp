// This program shows float imprecision

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
  float value = 0.7F;
  float multiplier = 64.0F;
  
  cout << "0.7 times 64 should be 44.8, but the computer thinks it's: " << setprecision(10)
       << value * multiplier << endl;
       //<<"size of:"<<sizeof(value)<<" bytes";

  return 0;
}


class Circle
{
  private:
    int x, y;
    double r;
    // private function
    double square(double v) 
    {
      return v * v;
    }
  public:
    // constructor that takes three parameters
    // also is a default constructor
    Circle(int x_param=0, int y_param=0, double r_param=0)
    {
      x = x_param; y = y_param; r = r_param;
    }
    // calculates and regurns the area of the cirlce
    double getArea()
    {
      const double PI = 3.14159f;
      return PI * square(r);
    }
};
  