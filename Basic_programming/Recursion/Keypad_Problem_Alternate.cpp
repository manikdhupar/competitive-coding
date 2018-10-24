#include <iostream>
#include <string>
using namespace std;

void printKeypad(int num, string output)
{
  // base case
  if (num == 0)
  {
    cout << output << endl;
    return;
  }

  int digit = num % 10;
  num = num / 10;

  if (digit == 2)
  {
    printKeypad(num, 'a' + output);
    printKeypad(num, 'b' + output);
    printKeypad(num, 'c' + output);
  }

  else if (digit == 3)
  {
    printKeypad(num, 'd' + output);
    printKeypad(num, 'e' + output);
    printKeypad(num, 'f' + output);
  }

  else if (digit == 4)
  {
    printKeypad(num, 'g' + output);
    printKeypad(num, 'h' + output);
    printKeypad(num, 'i' + output);
  }

  else if (digit == 5)
  {
    printKeypad(num, 'j' + output);
    printKeypad(num, 'k' + output);
    printKeypad(num, 'l' + output);
  }

  else if (digit == 6)
  {
    printKeypad(num, 'm' + output);
    printKeypad(num, 'n' + output);
    printKeypad(num, 'o' + output);
  }

  else if (digit == 7)
  {
    printKeypad(num, 'p' + output);
    printKeypad(num, 'q' + output);
    printKeypad(num, 'r' + output);
    printKeypad(num, 's' + output);
  }

  else if (digit == 8)
  {
    printKeypad(num, 't' + output);
    printKeypad(num, 'u' + output);
    printKeypad(num, 'v' + output);
  }

  else if (digit == 9)
  {
    printKeypad(num, 'w' + output);
    printKeypad(num, 'x' + output);
    printKeypad(num, 'y' + output);
    printKeypad(num, 'z' + output);
  }
}

void printKeypad(int num)
{
  string output = "";
  printKeypad(num, output);
}

int main()
{
  int num;
  cin >> num;

  printKeypad(num);

  return 0;
}
