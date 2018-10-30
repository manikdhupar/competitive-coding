#include <iostream>
using namespace std;

void helper(int input[], int inputSize, int output[], int outputSize)
{
  if (inputSize == 0)
  {
    for (int i = 0; i < outputSize; i++)
    {
      cout << output[i] << " ";
    }
    cout << endl;
    return;
  }

  helper(input + 1, inputSize - 1, output, outputSize);
  int element = input[0];
  int *array = new int[inputSize + 1];
  int i;
  for (i = 0; i < outputSize; i++)
  {
    array[i] = output[i];
  }
  array[i] = element;

  helper(input + 1, inputSize - 1, array, outputSize + 1);
}

void printSubsetsOfArray(int input[], int size)
{
  int *array = new int[size];
  helper(input, size, array, 0);
}

int main()
{
  int input[1000], length;
  cin >> length;
  for (int i = 0; i < length; i++)
    cin >> input[i];
  printSubsetsOfArray(input, length);
}
