#include <iostream>
#include <string>

using namespace std;

template <class T>
class Storage
{
private:
  T *array;
  int size;
public:
//Constructor
  Storage(int length);
//Copy constructor
  Storage(const Storage &elem);
  ~Storage();
  T &operator[](const int &index);
};
template<class T>
Storage<T>::Storage(int length)
{
  size = length;
  array = new T [size];
}
template <class T>
T &Storage<T>::operator[](const int &index)
{
  return array[index];
}
template <class T>
Storage<T>::Storage(const Storage &elem)
{
  cout << "Copy constructor is called!";
  size = elem.size;
  array = new T [size];
  for(int count = 0; count < size; count++)
  {
    *(array + count) = *(elem.array+count);
  }
}
template<class T>
Storage<T>::~Storage()
{
  // release all the allocated memory
  delete[] array;
  std::cout << "Deleting all the array elements ..." << std::endl;
};