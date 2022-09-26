
#include <fstream> //required for file operation:
#include <iostream>
using namespace std;

// driver function
int main()
{
	string line; // arguments, Name & size of Array.
	char text;	 // character variable to read data from file:

	fstream fin; //Object for reading:
	fin.open("Info.txt", ios::in);
	if (fin.fail() == true) 
	{
		cout << "File open error " << endl;
		return 0;
	} 
 
	fin.clear();
	fin.seekg(7L * sizeof(char), ios::beg);	 // skip first 7 chars from beginning:
	fin.seekg(-2L * sizeof(char), ios::cur); // then move back 2 chars from current position:

	cout << "Output (after skipping first 7 chars and then move 2 chars back) is: " << endl;
	while (fin.get(text)) //read data from file till end of file:
	{
		cout << text;
	}

	cout << endl; 
	fin.close(); //file close:
	return 0;
}
