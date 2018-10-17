#include <iostream>;
using namespace std;
#include <cstring>

void move(char input[], int start, int end)
{
  for (int i = end; i >= start; i--)
  {
    if (i == end)
    {
      input[i + 3] = '\0';
    }
    input[i + 2] = input[i];
  }
}

void replace(char input[], int start)
{
  int end = strlen(input);
  end = end - 1;
  if (start >= end)
  {
    return;
  }

  if (input[start] == 'p' && input[start + 1] == 'i')
  {
    move(input, start, end);
    input[start] = '3';
    input[start + 1] = '.';
    input[start + 2] = '1';
    input[start + 3] = '4';
    replace(input, start + 4);
  }
  else
  {
    replace(input, start + 1);
  }
}

void replacePi(char input[])
{
  // Write your code here
  return replace(input, 0);
}

int main()
{
  char input[100];
  cin.getline(input, 100);
  replacePi(input);
  cout << input << endl;
}
