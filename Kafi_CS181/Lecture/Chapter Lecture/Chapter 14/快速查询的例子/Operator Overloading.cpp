
#include <iostream>
#include <cstdlib>

class FeetInches;

std::ostream &operator<<(std::ostream &, const FeetInches &);
std::istream &operator>>(std::istream &, FeetInches &);

class FeetInches
{
private:
    int feet;
    int inches;
public:
    FeetInches operator+(const FeetInches &) const;
    FeetInches operator-(const FeetInches &) const;
    FeetInches operator * (const FeetInches &) const;
    FeetInches operator / (const FeetInches &) const;
    bool operator>=(const FeetInches &) const;
    bool operator<=(const FeetInches &) const;
    bool operator==(const FeetInches &) const;
    bool operator!=(const FeetInches &) const;
    friend std::ostream &operator<<(std::ostream &, const FeetInches &);
    friend std::istream &operator>>(std::istream &, FeetInches &);
    void simplify();
};
void FeetInches::simplify()
{
  if (inches >= 12)
  {
    feet += (inches / 12);
    inches = inches % 12;
  }
  else if (inches < 0)
  {
    feet -= ((abs(inches) / 12) + 1);
    inches = 12 - (abs(inches) % 12);
  }
}

FeetInches FeetInches::operator+(const FeetInches &right) const
{
  FeetInches temp;

  temp.inches = inches + right.inches;
  temp.feet = feet + right.feet;
  temp.simplify();
  return temp;
}

FeetInches FeetInches::operator-(const FeetInches &right) const
{
  FeetInches temp;

  temp.inches = inches - right.inches;
  temp.feet = feet - right.feet;
  temp.simplify();
  return temp;
}

FeetInches FeetInches::operator*(const FeetInches &right) const
{
  FeetInches temp;
  temp.feet = (this -> feet * right.feet) - (this -> inches * right.inches);
  temp.inches = (this -> inches * right.inches) + (this -> inches * right.feet);
  temp.simplify();
  return temp;
}

FeetInches FeetInches::operator/(const FeetInches &right) const
{
  FeetInches temp;
  temp.feet = ((this -> feet * right.feet) + (this -> inches * right.inches)) / (right.feet * right.feet + right.inches * right.inches);
  temp.inches = ((this -> inches * right.feet) - (this -> feet * right.inches)) / (right.feet * right.feet + right.inches * right.inches);
  return temp;
}

bool FeetInches::operator>=(const FeetInches &right) const
{
  bool status;
  if (feet >= right.feet)
  {
    status = true;
  }
  else
  {
    status = false;
  }
  return status;
}

bool FeetInches::operator<=(const FeetInches &right) const
{
  bool status;
  if (feet <= right.feet)
  {
    status = true;
  }
  else
  {
    status = false;
  }
  return status;
}

bool FeetInches::operator!=(const FeetInches &right) const
{
  bool status;
  if (feet != right.feet && inches != right.inches)
  {
    status = true;
  }
  else
  {
    status = false;
  }
  return status;
}
bool FeetInches::operator==(const FeetInches &right) const
{
  bool status;
  if (feet == right.feet && inches == right.inches)
  {
    status = true;
  }
  else
  {
    status = false;
  }
  return status;
}
std::ostream &operator<<(std::ostream &stream_insertion, const FeetInches &obj)
{
  stream_insertion << obj.feet << " feet, " << obj.inches << " inches";
  return stream_insertion;
}
std::istream &operator>>(std::istream &stream_extraction, FeetInches &obj)
{
  std::cout << "Feet: ";
  stream_extraction >> obj.feet;
  std::cout << "Inches: ";
  stream_extraction >> obj.inches;

  obj.simplify();
  return stream_extraction;
}