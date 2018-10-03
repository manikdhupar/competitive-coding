#include <iostream>
using namespace std;
#include <cstring>

void printSubstrings(char str[])
{
  int n = strlen(str);
  for (int i = 0; i < n; i++)
  {
    for (int j = i; j < n; j++)
    {
      for (int k = i; k <= j; k++)
      {
        cout << str[k];
      }
      cout << endl;
    }
  }
}

int main()
{

  char str[10000];
  cin.getline(str, 10000);

  printSubstrings(str);
}
