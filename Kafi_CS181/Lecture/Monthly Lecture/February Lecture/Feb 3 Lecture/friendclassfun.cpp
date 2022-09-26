#include <iostream>
using namespace std;

// forward declaration of a class; 
class Movie;

class DisplayThings
{
  public:
  void displayObject(const Movie m);
  
  // can not complete the definition, because we do not know
  // the definition of the Movie class
};


class Movie // class of a Movie 
{ 
  
  // variables
  string title; 
  string director;
  unsigned release_year;
  
  // functions that can use the class variables
  public: 
  
  // constructor
  Movie(string t, string d, unsigned y)
  {
    title = t;
    director = d;
    release_year = y;
  }
  
  //friend class DisplayThings;
  friend void DisplayThings::displayObject(const Movie); 
  
}; // end of the class definition


// the friend function of a class that can access information of a class
void DisplayThings::displayObject(const Movie m)
{
  cout<<m.title<<"; "<<m.director<<" ("<<m. release_year<<")";
} 


// the driver function
int main()
{
  Movie myMovie("Harry Potter", "Chris Columbus", 2001);
  //myMovie.display();
  
  DisplayThings displayVar;  
  displayVar.displayObject(myMovie); 
  return 0; 
}

