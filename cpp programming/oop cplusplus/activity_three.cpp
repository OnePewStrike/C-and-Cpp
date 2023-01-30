/*
Create a class, Heater that contains an integer data member called temperature. Define a
constructor that takes no parameters. The temperature data member should be set to 15 in the
constructor. Define two member functions, warmerand cooler, whose effect is to increase or
decrease the value of temperature by 5 respectively, these are called mutators. Define a getter
function (accessor), called getTemp()that will return the value of temperature
*/

// class implementation -- temperature
#include <iostream>
using namespace std;

class Heater
{
private:
  int temperature;

public:
  Heater();
  void warmer();
  void cooler();
  int getTemp();
};
int main(void)
{
  int userInput;

  Heater s1;
  s1.warmer();
  s1.warmer();
  cout << "\n\tTemperature 1: " << s1.getTemp() << endl;

  Heater s2;
  s2.cooler();
  s2.cooler();
  s2.warmer();
  cout << "\n\tTemperature 2: " << s2.getTemp() << endl;

  Heater s3;
  do
  {
    cout << "\n\n\tMenu-----------------------" << endl;
    cout << "\t1 to see temperature" << endl;
    cout << "\t2 to set temperature warmer" << endl;
    cout << "\t3 to set temperature cooler" << endl;
    cout << "\t4 to exit" << endl;
    cout << "\tuser choice: ";
    cin >> userInput;

    switch (userInput)
    {
    case 1:
      cout << "\n\tYou chose to check temperature" << endl;
      cout << "\n\t\tTemperature 3: " << s3.getTemp() << endl;
      break;
    case 2:
      cout << "\n\tYou chose to set temperature warmer" << endl;
      s3.warmer();
      cout << "\n\t\tTemperature increased";
      break;
    case 3:
      cout << "\n\tYou chose to set temperature cooler" << endl;
      s3.cooler();
      cout << "\n\t\tTemperature decreased";
      break;
    case 4:
      cout << "\n\tYou chose to exit" << endl;
      break;
    default:
      cerr << "\n\t\tError: choice does not exist try again" << endl;
      continue;
    }
  } while (userInput != 4);
  cout << "\nEnd of program";
  return 0;
}

Heater::Heater()
{
  cout << "\n\tObject Temperature created";
  temperature = 15;
}
void Heater::warmer()
{
  temperature += 5;
}
void Heater::cooler()
{
  temperature -= 5;
}
int Heater::getTemp()
{
  return temperature;
}