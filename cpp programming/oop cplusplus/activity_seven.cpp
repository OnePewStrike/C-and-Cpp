#include <iostream>
#include <stdbool.h>
using namespace std;

// bool functions: isGreater, isSmaller, isGreaterEqual, isLesserEqual, isEqual, isNotEqual

class Distance
{
private:
  double feet;
  double inch;

public:
  Distance();
  Distance(double, double);
  void addDistance(double, double);
  void show(); // not part of instruction
  bool operator>(const Distance &);
  bool operator<(const Distance &);
  bool operator>=(const Distance &);
  bool operator<=(const Distance &);
  bool operator==(const Distance &);
  bool operator!=(const Distance &);
};
int main(void)
{
  bool isGreater, isSmaller, isGreaterEqual, isLesserEqual, isEqual, isNotEqual;
  Distance dist1, dist2(19, 24.1);

  // distance is compared in feet
  dist1.addDistance(17, 48.2);
  isGreater = dist1 > dist2;
  // dist1.show();
  // dist2.show();

  if (isGreater)
  {
    cout << "\n\tdist1 is greater than dist2" << endl;
  }
  else
  {
    cout << "\n\tdist1 is not greater than dist2" << endl;
  }

  dist2.addDistance(9, 200);
  isSmaller = dist1 > dist2;
  // dist1.show();
  // dist2.show();

  if (isSmaller)
  {
    cout << "\n\tdist1 is smaller than dist2" << endl;
  }
  else
  {
    cout << "\n\tdist1 is not smaller than dist2" << endl;
  }

  isEqual = dist1 == dist2;
  // dist1.show();
  // dist2.show();

  if (isEqual)
  {
    cout << "\n\tboth distances are equal" << endl;
  }
  else
  {
    cout << "\n\tboth distances are not equal" << endl;
  }

  dist1.addDistance(23, 454);
  dist2.addDistance(19, 605);
  isGreaterEqual = dist1 >= dist2;
  // dist1.show();
  // dist2.show();

  if (isGreaterEqual)
  {
    cout << "\n\tdist1 is greater than and equal to dist2" << endl;
  }
  else
  {
    cout << "\n\tdist1 is not greater than and equal to dist2" << endl;
  }

  isLesserEqual = dist1 <= dist2;
  // dist1.show();
  // dist2.show();

  if (isLesserEqual)
  {
    cout << "\n\tdist1 is lesser than and equal to dist2" << endl;
  }
  else
  {
    cout << "\n\tdist 1 is not lesser than and equal to dist2" << endl;
  }

  isNotEqual = dist1 != dist2;
  // dist1.show();
  // dist2.show();

  if (isNotEqual)
  {
    cout << "\n\tdist1 is not equal to dist2" << endl;
  }
  else
  {
    cout << "\n\tdist1 is equal to dist2" << endl;
  }
  return 0;
}

Distance::Distance()
{
  this->feet = 0;
  this->inch = 0;
}
Distance::Distance(double feet, double inch)
{
  this->feet = feet;
  this->inch = inch;

  // 12 inches consitute to a foot
  this->feet += inch / 12;
}

void Distance::addDistance(double feetInput, double inchInput)
{
  this->feet += feetInput;
  this->inch += inchInput;

  // 12 inches consitute to a foot
  this->feet += inchInput / 12;
  cout << "\n\tDistance added to object" << endl;
}

void Distance::show()
{
  cout << "\tDist object feet: " << this->feet << endl;
}

bool Distance::operator>(const Distance &dist2)
{
  if (this->feet > dist2.feet)
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool Distance::operator<(const Distance &dist2)
{
  if (this->feet < dist2.feet)
  {
    return true;
  }
  else
  {
    return false;
  }
}
bool Distance::operator>=(const Distance &dist2)
{
  if (this->feet >= dist2.feet)
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool Distance::operator<=(const Distance &dist2)
{
  if (this->feet <= dist2.feet)
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool Distance::operator==(const Distance &dist2)
{
  if (this->feet == dist2.feet)
  {
    return true;
  }
  else
  {
    return false;
  }
}
bool Distance::operator!=(const Distance &dist2)
{
  if (this->feet != dist2.feet)
  {
    return true;
  }
  else
  {
    return false;
  }
}