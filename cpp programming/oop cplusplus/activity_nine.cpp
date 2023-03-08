#include <iostream>
using namespace std;

class Storage
{
private:
  double bits;
  double bytes;

public:
  Storage();
  Storage(int, int);
  friend Storage operator+(Storage &, Storage &);
  friend Storage operator+=(Storage &, Storage &);
  friend Storage operator++(Storage &);
  friend Storage operator++(Storage &, int);
  friend bool operator>(const Storage &, const Storage &);
  void showDetails();
};

int main(void)
{
  Storage file1(8, 8), file2(4, 4), file3;

  cout << "file objects: " << endl;
  cout << "file1(8,8) ; file2(4,4) ; file3()" << endl;

  cout << "\nobject file1 original: " << endl;
  file1.showDetails();
  cout << "\nobject file2 original: " << endl;
  file2.showDetails();
  cout << "\nobject file3 original: " << endl;
  file3.showDetails();

  file1++;
  cout << "\nobject file1 modified: " << endl;
  file1.showDetails();
  ++file1;
  cout << "\nobject file1 modified: " << endl;
  file1.showDetails();

  file2++;
  cout << "\nobject file2 modified: " << endl;
  file2.showDetails();
  ++file2;
  cout << "\nobject file2 modified: " << endl;
  file2.showDetails();
  file2++;
  cout << "\nobject file2 modified: " << endl;
  file2.showDetails();

  file3 = file1 + file2;
  cout << "\nobject file3 modified (file1 + file2): " << endl;
  file3.showDetails();

  file2 = file2 += file3;
  cout << "\nobject file2 modified (concatenation w/ file3): " << endl;
  file2.showDetails();

  if (file1 > file2)
  { // comparison is in bytes
    cout << "\file1 is greater than file2" << endl;
  }
  else
  {
    cout << "\nfile1 is not greater than file2" << endl;
  }

  cout << "\nobject file1: " << endl;
  file1.showDetails();

  cout << "\nobject file2: " << endl;
  file2.showDetails();
}

Storage::Storage()
{
  this->bits = 0;
  this->bytes = 0;
}

Storage::Storage(int bits, int bytes)
{
  if (bits >= 8)
  {
    this->bytes = bytes;
    this->bytes += bits / 8;
    this->bits = 0;
  }
  else
  {
    this->bits = bits;
    this->bytes = bytes;
  }
}

Storage operator+(Storage &obj1, Storage &obj2)
{
  Storage obj;
  obj.bits = obj1.bits + obj2.bits;
  obj.bytes = obj1.bytes + obj2.bytes;

  if (obj.bits >= 8)
  {
    obj.bytes += obj.bits / 8;
    obj.bits = 0;
  }
  cout << "\n\tFile merge occurred" << endl;
  return obj;
}

Storage operator+=(Storage &obj1, Storage &obj2)
{
  Storage obj;
  obj.bits = obj1.bits + obj2.bits;
  obj.bytes = obj1.bytes + obj2.bytes;

  if (obj.bits >= 8)
  {
    obj.bytes += obj.bits / 8;
    obj.bits = 0;
  }
  cout << "\n\tFile object concatenation occurred" << endl;
  return obj;
}

Storage operator++(Storage &obj)
{
  obj.bits++;

  if (obj.bits >= 8)
  {
    obj.bytes += obj.bits / 8;
    obj.bits = 0;
  }
  cout << "\n\tPost-increment on object occurred" << endl;
}

Storage operator++(Storage &obj, int)
{
  ++obj.bits;

  if (obj.bits >= 8)
  {
    obj.bytes += obj.bits / 8;
    obj.bits = 0;
  }
  cout << "\n\tPre-increment on object occurred" << endl;
}

bool operator>(const Storage &obj1, const Storage &obj2)
{
  if (obj1.bytes > obj2.bytes)
  {
    return true;
  }
  else if (obj1.bytes == obj2.bytes && obj1.bits > obj2.bits)
  {
    return true;
  }
  else
  {
    return false;
  }
}

void Storage::showDetails()
{
  cout << "\tbits: " << this->bits << endl;
  cout << "\tbytes: " << this->bytes << endl;
}