#include <iostream>

using namespace std;

class Point{
	private:
		int x, y;
	public:
		Point(int xp, int yq)
		{
			x = xp;
			y = yq;
		}
		void display()
		{
			cout<< this->x << ":" << this->y <<endl;
			
		}
}; 

int main() {
	Point pt_right (50, 30), pt_left (10, 50);
	pt_left.display();
	pt_right.display();
	
	return 0;
}