#include <iostream>
#include <string>
using namespace std;

void helper(string input, string output)
{
  if (input.size() == 0)
  {
    cout << output << endl;
  }

  for (int i = 0; i < input.size(); i++)
  {
    string temp = input;
    temp.erase(i, 1);
    helper(temp, output + input[i]);
  }
}

void printPermutations(string input)
{
  helper(input, "");
}

int main()
{
  string input;
  cin >> input;
  printPermutations(input);
  return 0;
}
