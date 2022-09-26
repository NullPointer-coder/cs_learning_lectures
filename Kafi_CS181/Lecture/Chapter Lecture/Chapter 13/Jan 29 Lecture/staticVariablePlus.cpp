// @author: 
// ********************

#include <iostream>
#include <string>
using namespace std;

class Student
{
	int id;
	string name;
	static int student_count;
	public:
		Student(string name);
		~Student()
		{	
			student_count --;
		}
	
		string to_string()
		{ return std::to_string(id) + "; " + name;
		}
};

int Student:: student_count = 0; // requirement

Student:: Student(string n)
{ 	
	name = n;
	student_count ++ ;
	id = student_count;
}

// driver program
int main()
{	cout<<"\nWelcome to the program\n";
	
	Student * ptr_student = new Student ("John");
	cout<< ptr_student -> to_string() << endl;
	delete  ptr_student;
	
	Student * str_student = new Student ("Smith");
	cout<< str_student -> to_string() << endl;
	
	delete str_student;
	
	return 0;
}