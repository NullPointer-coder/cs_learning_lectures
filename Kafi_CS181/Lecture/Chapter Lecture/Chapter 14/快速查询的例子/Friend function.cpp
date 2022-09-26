#include <iostream>
using namespace std;

class Movie // class of a Movie
{ 
private:
  string title; 
  string director;
  unsigned release_year;
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

  friend void displayObject(Movie m);
    
};

void displayObject(Movie m)
{
  m.title = m.title + " 2.0"; 
  cout<<m.title<<"; "<<m.director<<" ("<<m.release_year<<")" << endl; 
  Movie yourMovie("Big Fish", "Tim Burton", 2005) ;
  yourMovie.title = "Big BIG Fish";
  
  cout<< yourMovie.title << endl;
} 
