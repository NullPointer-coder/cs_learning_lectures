package helloWorld;

import java.util.Scanner;

abstract class Person {
	protected String name;

	private String address;

	public Person() {
		this.name = "";

		this.address = "";
	}

	public Person(String n, String ad) {
		this.name = n;
		this.address = ad;
	}

	public void InputPerson() {
		Scanner cin = new Scanner(System.in);

		System.out.println("Enter name: ");
		this.name = cin.nextLine();

		System.out.println("Enter address: ");
		this.address = cin.nextLine();

		cin.close();
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public String getAddress() {
		return address;
	}

	public void setAddress(String address) {
		this.address = address;
	}

	// a static method
	public static void theSuperStaticMethod() {

	}

	// this method does not allow override in the subclass
	final void theFinalMethod() {
		System.out.println("I am final -- cant be overriden");
	}

	// abstract method
	// must be implemented in the derived class
	abstract public void display();
	

	@Override
	public String toString() {
		return "Person [name=" + name + ", address=" + address + "]";
	}

}
