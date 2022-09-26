 
#include<fstream>//required for file operation:
#include<iostream>//required for input/output:
using namespace std;

// driver function
int main()
{
	ofstream fout; 
	
	string line;     
	char text;       // character variable to read data from file:
 
	cout<<"Enter some text here: "<<endl;
	getline(cin, line);  //getline function
 	
	//opening file for Writing:
	fout.open("Info.txt", ios::out);  
	
	fout<<line<<endl;
	fout.seekp(-7L * sizeof(char), ios::cur); // go back 7 chars
	
	if(fout.tellp()>= 0L) // make sure it is a valid position
	{
		fout<<"forest ";
	}
		
	cout<<"Data stored Successfully: \n\n"<<endl;
	
	fout.close(); //file close:
		 
	
    fstream fin;   // file variable for reading: 
	fin.open("Info.txt", ios::in); 
	
	if(fin.fail()==false) // was file open successful
	{
		while(fin.get(text)) // read chars one at a time and display them
		{
			cout<<text; //display data:
		}
	}
	
	fin.close(); //file close:
 
	return 0; 
}
