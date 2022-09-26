"use strict";

const person =
{
  firstName: "Fred",
  lastName: "Flintstone",
  toString: ()  =>  (this.firstName + " " + this.lastName)
};

console.log(Object.keys(person));
console.log(person.toString());

person.address = "123 Rocky Way";
console.log(Object.keys(person));

function Person(fname, lname)
{
  this.firstName = fname;
  this.lastName = lname;
}

const fred = new Person("Fred", "Flintstone");
console.log(fred.firstName + " " + fred.lastName);

const wilma = Object.create(fred);
wilma.firstName = "Wilma";
console.log(wilma.firstName + " " + wilma.lastName);

class PersonClass
{
  constructor(fname, lname)
  {
    this.firstName = fname;
    this.lastName = lname;
  }
  toString()
  {
    return this.firstName + " " + this.lastName;
  }
}

const barney = new PersonClass("Barney", "Rubble");
console.log(barney.toString());
