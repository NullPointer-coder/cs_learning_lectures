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
	{
		return name + " : " + std::to_string(id);
	}
};

// reading first and last records from a binary file
int main()
{
	const int RECORD_SIZE = 10;
	CStudent records[] = {CStudent("cecilia", 1), CStudent("sam", 2),
						  CStudent("emma", 3), CStudent("rebecca", 4),
						  CStudent("hawon", 5), CStudent("olivia", 6),
						  CStudent("lewis", 7), CStudent("Kamal", 8),
						  CStudent("Henry", 9), CStudent("Kafi", 10)};

	
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
 
	// reading from the binary file
	myfile.clear();				// clearing all flags
	myfile.seekg(0L, ios::beg); // going at the beginning

	CStudent first_CStudent;
	myfile.read(reinterpret_cast<char *>(&first_CStudent), sizeof(CStudent));
	cout << "First record \t" << first_CStudent.to_string() << endl;

	myfile.clear();								   // clearing all flags
	myfile.seekg(-1 * sizeof(CStudent), ios::end); // going to the last record

	// myfile.seekg(9L * sizeof(CStudent), ios::beg); // going to the last record

	CStudent last_CStudent;
	myfile.read(reinterpret_cast<char *>(&last_CStudent), sizeof(CStudent));
	cout << "Last record \t" << last_CStudent.to_string() << endl;

	// Done. Closing the random access file
	myfile.close();

	return 0;
}