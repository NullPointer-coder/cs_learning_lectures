
#include <iostream>
#include <cstdlib>

using namespace std;


class FeetInches
{
  private:
    int feet;
    int inches;
    void simplify();

  public:
    FeetInches(int f = 0, int i = 0)
    {
      feet = f;
      inches = i;
      simplify();
    }

    FeetInches(const FeetInches &f) //The copy constructor for part b
    {
      feet = f.feet;
      inches = f.inches;
    }

    void setFeet(int f)
    {
      feet = f;
    }

    void setInches(int i)
    {
      inches = i;
      simplify();
    }

    int getFeet() const
    {
      return feet;
    }

    int getInches() const
    {
      return inches;
    }

    FeetInches operator + (const FeetInches &);
    FeetInches operator - (const FeetInches &);
    FeetInches operator++ ();
    FeetInches operator++ (int);

    bool operator > (const FeetInches &);
    bool operator < (const FeetInches &);
    bool operator == (const FeetInches &);
    bool operator <= (const FeetInches &);
    bool operator >= (const FeetInches &);
    bool operator != (const FeetInches &);

    friend ostream &operator << (ostream &, const FeetInches &);
};

void FeetInches::simplify()
{
  if (inches >= 12)
  {
    feet += (inches / 12);
    inches %= 12;
  }
  else if (inches < 0)
  {
    feet -= ((abs(inches) / 12 ) + 1);
    inches = 12- (abs(inches) % 12);
  }
}

bool FeetInches::operator > (const FeetInches &right)
{
  if (feet > right.feet)
  {
    return true;
  }
  else if (feet == right.feet && inches > right.inches)
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool FeetInches::operator < (const FeetInches &right)
{
  if (feet < right.feet)
  {
    return true;
  }
  else if (feet == right.feet && inches < right.inches)
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool FeetInches::operator == (const FeetInches &right)
{
  return (feet == right.feet && inches == right.inches);
}


// bu using existing overloaded member functions
bool FeetInches::operator >= (const FeetInches &right) //overloads >=
{
  return (*this > right || *this == right);
}

// creating your own comparision routine
bool FeetInches::operator <= (const FeetInches &right) //overloads <=
{
  if (feet < right.feet)
  {
      return true;
  }
  else if (feet == right.feet)
  {
      return inches <= right.inches;
  }
  else
  {
      return false;
  }
}

bool FeetInches::operator != (const FeetInches &right) //overloads !=
{
  return !(*this == right);
}

ostream &operator << (ostream &out, const FeetInches &f) //overloaded ostream
{
  out << f.feet <<" feet, "<< f.inches << " inches";
  return out;
}

int main()
{
  //part A
  cout << "\nFor part A:\n";
  int feet, inches;
  FeetInches first, second;

  cout << "Enter a distance in feet and inches: ";
  cin >> feet >> inches;
  first.setFeet(feet);
  first.setInches(inches);

  cout << "Enter another distance in feet and inches: ";
  cin >> feet >> inches;
  second.setFeet(feet); 
  second.setInches(inches);

  if (first != second)
  {
    cout << "First doesn't equal second" << endl;
  }
  if (first >= second)
  {
    cout << "First is greater than or equal to second" << endl;
  }
  if(first <= second)
  {
    cout << "First is less than or equal to second" << endl;
  }

  //part B
  cout << "\nFor Part B:\n";
  FeetInches third = second; //calls copy constructor
  if(third <= second)
  {
    cout << "First is less than or equal to copied second" << endl;
  }
  //part C
  cout << "\nFor Part C:\n";
  FeetInches box_length(10, 2);
  cout << box_length << endl ; // will print: 10 feet and 2 inches

  return 0;
}
