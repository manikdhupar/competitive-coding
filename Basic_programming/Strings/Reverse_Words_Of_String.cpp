#include <iostream>
#include <string>
using namespace std;

void reverse(string &input, int si, int li)
{
  while (si <= li)
  {
    char temp = input[si];
    input[si] = input[li];
    input[li] = temp;
    si++;
    li--;
  }
  return;
}

string helper(string input)
{
  int li = input.length() - 1;
  int si = 0;
  int count = 0;
  while (input[si] == ' ')
  {
    si++;
  }
  count = si;
  for (int i = count; i <= li; i++)
  {
    if (input[i] == ' ' || i == li)
    {
      i == li ? reverse(input, si, i) : reverse(input, si, i - 1);
      si = i + 1;
    }
  }
  reverse(input, 0, li);

  return input;
  reverse(input, 0, li);
  return input;
}

int main()
{
  string s = "how are you manik , hey   ";
  cout << helper(s) << endl;
}