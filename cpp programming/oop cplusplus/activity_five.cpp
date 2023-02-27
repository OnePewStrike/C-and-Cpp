// class implementation -- date
#include <iostream>
using namespace std;

class Date
{
private:
  int day;
  int year;
  int month;

public:
  Date(int, int, int);
  void displayDate();
  void setMonth(int);
  void setDay(int);
  void setYear(int);
  int getMonth();
  int getDay();
  int getYear();
};

int main(void)
{
  int userInput, num;
  Date *thisObject;

  Date t1(1, 13, 2002);
  thisObject = &t1;
  cout << "\n\tBirth date: ";
  thisObject->displayDate();
  cout << "\n\tMonth: " << thisObject->getMonth();
  cout << "\n\tDay: " << thisObject->getDay();
  cout << "\n\tYear: " << thisObject->getYear() << endl;
  ;

  thisObject->setMonth(8);
  thisObject->setDay(28);
  thisObject->setYear(1901);
  cout << "\n\tFounder's date: ";
  thisObject->displayDate();
  cout << "\n\tMonth: " << thisObject->getMonth();
  cout << "\n\tDay: " << thisObject->getDay();
  cout << "\n\tYear: " << thisObject->getYear() << endl;

  Date t2(6, 12, 1898);
  thisObject = &t2;
  do
  {
    cout << "\n\tMain Menu---------------";
    cout << "\n\t1 to check full date";
    cout << "\n\t2 to check month";
    cout << "\n\t3 to check day";
    cout << "\n\t4 to check year";
    cout << "\n\t5 to set month";
    cout << "\n\t6 to set day";
    cout << "\n\t7 to set year";
    cout << "\n\t8 to exit";
    cout << "\n\t------------------------";
    cout << "\n\tuser choice: ";
    cin >> userInput;

    switch (userInput)
    {
    case 1:
      thisObject->displayDate();
      break;
    case 2:
      cout << "\n\t\tMonth: " << thisObject->getMonth() << endl;
      break;
    case 3:
      cout << "\n\t\tDay: " << thisObject->getDay() << endl;
      break;
    case 4:
      cout << "\n\t\tYear: " << thisObject->getYear() << endl;
      break;
    case 5:
      cout << "\n\t\tInput month: ";
      cin >> num;
      thisObject->setMonth(num);
      break;
    case 6:
      cout << "\n\t\tInput day: ";
      cin >> num;
      thisObject->setDay(num);
      break;
    case 7:
      cout << "\n\t\tInput year: ";
      cin >> num;
      thisObject->setYear(num);
      break;
    case 8:
      cout << "\n\t\tExit" << endl;
      break;
    default:
      cerr << "\n\t\tError: user input not part of options" << endl;
    }
  } while (userInput != 8);
  cout << "End of program";
  return 0;
}

Date::Date(int m, int d, int y)
{
  month = m;
  day = d;
  year = y;
}
void Date::displayDate()
{
  cout << "\n\t\tDate: " << month << "/" << day << "/" << year << endl;
  return;
}
void Date::setMonth(int m)
{
  month = m;
  return;
}
void Date::setDay(int d)
{
  day = d;
  return;
}
void Date::setYear(int y)
{
  year = y;
  return;
}
int Date::getMonth()
{
  return month;
}
int Date::getDay()
{
  return day;
}
int Date::getYear()
{
  return year;
}