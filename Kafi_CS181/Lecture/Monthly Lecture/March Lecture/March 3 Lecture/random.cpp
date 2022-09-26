#include <iostream>
#include <string>
#include <fstream>


using namespace std;

class CStudent
{
	int id;
	string name;

public:
	// default constructor
	CStudent(string n = "", int i = 0)
	{ 
		name = n;
		id = i;
	}
	string getName()
	{
		return name;
	}
	// string formatting
	string to_string()
	{	return name + " : " + std::to_string(id); 
	}
};

// a program to illustrate how to append data to a file
int main()
{
	const int RECORD_SIZE = 7;
	CStudent records[] = {CStudent("cecilia", 1), CStudent("sam", 2),
						  CStudent("emma", 3), CStudent("rebecca", 4),
						  CStudent("hawon", 5), CStudent("olivia", 6),
						  CStudent("lewis", 7)};

	
	// bug work around
	fstream demo_open("binary.dat", ios::out); 
	demo_open.close();
	
	// open binary file and write contents of two objects	
	fstream myfile("binary.dat", ios::out | ios::binary | ios::in);

	for (auto st_var : records) // writing all objects in the file
	{
		myfile.write(reinterpret_cast<char *>(&st_var), sizeof(CStudent));
	}

	cout << "\nWriting to the file was successful!" << endl;

	myfile.clear();									// clearing all flags
	myfile.seekp(-2L * sizeof(CStudent), ios::cur); // going two records back
	cout << endl
		 << "Position after the 5th record: " << myfile.tellp() << endl;

	// replacing the 6th record in the file
	CStudent new_CStudent("alicia", 9);
	myfile.write(reinterpret_cast<char *>(&new_CStudent), sizeof(CStudent));

	// now, display everything from the file
	myfile.clear();				// clearing all flags
	myfile.seekg(0L, ios::beg); // going to the beginning of the file

	cout << "\nDisplaying all the CStudent records .." << endl;

	CStudent st_var;
	while (myfile.read(reinterpret_cast<char *>(&st_var), sizeof(CStudent)))
	{
		cout << st_var.to_string() << endl;
	}

	// Done. closing the random access file
	myfile.close();

	return 0;
}