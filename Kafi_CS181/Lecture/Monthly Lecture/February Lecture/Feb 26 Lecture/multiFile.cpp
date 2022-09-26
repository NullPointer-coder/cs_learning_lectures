#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

// void smallProg()
// {
// 	int *p = new int(66);
// 	char *ch = reinterpret_cast<char *>(p);
// 	cout << *p << endl;
// 	cout << *ch << endl;
// }

// driver function
int main()
{
		fstream infile, outfile;
	infile.open("data.txt", ios::in);

	// smallProg();

	// if(infile.fail() == true) or, if(infile.is_open() == false)
	if (!infile) // verify if the file exist
	{
		cout << "\nInvalid input file name: data.txt";
		return 0; // exit the program
	}

	// open the output file
	outfile.open("outdata.txt", ios::out);
	// as long we can read from the input file
	while (infile) // infile.eof() == false
	{
		char letter;
		infile.get(letter); // read a char
		// write to the output file
		outfile.put(toupper(letter));
	}
	cout << "\nDone..";
	// close both of the files
	infile.close();
	outfile.close();
}


