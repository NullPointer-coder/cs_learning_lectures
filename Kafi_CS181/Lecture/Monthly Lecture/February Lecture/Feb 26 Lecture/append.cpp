#include <iostream>
#include <fstream>
using namespace std;



// driver function
int main()
{
	fstream outfile;
	outfile.open("data.txt", ios::app);
	
	// if the file does not exist, it will be created
	
	cout <<"Appending new data to the file " << endl;
	outfile << "Ferrari, 2021, Justin Trudeau" << endl;
	
	cout <<"Done" << endl;
	
	outfile.close();
}
