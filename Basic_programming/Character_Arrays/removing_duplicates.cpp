#include <iostream>
using namespace std;
#include <cstring>

void removeConsecutiveDuplicates(char input[])
{
  int len = strlen(input);
  int count = 0;
  for (int i = 0; i < len; i++)
  {
    if (input[i] != input[i + 1])
    {
      input[count] = input[i];
      count++;
    }
  }
  input[count] = '\0';
}

int main()
{
  char input[1000];
  cin.getline(input, 1000);
  removeConsecutiveDuplicates(input);
  cout << input << endl;
}
