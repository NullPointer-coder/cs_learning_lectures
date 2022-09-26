// Jingbo Wang
// This project to translates a day of year to a string consisting
// of the month followed by day of the month.

#include <iostream>
#include <string>

using namespace std;

const int MONTH_TOTAL = 12;
const int YEAR_DAYS_TOTAL =365;

class DayOfYear
{
  private:
    int input_day;

    const int days_per_month[MONTH_TOTAL] = {31, 28, 31, 30, 31, 30, 31, 31,
                                             30, 31,30, 31};
    const string month_names[MONTH_TOTAL] = {"January", "February",
                                                  "March","April", "May",
                                                  "June", "July","August",
                                                  "September", "October",
                                                  "November", "December"};
  public:
    DayOfYear(int input_d);

    int calc_day_of_month();
    int calc_number_of_month();

    string get_month();
    string to_string();

    //prefix
    DayOfYear operator --();
    DayOfYear operator ++();

    //Postfix
    DayOfYear operator --(int);
    DayOfYear operator ++(int);

    //overload =
    DayOfYear operator = (const DayOfYear& right);
};

int main()
{
  int day;
  cout << "Please enter a day of year: ";
  cin  >> day;

  DayOfYear day_of_year(day);
  cout << day_of_year.to_string() << endl << endl;
  DayOfYear birthday(0);

  cout <<"// Prefix"<<endl;
  birthday = -- day_of_year;
  cout << "birthday = -- day_of_year" << endl;
  cout << birthday.to_string() << " (birthday)" << endl;
  cout << day_of_year.to_string() << " (day_of_year)" << endl << endl;

  -- day_of_year;
  cout << "-- day_of_year" << endl;
  cout << day_of_year.to_string() << " (day_of_year)" << endl << endl;

  birthday = ++ day_of_year;
  cout << "birthday = ++ day_of_year" << endl;
  cout << birthday.to_string() << " (birthday)" << endl;
  cout << day_of_year.to_string() << " (day_of_year)" << endl << endl;

  ++day_of_year;
  cout << "++ day_of_year" << endl;
  cout << day_of_year.to_string() << " (day_of_year)" << endl << endl;

  cout <<"// Postfix"<<endl;
  birthday = day_of_year--;
  cout << "birthday = day_of_year --" << endl;
  cout << birthday.to_string() << " (birthday)" << endl;
  cout << day_of_year.to_string() << " (day_of_year)" << endl << endl;

  day_of_year ++;
  cout << "day_of_year ++" << endl;
  cout << day_of_year.to_string() << " (day_of_year)" << endl << endl;

  birthday = day_of_year ++;
  cout << "birthday = day_of_year ++" << endl;
  cout << birthday.to_string() << " (birthday)" << endl;
  cout << day_of_year.to_string() << " (day_of_year)" << endl << endl;

  day_of_year --;
  cout << "day_of_year --" << endl;
  cout << day_of_year.to_string() << " (day_of_year)" << endl << endl;

  return 0;
}

DayOfYear :: DayOfYear(int input_d)
{
  input_day = input_d;
}

int DayOfYear :: calc_day_of_month()
{
  int index = input_day;
  if(index > YEAR_DAYS_TOTAL)
  {
    index = index - YEAR_DAYS_TOTAL;
  }
  else if(index < 1)
  {
    index = YEAR_DAYS_TOTAL + index;
  }

  for(int i = 0; i < MONTH_TOTAL; i++)
  {
    if(index > days_per_month[i])
    {
      index = index - days_per_month[i];
    }
    else
    {
      return index;
    }
  }
}

int DayOfYear :: calc_number_of_month()
{
  int index = input_day;
  if(index > YEAR_DAYS_TOTAL)
  {
    index = index - YEAR_DAYS_TOTAL;
  }
  else if(index < 1)
  {
    index = YEAR_DAYS_TOTAL + index;
  }

  for(int i = 0; i < MONTH_TOTAL; i++)
  {
    if(index > days_per_month[i])
    {
      index = index - days_per_month[i];
    }
    else
    {
      return i;
    }
  }
}

string DayOfYear :: get_month()
{
  string monthName;
  monthName = month_names[calc_number_of_month()];

  return monthName;
}

string DayOfYear :: to_string()
{

  string result =  "The date is " + get_month() + " "
                        + std:: to_string(calc_day_of_month())
                        + ".";
  return result;
}

DayOfYear  DayOfYear :: operator --()
{
  input_day--;
  DayOfYear temp(input_day);
  return temp;
}

DayOfYear DayOfYear :: operator ++()
{
  input_day++;
  DayOfYear temp(input_day);
  return temp;
}

DayOfYear DayOfYear :: operator --(int)
{
  DayOfYear temp(input_day);
  input_day--;
  return temp;
}
DayOfYear DayOfYear :: operator ++(int)
{
  DayOfYear temp(input_day);
  input_day++;
  return temp;
}

DayOfYear DayOfYear :: operator = (const DayOfYear& right)
{
  input_day = right.input_day;
  return *this;
}
