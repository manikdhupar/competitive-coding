/* C++ implementation to convert infix expression to postfix*/
// Note that here we use std::stack  for Stack operations
#include <vector>
#include <climits>
#include <iostream>
using namespace std;

class Polynomial
{
public:
  int *degCoeff;
  int capacity;

  // Complete the class
  // Default constructor
  Polynomial()
  {
    capacity = 5;
    degCoeff = new int[capacity];
    for (int i = 0; i < capacity; i++)
    {
      degCoeff[i] = 0;
    }
  }

  Polynomial(int n)
  {
    capacity = n;
    degCoeff = new int[capacity];
    for (int i = 0; i < capacity; i++)
    {
      degCoeff[i] = 0;
    }
  }

  // Copy constructor

  Polynomial(Polynomial const &d)
  {
    this->degCoeff = new int[d.capacity];
    for (int i = 0; i < d.capacity; i++)
    {
      this->degCoeff[i] = d.degCoeff[i];
    }
    this->capacity = d.capacity;
  }

  // Copy assignment operator

  void operator=(Polynomial const &d)
  {
    this->degCoeff = new int[d.capacity];
    for (int i = 0; i < d.capacity; i++)
    {
      this->degCoeff[i] = d.degCoeff[i];
    }
    this->capacity = d.capacity;
  }

  // Set Coefficient

  void setCoefficient(int degree, int coeff)
  {
    if (degree >= capacity)
    {

      int newSize = capacity;
      while (degree >= newSize)
      {
        newSize *= 2;
      }

      int *newArray = new int[newSize];
      for (int i = 0; i < capacity; i++)
      {
        newArray[i] = degCoeff[i];
      }
      for (int i = capacity; i < newSize; i++)
      {
        newArray[i] = 0;
      }
      newArray[degree] = coeff;
      this->degCoeff = newArray;
      this->capacity = newSize;
    }
    else
    {
      degCoeff[degree] = coeff;
    }
  }

  // overloading + operator

  Polynomial operator+(Polynomial const &p1)
  {
    int max;
    this->capacity > p1.capacity ? max = this->capacity : max = p1.capacity;
    Polynomial p3(max);
    for (int i = 0; i < capacity; i++)
    {
      p3.degCoeff[i] += degCoeff[i];
    }

    for (int i = 0; i < p1.capacity; i++)
    {
      p3.degCoeff[i] += p1.degCoeff[i];
    }
    return p3;
  }

  // overloading - operator

  Polynomial operator-(Polynomial const &p1)
  {
    int max;
    this->capacity > p1.capacity ? max = this->capacity : max = p1.capacity;
    Polynomial p3(max);
    for (int i = 0; i < capacity; i++)
    {
      p3.degCoeff[i] = degCoeff[i];
    }

    for (int i = 0; i < p1.capacity; i++)
    {
      p3.degCoeff[i] -= p1.degCoeff[i];
    }
    return p3;
  }

  Polynomial operator*(Polynomial const &p1)
  {
    Polynomial pnew;
    for (int i = 0; i < capacity; i++)
    {
      for (int j = 0; j < p1.capacity; j++)
      {
        int deg = i + j;
        int coeff;
        if (deg >= pnew.capacity)
        {
          coeff = (degCoeff[i] * p1.degCoeff[j]);
        }
        else
        {

          coeff = (degCoeff[i] * p1.degCoeff[j]) + pnew.degCoeff[deg];
        }
        pnew.setCoefficient(deg, coeff);
      }
    }
    return pnew;
  }

  void print()
  {
    for (int i = 0; i < capacity; i++)
    {
      if (degCoeff[i] != 0)
      {

        cout << degCoeff[i] << "x" << i << " ";
      }
    }
    cout << endl;
  }
};

//Driver program to test above functions
int main()
{
  int count1, count2, choice;
  cin >> count1;

  int *degree1 = new int[count1];
  int *coeff1 = new int[count1];

  for (int i = 0; i < count1; i++)
  {
    cin >> degree1[i];
  }

  for (int i = 0; i < count1; i++)
  {
    cin >> coeff1[i];
  }

  Polynomial first;
  for (int i = 0; i < count1; i++)
  {
    first.setCoefficient(degree1[i], coeff1[i]);
  }

  cin >> count2;

  int *degree2 = new int[count2];
  int *coeff2 = new int[count2];

  for (int i = 0; i < count2; i++)
  {
    cin >> degree2[i];
  }

  for (int i = 0; i < count2; i++)
  {
    cin >> coeff2[i];
  }

  Polynomial second;
  for (int i = 0; i < count2; i++)
  {
    second.setCoefficient(degree2[i], coeff2[i]);
  }

  cin >> choice;

  switch (choice)
  {
    // Add
  case 1:
  {
    Polynomial result1 = first + second;
  }
    // Subtract
  case 2:
  {
    Polynomial result2 = first - second;
    result2.print();
    break;
  }
    // Multiply
  case 3:
  {
    Polynomial result3 = first * second;
    result3.print();
    break;
  }
  case 4: // Copy constructor
  {
    Polynomial third(first);
    if (third.degCoeff == first.degCoeff)
    {
      cout << "false" << endl;
    }
    else
    {
      cout << "true" << endl;
    }
    break;
  }

  case 5: // Copy assignment operator
  {
    Polynomial fourth(first);
    if (fourth.degCoeff == first.degCoeff)
    {
      cout << "false" << endl;
    }
   
  }

  return 0;
}
