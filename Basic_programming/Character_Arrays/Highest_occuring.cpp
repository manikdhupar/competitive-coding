#include <iostream>
using namespace std;
#include <cstring>

// input - given string
char highestOccurringChar(char input[])
{
  int len = strlen(input);
  char key = input[0];
  int prevCount = 0;
  for (int i = 0; input[i] != '\0'; i++)
  {
    int count = 0;
    char ch = input[i];
    for (int j = 0; j < len; j++)
    {
      if (ch == input[j])
      {
        count++;
      }

      if (j == len - 1 && count > prevCount)
      {
        prevCount = count;
        key = ch;
      }
    }
  }
  return key;
}

int main()
{
  char input[1000];
  cin.getline(input, 1000);
  cout << highestOccurringChar(input) << endl;
}
