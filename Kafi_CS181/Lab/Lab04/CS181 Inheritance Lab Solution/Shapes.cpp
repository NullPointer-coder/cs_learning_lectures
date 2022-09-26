//A program for calculating the areas of various shapes
#include <iostream>

class BasicShape { //Base class
private:
  double area;
public:
  double getArea() //Accessor
  {
    return area;
  }

  void setArea(double new_area) //Mutator
  {
    area = new_area;
  }

  virtual void calcArea() = 0; //Pure virtual function for use in derived classes
};

class Circle : public BasicShape { //Derived class
private:
  const double PI = 3.14159;
  long centerX;
  long centerY;
  double radius;
public:
  Circle(long x, long y, double r) //Constructor
  {
    centerX = x;
    centerY = y;
    radius = r;
    calcArea();
  }

  long getCenterX() const //Accessor
  {
    return centerX;
  }

  long getCenterY() const //Accessor
  {
    return centerY;
  }

  /**
    Calculates the area of a given circle.
  */
  void calcArea() override;
};

void Circle::calcArea()
  {
    double area = PI * radius * radius;
    setArea(area);
  }

class Rectangle : public BasicShape { //Derived class
private:
  long width;
  long length;

public:
  Rectangle(long w, long l) //Constructor
  {
    width = w;
    length = l;
    calcArea();
  }

  long getWidth() const //Accessor
  {
    return width;
  }

  long getLength() const //Accessor
  {
    return length;
  }

  /**
    Calculates the area of a given rectangle.
  */
  void calcArea() override;
};

void Rectangle::calcArea()
  {
    double area = length * width;
    setArea(area);
  }

int main()
{
  Circle new_circle(15, 24, 7); //Makes a new circle object
  Rectangle new_rectangle(33, 25); //Makes a new rectangle object

  std::cout << "Circle with center: (" << new_circle.getCenterX() << ", " << new_circle.getCenterY() << ") and area: " << new_circle.getArea() << std::endl;
  std::cout << "Square with width: " << new_rectangle.getWidth() << ", length: " << new_rectangle.getLength() << ", and area: " << new_rectangle.getArea() << std::endl;

  return 0;
}
 