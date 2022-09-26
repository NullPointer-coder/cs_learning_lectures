#include <iostream>
#include <string>

using namespace std;

class DayOfYear
{
private:
  int day;
  
  const string month_names[12] {"January", "February", "March", "April", "May",
    "June", "July", "August", "September", "October", "November", "December"};
  
  const int month_days[12] {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304,
    334};
  
  void simplify()
  {
    // fixes the day to an int from 1-365 if it is greater than 365
    if (day > 365) day %= 365;
    
    //fixes the day to an int from 1-365 if it is less than 1
    if (day < 1) day += 365;
  }
  
public:
  DayOfYear(int d)
  {
    this->day = d;
    simplify();
  }
  
  string to_string(); 
};



string DayOfYear::to_string()
{
  
  simplify();
  
  // const int month_days[12] {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
  
  const int NUMBER_OF_MONTHS=12;
  int month_index = 0;
  int day_val = day;
  for (unsigned index = NUMBER_OF_MONTHS-1; index >=0 ; index--)
    {
      //finds out what month the day is in
      if (month_days[index] <= day)
        {
          month_index = index;
          day_val = day_val - month_days[index];
          break;
        }
    }
  return month_names[month_index] + " " + std::to_string(day_val) ;
}

int main()
{
  int day;
  cout << "Enter a day of the year: ";
  cin >> day; 

  DayOfYear newDay(day);
  cout << newDay.to_string() << endl;

  return 0;
} 
