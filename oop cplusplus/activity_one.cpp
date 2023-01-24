#include <iostream>
#include <string>
using namespace std;

double power(double n, int p = 2);

int main()
{
  int number, p;
  char user_input;

  cout << "Enter the number: ";
  cin >> number;

  do
  {
    cout << "Do you want to power? (y/n)? ";
    cin >> user_input;

    if (user_input == 'y' || user_input == 'Y')
    {
      cout << "Enter power to be raised: ";
      cin >> p;
      cout << "4 ^ " << p << " ( 4 raised to the power " << p << ") = " << power(number, p) << endl;
      break;
    }
    else if (user_input == 'n' || user_input == 'N')
    {
      cout << "4 ^ 2 ( 4 raised to the power 2) = " << power(number) << endl;
      break;
    }
    else
    {
      cout << "Invalid choice" << endl;
      continue;
    }
  } while (1);
}

double power(double n, int p)
{
  double result = n;

  if (p >= 0)
  {
    for (int i = 1; i < p; i++)
    {
      result *= n;
    }
  }
  else
  {
    p = p * -1;
    for (int i = 1; i < p; i++)
    {
      result *= n;
    }
    result = 1 / result;
  }

  return result;
}