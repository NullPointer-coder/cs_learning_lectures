// Jingbo Wang
// Find out the secret password by completing the following program

#include <iostream>
using namespace std;


int main()
{

  // this value can be between 1 and 5: change the value to figure out
  // the right key
  unsigned secret_key = 2;

  /* variable names with initial value, these values are imortant */
  char aletter = 66, bletter = 83, cletter = 65, dletter = 73;


  cout<< "Once upon a time, there was a ";
  // an animal that can swim
  cout<< char(aletter + secret_key);
  cout<< char(bletter + secret_key);
  cout<< char(cletter + secret_key);
  cout<< char(dletter + secret_key);

  return 0;
}




