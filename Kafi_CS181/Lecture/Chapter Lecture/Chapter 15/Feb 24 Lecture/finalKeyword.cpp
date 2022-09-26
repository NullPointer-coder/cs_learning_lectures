	#include <iostream>
	using namespace std;
	// override a function

	class Mammal
	{	string mammalSound;
	public:
		Mammal()
		{	mammalSound = "Meeeoowww";
		}
		void display() // final: not applicable
		{	cout<< "\nI am a Mammal and I sound: "
				<<getSound();
		}
		virtual string getSound() const final 
		{ return mammalSound; }
	};


class Lion : public Mammal
{
	string lionSound;
public:
	Lion() : Mammal()
	{	lionSound = "Raawwrrrrr";
	}
	// Error: a final function can not
	// be overriden in the derived class
//	string getSound() const 
//	{ return lionSound; } 
};

	// using the derived class
	int main()
	{	Lion theKing;
		theKing.display();
	}

	/* Output of the program: */
		// I am a Lion and I sound: Raawwrrrrr 
		
		