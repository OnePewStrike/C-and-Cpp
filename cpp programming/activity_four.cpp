// class implementation -- Heater
#include <iostream>
#include <string>
#define tempOne "\n\n\tTemperature 1: "
#define tempTwo "\n\n\tTemperature 2: "
#define tempThree "\n\t\tTemperature 3: "
using namespace std;

class Heater
{
private:
  int temperature;
  int min;
  int max;
  int increment;

public:
  Heater(int, int);
  void warmer();
  void cooler();
  int getTemp();
  void setIncrement(int);
};
int main(void)
{
  int userInput, min, max, increment;

  Heater s1(5, 50);
  s1.setIncrement(10);
  cout << tempOne << s1.getTemp() << endl;
  s1.warmer();
  cout << tempOne << s1.getTemp() << endl;
  s1.warmer();
  cout << tempOne << s1.getTemp() << endl;
  s1.warmer();
  cout << tempOne << s1.getTemp() << endl;
  s1.warmer();
  cout << tempOne << s1.getTemp() << endl;

  Heater s2(-20, 50);
  s2.setIncrement(8);
  cout << tempTwo << s2.getTemp() << endl;
  s2.cooler();
  cout << tempTwo << s2.getTemp() << endl;
  s2.cooler();
  cout << tempTwo << s2.getTemp() << endl;
  s2.cooler();
  cout << tempTwo << s2.getTemp() << endl;
  s2.cooler();
  cout << tempTwo << s2.getTemp() << endl;
  s2.cooler();
  cout << tempTwo << s2.getTemp() << endl;

  Heater s3(0, 50);
  do
  {
    cout << "\n\n\tMenu-----------------------" << endl;
    cout << "\t1 to check temperature" << endl;
    cout << "\t2 to set increment" << endl;
    cout << "\t3 to set temperature warmer" << endl;
    cout << "\t4 to set temperature cooler" << endl;
    cout << "\t5 to exit" << endl;
    cout << "\tuser choice: ";
    cin >> userInput;

    switch (userInput)
    {
    case 1:
      cout << "\n\tYou chose to check temperature" << endl;
      cout << tempThree << s3.getTemp() << endl;
      break;
    case 2:
      cout << "\n\tYou chose to set increment" << endl;
      cout << "\n\t\tIncrement: ";
      cin >> increment;
      s3.setIncrement(increment);
      break;
    case 3:
      cout << "\n\tYou chose to set temperature warmer" << endl;
      s3.warmer();
      break;
    case 4:
      cout << "\n\tYou chose to set temperature cooler" << endl;
      s3.cooler();
      break;
    case 5:
      cout << "\n\t You chose to exit" << endl;
      break;
    default:
      cerr << "\n\t\tError: choice does not exist try again" << endl;
      continue;
    }
  } while (userInput != 5);

  cout << "\nEnd of program";
  return 0;
}

Heater::Heater(int x, int y)
{
  cout << "\n\tObject Temperature created\n";
  temperature = 15;
  increment = 5;
  min = x;
  max = y;
}
void Heater::warmer()
{
  int checkTemp = temperature + increment;
  if (checkTemp > max)
  {
    cerr << "\n\t\tError: Temperature exceeds max... returning previous temp..." << endl;
    return;
  }
  else
  {
    cout << "\n\t\tTemperature increased...";
    temperature += increment;
  }
  return;
}
void Heater::cooler()
{
  int checkTemp = temperature - increment;
  if (checkTemp < min)
  {
    cerr << "\n\t\tError: Temperature exceeds min... retuning previous temp..." << endl;
    return;
  }
  else
  {
    cout << "\n\t\tTemperature decreased...";
    temperature -= increment;
  }
  return;
}
int Heater::getTemp()
{
  return temperature;
}
void Heater::setIncrement(int inc)
{
  if (inc < 0)
  {
    cerr << "\n\t\tError: set increment is negative... \n\t\treturning default increment...";
    return;
  }
  else
  {
    cout << "\n\t\tIncrement set...";
    increment = inc;
  }
  return;
}