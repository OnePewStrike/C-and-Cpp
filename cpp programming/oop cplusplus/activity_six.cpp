// class Time
#include <iostream>
#include <string>
using namespace std;

class Time
{
private:
  int hours;
  int minutes;
  int seconds;

public:
  Time();
  Time(int, int, int);
  void show();
  void addTime(int);
  Time operator+(const Time &);
};

int main(void)
{
  // input is set in seconds
  cout << "\n\n\tTime object 1: ";
  Time testOne(11, 59, 59);
  testOne.show();
  testOne.addTime(2358);
  testOne.show();
  testOne.addTime(19232);
  testOne.show();
  testOne.addTime(25212);
  testOne.show();

  cout << "\n\n\tTime object 2: ";
  Time testTwo;
  testTwo.addTime(97200);
  testTwo.show();

  cout << "\n\n\tTime object 3 (add object 1 and 2): ";
  Time testThree;
  testThree = testOne + testTwo;
  testThree.show();

  /*
  cout << "\n\n\tTime object 4 (check valid values): ";
  Time testFour(-1, 12, 0);
  test.show();
  */
  return 0;
}

Time::Time()
{
  hours = 0;
  minutes = 0;
  seconds = 0;
}

Time::Time(int h, int m, int s)
{
  if (h < 0 || m < 0 || s < 0)
  {
    hours = 0;
    minutes = 0;
    seconds = 0;
  }
  else
  {
    hours = h;
    minutes = m;
    seconds = s;
  }
}

void Time::show()
{
  cout << "\n\t" << hours << ":" << minutes << ":" << seconds;
  return;
}

void Time::addTime(int s)
{
  seconds += s;
  do
  {
    if (seconds >= 60)
    {
      seconds -= 60;
      minutes++;
    }
    else if (minutes >= 60)
    {
      minutes -= 60;
      hours++;
    }
    else if (hours > 24)
    {
      hours -= 24;
    }
    else
    {
      break;
    }
  } while (1);
  return;
}

Time Time::operator+(const Time &x)
{
  Time time;
  time.hours = this->hours + x.hours;
  time.minutes = this->minutes + x.minutes;
  time.seconds = this->seconds + x.seconds;
  return time;
}