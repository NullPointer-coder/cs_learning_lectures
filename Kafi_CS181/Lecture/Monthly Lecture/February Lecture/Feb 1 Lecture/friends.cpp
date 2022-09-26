#include <iostream>
using namespace std;

class Movie // class of a Movie
{ // variables
  string title; 
  string director;
  unsigned release_year;
  
  // functions that can use the class variables
  public:
  
  Movie(string t, string d, unsigned y)
  {
    title = t;
    director = d;
    release_year = y;
  }
  string get_title() { return title;}
  string get_director() { return director;}
  unsigned get_release_year() { return  release_year;}
  
  // friend function
  friend void displayObject(Movie m);
    
}; // end of the class definition


// stand alone function, not part of any class
void displayObject(Movie m)
{
  // usual approach:
  // cout<<m.get_title()<<"; "<<m.get_director()<<" ("<<m.get_release_year()<<")";
  
  // friend function approach:
  m.title = m.title + " 2.0"; 
  cout<<m.title<<"; "<<m.director<<" ("<<m.release_year<<")" << endl; 
  // any object of Movie class would be super object
  // and have access to instance variables directly  
  Movie yourMovie("Big Fish", "Tim Burton", 2005) ;
  yourMovie.title = "Big BIG Fish";
  
  cout<< yourMovie.title << endl;
} 


 
int main()
{
  Movie myMovie ("Harry Potter", "Chris Columbus", 2001) ;
  //myMovie.display();
  displayObject(myMovie); 
  return 0; 
}

