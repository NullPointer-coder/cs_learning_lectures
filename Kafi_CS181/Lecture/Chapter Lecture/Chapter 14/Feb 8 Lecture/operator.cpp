// @author: 
// ********************

#include <iostream>
#include <cmath>
using namespace std;

class Point2d
{	int x, y;
	double square(double v)
	{ 	return v * v;
	}
	public:
	Point2d(int px, int py)
	{	x = px; y = py;
	}
	double operator-(const Point2d &param)
	{ 	return sqrt(square(x-param.x)
			      + square(y-param.y)); 
	}
	
	 
};

int main()
{
	Point2d left(2,2), right(4,4);
	// compute and display distance between 2 points
	
	double distance = right - left; // right.operator-(left)
	
	cout << distance << endl; // 2.82843  
	return 0;
}
  



