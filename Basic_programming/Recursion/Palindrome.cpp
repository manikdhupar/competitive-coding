#include <iostream>
using namespace std;
#include <cstring>

bool checkPalindrome(char input[])
{
  // Write your code here

  int len = strlen(input);

  if (len == 0)
  {
    return true;
  }

  if (input[0] != input[len - 1])
  {
    return false;
  }

  input[len - 1] = '\0';

  bool shortAns = checkPalindrome(input + 1);
  return shortAns;
}

int main()
{
  char input[50];
  cin >> input;

  if (checkPalindrome(input))
  {
    cout << "true" << endl;
  }
  else
  {
    cout << "false" << endl;
  }
}
