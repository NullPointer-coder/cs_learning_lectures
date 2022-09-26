#include<iostream>
#include<exception>

using namespace std;
class MyException : public std::runtime_error
{
public:
  MyException(): std::runtime_error("Error: Out of the boundary"){}
};

int main()
{
  int input;
  try
  {
    cout << "Please input: ";
    cin >> input;
    if(input > 10)
    {
      throw MyException();
    }
  }
  catch(const std::exception& e)
  {
    cout << e.what() << endl;
  }
}