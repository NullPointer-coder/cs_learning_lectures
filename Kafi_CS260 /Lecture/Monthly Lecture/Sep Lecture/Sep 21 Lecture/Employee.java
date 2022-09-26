package helloWorld;

import java.util.Scanner;

public class Employee extends Person {
	private float rate;
	private int hour;

	public Employee(String name, String address, float rate, int hour) {
		super(name, address);
		// this.name = name; -- allowed, since it is a protected member
		this.rate = rate;
		this.hour = hour;
	}

	public Employee(String n, String ad) {
		this(n, ad, 0f, 0);
	}

	public void InputStudent() {
		super.InputPerson();
		Scanner cin = new Scanner(System.in);

		System.out.println("Enter rate: ");
		if (cin.hasNextFloat()) {
			this.rate = cin.nextFloat();

		}

		System.out.println("Enter hour: ");
		if (cin.hasNextInt()) {
			this.rate = cin.nextInt();
			cin.nextLine(); // consume the newline character
		}

		cin.close();
	}

	// abstract method must be implemented

	public void display() {
		System.out.println("Employee [name=" + this.name + ", address=" + this.getAddress() + ", rate=" + rate
				+ ", hour=" + hour + "]");
	}

	@Override
	public String toString() {
		return super.toString() + " Employee [rate=" + rate + ", hour=" + hour + "]";
	}

	public float getRate() {
		return rate;
	}

	public void setRate(float rate) {
		this.rate = rate;
	}

	public int getHour() {
		return hour;
	}

	public void setHour(int hour) {
		// Person.CountMeIn();

		this.hour = hour;
	}
}
