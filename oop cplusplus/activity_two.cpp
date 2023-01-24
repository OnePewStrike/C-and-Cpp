// class Rectangle -- test your class
// dulientelab2.cpp
#include <iostream>
using namespace std;

class Rectangle
{
public:
  void setDefault(float, float);
  float setLength();
  float setWidth();
  float getLength();
  float getWidth();
  float getArea();
  float getPerimeter();

private:
  float length;
  float width;
};

int main(void)
{
  int userInput;
  float length, width, area, perimeter;

  Rectangle s1;
  s1.setDefault(1, 1);
  length = s1.getLength();
  width = s1.getWidth();
  area = s1.getArea();
  perimeter = s1.getPerimeter();

  do
  {
    cout << "\n\tMenu----------------------------" << endl;
    cout << "\t\t1 to set length and width" << endl;
    cout << "\t\t2 to get length" << endl;
    cout << "\t\t3 to get width" << endl;
    cout << "\t\t4 to get area" << endl;
    cout << "\t\t5 to get perimeter" << endl;
    cout << "\t\t6 to exit" << endl;
    cout << "\n\t--------------------------------" << endl;
    cout << "\n\tuser choice: ";
    cin >> userInput;
    cout << endl;

    switch (userInput)
    {
    case 1:
      cout << "\tYou chose to set LENGTH and WIDTH" << endl;
      s1.setLength();
      length = s1.getLength();
      s1.setWidth();
      width = s1.getWidth();
      area = s1.getArea();
      perimeter = s1.getPerimeter();
      break;
    case 2:
      cout << "\tYou chose to get LENGTH" << endl;
      cout << "\n\t\tLength: " << length << endl;
      break;
    case 3:
      cout << "\tYou chose to get WIDTH" << endl;
      cout << "\n\t\tLength: " << width << endl;
      break;
    case 4:
      cout << "\tYou chose to get AREA" << endl;
      cout << "\n\t\tArea: " << area << endl;
      break;
    case 5:
      cout << "\tYou chose to get PERIMETER" << endl;
      cout << "\n\t\tPerimeter: " << perimeter << endl;
      break;
    case 6:
      cout << "\tYou chose to exit" << endl
           << endl;
      break;
    default:
      cerr << "\tError: It is not part of choices try again" << endl;
      continue;
    }

  } while (userInput != 6);
  cout << "End of program" << endl;
  return 0;
}

void Rectangle::setDefault(float len, float wid)
{
  length = len;
  width = wid;
}

float Rectangle::setLength()
{
  do
  {
    cout << "\n\t\tInput length: ";
    cin >> length;
    if (length >= 0.00 && length < 20.0)
    {
      break;
    }
    else
    {
      cerr << "\n\tError: It must be greater than or equal to 0.0 or less than 20.0" << endl;
    }
  } while (1);
}

float Rectangle::setWidth()
{
  do
  {
    cout << "\t\tInput width: ";
    cin >> width;
    if (width >= 0.00 && width < 20.0)
    {
      break;
    }
    else
    {
      cerr << "\n\tError: It must be greater than or equal to 0.0 or less than 20.0" << endl;
    }
  } while (1);
}

float Rectangle::getLength()
{
  return length;
}

float Rectangle::getWidth()
{
  return width;
}

float Rectangle::getArea()
{
  return length * width;
}

float Rectangle::getPerimeter()
{
  return 2 * (length + width);
}