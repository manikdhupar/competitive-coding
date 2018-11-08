#include <iostream>
using namespace std;

void printSubsetSumToK(int input[], int size, int k, int output[], int outputSize)
{
  if (size == 0)
  {
    if (k == 0)
    {
      for (int i = 0; i < outputSize; i++)
      {
        cout << output[i] << " ";
      }
      cout << endl;
      return;
    }
    else
    {
      return;
    }
  }

  int *array = new int[outputSize + 1];

  int i;
  for (i = 0; i < outputSize; i++)
  {
    array[i] = output[i];
  }
  array[i] = input[0];

  printSubsetSumToK(input + 1, size - 1, k, output, outputSize);
  printSubsetSumToK(input + 1, size - 1, k - input[0], array, outputSize + 1);
}

void printSubsetSumToK(int input[], int size, int k)
{
  int output[1000];
  printSubsetSumToK(input, size, k, output, 0);
}

int main()
{
  int input[1000], length, k;
  cin >> length;
  for (int i = 0; i < length; i++)
    cin >> input[i];
  cin >> k;
  printSubsetSumToK(input, length, k);
}
