#include <iostream>

class Ship
{
private:
    std::string ship_name;
   int year;
public:
    Ship(std::string name, int year_boat){ship_name = name; year = year_boat;}
    void set_ship_name(std::string name_of_ship){ ship_name = name_of_ship;};
    void set_year(int year) { this ->year = year;}
    virtual int get_year() const {return year;}
    virtual std::string get_ship_name() const {return ship_name;}
    virtual void display()
    {
      std::cout << "The name of the ship is: " << get_ship_name() << std::endl
                << "And the year of the ship is: " << get_year() << std::endl;
    }

};

class CruiseShip: public Ship
{
protected:
    int max_number_passenger;
public:
    CruiseShip(std::string name, int yearBoat, int max_passenger) : Ship(name, yearBoat)
    {
      set_ship_name(name);
      set_max_passenger(max_passenger);
    }
     void set_max_passenger(int max_number){max_number_passenger = max_number;}
    int get_max_number_passenger() const{return max_number_passenger;}
    void display()
    {
        std::cout << std::endl <<  "The name of the Cruise ship is: " << get_ship_name() << std::endl
                  << "And it has the max passenger is: " << get_max_number_passenger() << std::endl;
    }
};
