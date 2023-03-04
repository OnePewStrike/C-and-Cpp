#include <iostream>
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
  Time operator+(const Time &);
  Time operator++();
  Time operator--();
  void show(); // not part of instruction
};

int main(void)
{
  Time t1, t2(11, 59, 59), t3;
  cout << "\n\tTime object 1: ";
  ++t1;
  ++t1;
  ++t1;
  t1.show(); // set 0:0:03
  --t1;
  --t1;
  t1.show(); // set 0:0:01
  --t1;
  --t1;
  t1.show(); // check operator-- must display 23:59:59
  ++t1;
  t1.show(); // check operator++ must display 0:0:0

  cout << "\n\n\tTime object 2: ";
  t2.show();

  cout << "\n\n\tTime object 3 (0:0:0 + 11:59:59): "; // 2400 hour + 1159 hour = 1159 hour
  t3 = t2 + t1;
  t3.show();
  return 0;
}

Time::Time()
{
  this->hours = 0;
  this->minutes = 0;
  this->seconds = 0;
}

Time::Time(int hours, int minutes, int seconds)
{
  if (hours < 0 || minutes < 0 || seconds < 0)
  {
    this->hours = 0;
    this->minutes = 0;
    this->seconds = 0;
  }
  else
  {
    this->hours = hours;
    this->minutes = minutes;
    this->seconds = seconds;
  }
}

Time Time::operator+(const Time &x)
{
  Time time;
  time.hours = this->hours + x.hours;
  time.minutes = this->minutes + x.minutes;
  time.seconds = this->seconds + x.seconds;
  do
  {
    if (time.seconds >= 60)
    {
      time.seconds -= 60;
      ++time.minutes;
    }
    else if (time.minutes >= 60)
    {
      time.minutes -= 60;
      ++time.hours;
    }
    else if (time.hours > 24)
    {
      time.hours -= 24;
    }
    else
    {
      break;
    }
  } while (1);
  return time;
}

Time Time::operator++()
{
  ++seconds;
  do
  {
    if (seconds >= 60)
    {
      seconds -= 60;
      ++minutes;
    }
    else if (minutes >= 60)
    {
      minutes -= 60;
      ++hours;
    }
    else if (hours >= 24)
    {
      hours -= 24;
    }
    else
    {
      break;
    }
  } while (1);
  return Time(hours, minutes, seconds);
}

Time Time::operator--()
{
  --seconds;
  do
  {
    if (seconds < 0)
    {
      seconds = 59;
      --minutes;
    }
    else if (minutes < 0)
    {
      minutes = 59;
      --hours;
    }
    else if (hours < 0)
    {
      hours += 24;
    }
    else
    {
      break;
    }
  } while (1);
  return Time(hours, minutes, seconds);
}

void Time::show()
{
  cout << "\n\t" << hours << ":" << minutes << ":" << seconds;
  return;
}