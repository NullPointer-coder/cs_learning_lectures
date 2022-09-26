#include <iostream>
using namespace std;
// override a function

class Mammal
{	string mammalSound;
	public:
	Mammal()
	{	mammalSound = "Meeeoowww";
	}
	void display()  // =0; not applicable
	{	cout<< "\nI am a Mammal and"
			<<"I sound: "<<getSound();
	}
	virtual string getSound() const  = 0;
};


class Lion : public Mammal
{
	string lionSound;
public:
	Lion() : Mammal()
	{	lionSound = "Raawwrrrrr";
	}
	
	// be overriden in the derived class
	string getSound() const override
	{ return lionSound; }
};

// Purpose of the object of the
// abstract class
int main()
{	Mammal * myMammal = new Lion();
	myMammal->display();
} 

// Output: base class object
// of an abstract class can be
// assigned the object of the
// derived classes
 


/* Output of the program: */
	// I am a Lion and I sound: Raawwrrrrr 
		
		