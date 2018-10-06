#include <iostream>
using namespace std;

bool checkPalindrome(char str[])
{
  int count = 0;
  for (int i = 0; str[i] != '\0'; i++)
  {
    count++;
  }

  int i = 0;
  int j = count - 1;

  while (i < j)
  {
    if (str[i] == str[j])
    {
      i++;
      j--;
    }
    else
    {
      return false;
    }
  }
  return true;
}

int main()
{

  char str[10000];
  cin.getline(str, 10000);

  if (checkPalindrome(str))
  {
    cout << "true" << endl;
  }
  else
  {
    cout << "false" << endl;
  }
}
