#include <iostream>

using namespace std;

template <class T>
class CopyConstructor
{
private:
  T variableOne;
  T variableTwo;
public:
  CopyConstructor(T variableOne, T variableTwo)
  {
    this->variableOne = variableOne;
    this->variableTwo = variableTwo;
  }
};