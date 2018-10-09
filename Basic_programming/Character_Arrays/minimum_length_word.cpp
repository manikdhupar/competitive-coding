#include <iostream>
using namespace std;
#include <cstring>
#include <climits>

void minLengthWord(char arr[], char output[])
{

  int len = strlen(arr);

  int length = INT_MAX;
  int num = 0, index = 0;
  for (int i = 0; i <= len; i++)
  {
    int count = 0;
    if (arr[i] == ' ' || arr[i] == '\0')
    {
      for (int j = i - 1; j >= num; j--)
      {
        count++;
      }
      if (count < length)
      {
        length = count;
        index = num;
      }
      num = i + 1;
    }
  }

  for (int i = 0; i < length; i++)
  {
    output[i] = arr[index];
    index++;
  }
}

int main()
{
  char ch[10000], output[10000];
  cin.getline(ch, 10000);
  minLengthWord(ch, output);
  cout << output << endl;
}
