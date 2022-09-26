#include <iostream>
#include <string>
#include <fstream>

using namespace std;
// CStudent class information
class CStudent
{ 	int id;
	string name;
	public:
		// default constructor
		CStudent(string n="", int i=0)
		{	name = n; 
			id = i;
		}
		// string formatting
		string to_string()
		{	return name + " : " + std::to_string(id);	} 
};

// a program to illustrate how to append data to a file
int main()
{	CStudent james("james", 1);		
	CStudent sabiha("sabiha", 5);
		
	// open binary file and write contents of two objects
	fstream outfile("binary.dat", ios::out | ios::binary);
	
	outfile.write(reinterpret_cast<char *> (&james), sizeof(CStudent));
	outfile.write(reinterpret_cast<char *> (&sabiha), sizeof(CStudent));
	outfile.close();
	
	// read the content of the binary file
	fstream infile("binary.dat", ios::in | ios::binary);
	
	// display the things from the file
	CStudent st_var;
	// as long as we can read content from the file, continue
	while(infile.read(reinterpret_cast<char *> (&st_var), sizeof(CStudent)) )
	{	cout<<st_var.to_string()<<endl; 
	} 

	// done reading
	infile.close();
	
	return 0;
}
