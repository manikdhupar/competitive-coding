#include <iostream>
using namespace std;
#include <cstring>

void reverseEachWord(char input[])
{
  int len = strlen(input);
  char temp[1000];
  int i = 0, count = 0, num = 0;
  while (i <= len)
  {
    if (input[i] == ' ')
    {
      for (int j = i - 1; j >= num; j--)
      {
        temp[count] = input[j];
        count++;
      }
      num = i + 1;
      temp[count] = ' ';
      count++;
    }

    if (input[i] == '\0')
    {
      for (int j = i - 1; j >= num; j--)
      {
        temp[count] = input[j];
        count++;
      }
    }
    i++;
  }
  temp[count] = '\0';

  for (int i = 0; i <= len; i++)
  {
    input[i] = temp[i];
  }
}

int main()
{
  char input[1000];
  cin.getline(input, 1000);
  reverseEachWord(input);
  cout << input << endl;
}
