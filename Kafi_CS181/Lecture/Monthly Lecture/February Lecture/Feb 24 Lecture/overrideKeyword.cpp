#include <iostream>
using namespace std;
// override a function

class Mammal
{	string mammalSound;
public:
	Mammal()
	{	mammalSound = "Meeeoowww";
	}
	void display()
	{	cout<< "\nI am a Mammal and I sound: "
			<<getSound();
	}
	virtual string getSound() const 
	{ return mammalSound; }
};



class Lion : public Mammal
{
	string lionSound;
public:
	Lion() : Mammal()
	{	lionSound = "Raawwrrrrr";
	}
	string getSound() const override  
	{ return lionSound; }
	
		
	void display() // override: not applicable
	{	cout<< "\nI am a Mammal and I sound: "
			<<getSound();
	}
};

// using the derived class 
int main()
{	Lion theKing;
	theKing.display();
} 

/* Output of the program: */
	// I am a Lion and I sound: Raawwrrrrr
	
	