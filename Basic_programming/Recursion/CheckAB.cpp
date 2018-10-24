#include <iostream>
using namespace std;

bool checkAB(char input[], int startIndex, int endIndex)
{
  if (startIndex > endIndex)
  {
    return true;
  }

  if (input[startIndex] == 'a')
  {
    if (input[startIndex + 1] == 'b' && input[startIndex + 2] != 'b')
    {

      return false;
    }
  }

  if (input[startIndex] == 'b' && input[startIndex + 1] == 'b')
  {
    if (input[startIndex + 2] && input[startIndex + 2] != 'a')
    {
      cout << "executed2" << endl;
      cout << input[startIndex + 2] << endl;
      return false;
    }
  }
  return checkAB(input, startIndex + 1, endIndex);
}

bool checkAB(char input[])
{
  // Write your code here
  if (input[0] != 'a')
  {
    return false;
  }

  int length = 0;
  for (int i = 0; input[i] != '\0'; i++)
  {
    length++;
  }

  return checkAB(input, 0, length);
}

int main()
{
  char input[100];
  bool ans;
  cin >> input;
  ans = checkAB(input);
  if (ans)
    cout << "true" << endl;
  else
    cout << "false" << endl;
}
