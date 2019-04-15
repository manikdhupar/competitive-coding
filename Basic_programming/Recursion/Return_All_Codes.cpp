#include <iostream>
using namespace std;
#include <string.h>
using namespace std;

string ref = "0abcdefghijklmnopqrstuvwxyz";

int helper(string input, string output[10000], string temp, int count)
{
  if (input.size() == 0)
  {
    output[count] = temp;
    count++;
    return count;
  }

  int index1 = input[0] - 48;
  string s3 = temp;
  temp += ref[index1];
  int count1 = helper(input.substr(1), output, temp, count);
  if (input.size() > 1)
  {
    string s2;
    s2 += input[0];
    s2 += input[1];
    int index2 = stoi(s2);
    s3 += ref[index2];
    if (index2 <= 26)
    {
      int finalCount = helper(input.substr(2), output, s3, count1);
      return finalCount;
    }
  }
  return count1;
}

int getCodes(string input, string output[10000])
{
  return helper(input, output, "", 0);
}

int main()
{
  string input;
  cin >> input;

  string output[10000];
  int count = getCodes(input, output);
  for (int i = 0; i < count && i < 10000; i++)
    cout << output[i] << endl;
  return 0;
}
