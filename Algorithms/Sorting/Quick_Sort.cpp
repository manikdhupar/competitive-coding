#include <iostream>
using namespace std;

int partition(int input[], int startIndex, int endIndex)
{

  int smallCount = 0;
  int element = input[startIndex];
  for (int i = startIndex + 1; i <= endIndex; i++)
  {
    if (input[i] <= element)
    {
      smallCount++;
    }
  }

  int pivotIndex = startIndex + smallCount;

  int temp = input[startIndex];
  input[startIndex] = input[pivotIndex];
  input[pivotIndex] = temp;

  int i = startIndex;
  int j = endIndex;

  while (i <= pivotIndex && j >= pivotIndex)
  {
    if (input[i] <= element)
    {
      i++;
    }
    else if (input[j] > element)
    {
      j--;
    }
    else
    {
      int temp = input[i];
      input[i] = input[j];
      input[j] = temp;
      i++;
      j--;
    }
  }

  return pivotIndex;
}

void quickSort(int input[], int startIndex, int endIndex)
{
  if (startIndex >= endIndex)
  {
    return;
  }

  int c = partition(input, startIndex, endIndex);
  quickSort(input, startIndex, c - 1);
  quickSort(input, c + 1, endIndex);
}

void quickSort(int input[], int size)
{
  quickSort(input, 0, size - 1);
}

int main()
{
  int n;
  cin >> n;

  int *input = new int[n];

  for (int i = 0; i < n; i++)
  {
    cin >> input[i];
  }

  quickSort(input, n);
  for (int i = 0; i < n; i++)
  {
    cout << input[i] << " ";
  }

  delete[] input;
}
