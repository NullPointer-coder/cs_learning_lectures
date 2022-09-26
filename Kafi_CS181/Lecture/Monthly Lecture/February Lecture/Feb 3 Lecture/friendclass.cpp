#include <iostream>
using namespace std;

// forward declaration of a class; 
class DisplayThings;

class Movie // class of a Movie
{ 
  friend class DisplayThings;
  
  // variables
  string title; 
  string director;
  unsigned release_year;
  
  // functions that can use the instance variables
  public: 
  
  // constructor
  Movie(string t, string d, unsigned y)
  {
    title = t;
    director = d;
    release_year = y;
  }
  
}; // end of the class definition


// the friend class implementation
class DisplayThings
{
  public:
  // this function displays the content of an object
  void displayObject(const Movie m)
  {
    cout<<m.title<<"; "<<m.director<<" ("<<m. release_year<<")";
  }
  // this function determines if two objects are equal
  bool compare_two_movies(const Movie first, const Movie second)
  {
    return (  first.title == second.title && 
              first.director == second.director &&
              first.release_year == second.release_year );
  }
};


// the driver function
int main()
{
  Movie good_movie("Harry Potter", "Chris Columbus", 2001);
  //myMovie.display();
  
  DisplayThings util; 
  util.displayObject(good_movie);  
  
  Movie great_movie("Big Fish", "Tim Burton", 2005);
  cout<<"\nThe two objects are equal: " << util.compare_two_movies(good_movie, good_movie) << endl; 
  return 0;  
} 

