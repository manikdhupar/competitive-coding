#include <iostream>
using namespace std;

void trimSpaces(char input[])
{

  int count = 0;
  for (int i = 0; input[i] != '\0'; i++)
  {
    count++;
  }

  for (int i = 0; i < count; i++)
  {
    while (input[i] == 32)
    {
      count--;
      int j = i;
      while (j < count)
      {
        input[j] = input[j + 1];
        j++;
      }
      input[count] = '\0';
    }
  }
}

int main()
{
  char input[1000000];
  cin.getline(input, 1000000);
  trimSpaces(input);
  cout << input << endl;
}
