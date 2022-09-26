#include <iostream>
#include <fstream>
using namespace std;

void displayErrorBits(const fstream &infile)
{
	cout << "EOF:" << infile.eof() << " "
		 << "BAD:" << infile.bad() << " "
		 << "GOOD:" << infile.good() << " "
		 << "FAIL:" << infile.fail() << endl;
}

// driver function
int main()
{
	fstream infile;
	infile.open("data.txt", ios::in);

	cout << "\nAfter openning the file .." << endl;
	displayErrorBits(infile);

	if (infile.is_open() == false) // if(!infile)
	{
		cout << "\nFile open unsuccessful .. " << endl;
		return 0;
	}
	string dataItem; 

	cout << "\n\nFile contents .." << endl;
	while (infile.eof() == false) // while (infile)
	{
		getline(infile, dataItem, ','); // third parameter is '\n'
		cout << dataItem << " ";
	}

	cout << "\nAfter reading the file .." << endl;
	displayErrorBits(infile); 

	// cout << "\nstill valid infile: " << infile << endl;
	infile >> dataItem;

	cout << "\nAfter attmpting an invalid read operation .." << endl;
	displayErrorBits(infile);
}
