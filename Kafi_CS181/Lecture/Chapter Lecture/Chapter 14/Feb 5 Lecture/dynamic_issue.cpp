// @author: 
// ********************

#include <iostream>
#include <string>
using namespace std;

class Student 
{
	int * id;
	string name;
	
	public:
		Student(int id_value, string name_value)
		{
			id = new int;
			*id = id_value;
			name = name_value;
		}
		
		Student (const Student & right_object)
		{ 	
			id = new int;
			*id = *right_object.id;
			name = right_object.name;
		}
		
		~Student()
		{	
			delete  id;
		}
		void set_id(int id_value)
		{
			*id = id_value;
		}
		string to_string()
		{ return std::to_string(*id) + "; " + name;
		}
};

// driver program
int main()
{	
	Student first (101, "John"); 
	cout<< first.to_string() << endl;
	
	Student second = first; // second.id = first.id
	//cout<< second.to_string() << endl;
	
	second.set_id(107);
//	 cout<< second.to_string() << endl;
//	 
	cout<< first.to_string() << endl;
		
	return 0;
}





