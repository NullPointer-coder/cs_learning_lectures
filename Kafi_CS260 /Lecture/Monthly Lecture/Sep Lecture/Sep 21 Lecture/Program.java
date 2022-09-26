/**
 * 
 */
package helloWorld;

import java.util.ArrayList;

/**
 *
 *
 */
public class Program {

	// polymorphism
	public static void subTypePolymorphicDisplay(Person myPerson) {
		myPerson.display();
	}

	public static void main(String[] args) {

		Object obj = new Student("James Holland", "Kirksville", 4.0f);
		System.out.println(obj.toString());

		ArrayList<Person> contents = new ArrayList<Person>();


		Student myStudent = new Student("James Holland", "Kirksville", 4.0f);
		// myStudent.display();
		// subType polymorphism
		subTypePolymorphicDisplay(myStudent);
		System.out.println(myStudent.name);

		contents.add(myStudent);

		Employee myEmployee = new Employee("John Mark", "Kirksville", 20.0f, 40);
		contents.add(myEmployee);

//		System.out.println(myStudent.toString());
//		System.out.println(myEmployee.toString());
//
//		// instanceof operator
//		if (myStudent instanceof Student) {
//			System.out.println("Object is a Student");
//		}
//		if (myStudent instanceof Person) {
//			System.out.println("Student is a Person");
//		}

		for (Person p : contents) {
			p.display();
		}
		// subTypePolymorphicDisplay(myEmployee);
		
	}

}