package helloWorld;

import java.util.Scanner;

class Student extends Person {
	private float cgpa;

	public Student(String name, String address, float cgpa) {
		super(name, address);
		this.cgpa = cgpa;
	}

	public Student(String n, String ad) {
		this(n, ad, 0f);
	}

	public float getCgpa() {
		return cgpa;
	}

	public void setCgpa(float cgpa) {
		this.cgpa = cgpa;
	}

	public void InputStudent() {
		super.InputPerson();
		Scanner cin = new Scanner(System.in);

		System.out.println("Enter cgpa: ");
		if (cin.hasNextFloat()) {
			this.cgpa = cin.nextFloat();
			cin.nextLine(); // consume the newline character
		}

		cin.close();
	}

	// a static method -- can't override
	// however, we can define the function again
	// @Override
	public static void theSuperStaticMethod() {

		Person.theSuperStaticMethod();
		// Person.theSuperStaticMethod();
	}


	public void display() {
		System.out.println("Student [name=" + this.name + ", address=" + this.getAddress() + ", CGPA= " + cgpa + "]");

	}

	@Override
	public String toString() {
		return super.toString() + " Student [cgpa=" + cgpa + "]";
	}
}
