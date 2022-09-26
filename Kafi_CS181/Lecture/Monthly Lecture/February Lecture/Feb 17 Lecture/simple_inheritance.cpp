#include <iostream>

using namespace std;

// Base class
class Shape
{	private:
		string shape_name;
	public:
		Shape(string s_n = "") { shape_name = s_n;}
		
		void set_shape_name(string s_n){ shape_name = s_n;}
		string get_shape_name() const { return shape_name;}
		
};
			
// Derived class
class Square: public Shape
{	// This class has now has:
	// shape_name
	// set_shape_name()
	// get_shape_name()
	
	private:
		int width;
	public:
		// using Shape::Shape;		
		Square(string s_n, int w) //: Shape (s_n)
		{	set_shape_name(s_n);
			width = w; 
		}
		
		int get_width() const { return width; }
};
 
int main()
{
	Square my_square ("Box", 100); 
	cout << my_square.get_shape_name() << " " << my_square.get_width() << endl;
	return 0; 
}
