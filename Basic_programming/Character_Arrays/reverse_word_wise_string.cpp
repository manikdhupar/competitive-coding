#include <iostream>
using namespace std;

void reverse(int i, int j, char arr[])
{
  while (i < j)
  {
    char temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    i++;
    j--;
  }
}

void reverseStringWordWise(char input[])
{
  int total = 0;
  for (int i = 0; input[i] != '\0'; i++)
  {
    total++;
  }
  int start = 0;
  int end = total - 1;

  reverse(start, end, input);

  for (int i = 0; i <= end; i++)
  {
    if (input[i] == 32)
    {
      reverse(start, i - 1, input);
      start = i + 1;
    }

    if (i == end)
    {
      reverse(start, i, input);
    }
  }
}

int main()
{
  char input[1000000];
  cin.getline(input, 1000000);
  reverseStringWordWise(input);
  cout << input << endl;
}