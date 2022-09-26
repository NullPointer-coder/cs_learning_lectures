#include <iostream>
using namespace std;
int main()
{ const double MIN_INCOME = 35000.00;
  const unsigned MIN_YEARS = 5;
  cout << "Enter your annual income: ";
  double income;
  cin >> income;

  if (income >= MIN_INCOME)
  { cout << "Years at current job: ";
    unsigned years;
    cin >> years;
    if (years >= MIN_YEARS)
    {  cout << "You qualify" << endl;
    }
    else
    { unsigned years_remaining = MIN_YEARS - years;
      cout << "You will qualify in " << years_remaining << " years" << endl;
    }
  }
  else
  { cout << "You must earn at least $" << MIN_INCOME << " to qualify" << endl;
  }
  return 0;
}
