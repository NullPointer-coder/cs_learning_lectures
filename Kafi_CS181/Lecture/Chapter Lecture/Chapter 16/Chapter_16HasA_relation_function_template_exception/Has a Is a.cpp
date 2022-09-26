#include<iostream>
#include <string>
#include <vector>

using namespace std;

// has a relationship example
class CCourse
{
private:
 string booktitle; //"has a" book
 string professor; // "has a" professor
 vector<CCourse> students; // has students
public:

 };

// is a relationship example
class Animal
{
private:
 string name:
public:

};

class Cat: public Animal
{
 // here the cat inherits the attributes of the animal class
 // therefore, the cat "is a(n)" animal
public:

};