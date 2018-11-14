#include <iostream>
using namespace std;

class Fraction
{
  int numerator;
  int denominator;

public:
  Fraction(int numerator, int denominator)
  {
    this->numerator = numerator;
    this->denominator = denominator;
  }

  void display()
  {
    cout << numerator << "/" << denominator << endl;
  }

  Fraction operator+(Fraction const &f)
  {
    int num = (numerator * f.denominator) + (f.numerator * denominator);
    int den = denominator * f.denominator;
    Fraction fnew(num, den);
    return fnew;
  }
};

int main()
{
  Fraction f1(2, 3);
  Fraction f2(4, 5);
  Fraction f3 = f1 + f2;
  f1.display();
  f2.display();
  f3.display();
  return 0;
}
