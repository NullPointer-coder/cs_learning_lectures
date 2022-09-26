//A program to store information of many types of ships
#include <iostream>

class Ship { //Base Class
private:
  std::string ship_name;
  std::string ship_year;
public:
  Ship(std::string name, int year) //Constructor
  {
    set_ship_name(name);
    set_year(year);
  }

  std::string get_ship_name() const //Accessor
  {
    return ship_name;
  }

  void set_ship_name(std::string name) //Mutator 
  {
    ship_name = name;
  }

  int get_year() const //Accessor
  {
    int year;
    year = std::stoi(ship_year);
    return year;
  }

  void set_year(int year) //Mutator
  {
    ship_year = std::to_string(year);
  }

  /**
    Displays the name and year of the specified ship to the console.
  */
  virtual void display();
};

void Ship::display()
  {
    std::cout << "Ship Name: " << get_ship_name() << std::endl;
    std::cout << "Ship Year: " << get_year() << std::endl;
    std::cout << std::endl;
  }

class CruiseShip : public Ship { //Derived class
private:
  int max_passengers;
public:
  CruiseShip(std::string name, int passengers, int year) : Ship(name, year) //Constructor
  {
    set_ship_name(name);
    set_max_passengers(passengers);
    set_year(year);
  }

  void set_max_passengers(int passengers) //Mutator
  {
    max_passengers = passengers;
  }

  int get_max_passengers() const //Accessor
  {
    return max_passengers;
  }

  /**
    Displays the name and maximum passengers of the specified cruise ship to the console.
  */
  void display() override;
};

void CruiseShip::display()
  {
    std::cout << "Ship Name: " << get_ship_name() << std::endl;
    std::cout << "Ship Max Passengers: " << get_max_passengers() << std::endl;
    std::cout << std::endl;
  }

class CargoShip : public Ship { //Derived class
private:
  int cargo_capacity;
public:
  CargoShip(std::string name, int capacity, int year) : Ship(name, year) //Constructor
  {
    set_ship_name(name);
    set_cargo_capacity(capacity);
    set_year(year);
  }

  void set_cargo_capacity(int capacity) //Mutator
  {
    cargo_capacity = capacity;
  }

  int get_cargo_capacity() const //Accessor
  {
    return cargo_capacity;
  }

  /**
    Displays the name and cargo capacity of the specified cargo ship to the console.
  */
  void display() override;
};

void CargoShip::display()
  {
    std::cout << "Ship Name: " << get_ship_name() << std::endl;
    std::cout << "Ship Cargo Capacity: " << get_cargo_capacity() << std::endl;
    std::cout << std::endl;
  }

int main()
{
  Ship *ships[10] = //Creating a list of ships of multiple types
  {
    new Ship("USS Texas", 1892),
    new Ship("USS Missouri", 1980),
    new Ship("USS Idaho", 1905),
    new Ship("USS Connecticut", 1903),
    new CruiseShip("Britannia", 3647, 2015),
    new CruiseShip("Carnival Liberty", 2974, 2005),
    new CruiseShip("World Odyssey", 520, 2015),
    new CargoShip("MV Algocape", 29709, 1966),
    new CargoShip("MV Algosteel", 26690, 1966),
    new CargoShip("MV Algorail", 23320, 1967),
  };

  for (unsigned i = 0; i < 10; i++) //Displays each ship in the previous list
  {
    ships[i]->display();
    delete ships[i]; //Cleaning memory
  }

  return 0;
}
