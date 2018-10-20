#include <iostream>
using namespace std;

void merge(int input[], int startIndex, int endIndex)
{

  int mid = (startIndex + endIndex) / 2;

  int size = endIndex - startIndex + 1;

  int *output = new int[size];
  int i = startIndex, j = mid + 1, k = 0;

  while (i <= mid && j <= endIndex)
  {
    if (input[i] > input[j])
    {
      output[k] = input[j];
      j++;
      k++;
    }
    else
    {
      output[k] = input[i];
      i++;
      k++;
    }
  }

  while (i <= mid)
  {
    output[k] = input[i];
    i++;
    k++;
  }

  while (j <= endIndex)
  {
    output[k] = input[j];
    j++;
    k++;
  }
  int y = 0;
  for (int x = startIndex; x <= endIndex; x++)
  {
    input[x] = output[y];
    y++;
  }

  delete[] output;
}

void mergeSort(int input[], int startIndex, int endIndex)
{
  if (startIndex >= endIndex)
  {
    return;
  }

  int mid = (startIndex + endIndex) / 2;

  mergeSort(input, startIndex, mid);
  mergeSort(input, mid + 1, endIndex);
  merge(input, startIndex, endIndex);
}

void mergeSort(int input[], int length)
{
  int startIndex = 0;
  int endIndex = length - 1;
  mergeSort(input, startIndex, endIndex);
}

int main()
{
  int input[1000], length;
  cin >> length;
  for (int i = 0; i < length; i++)
    cin >> input[i];
  mergeSort(input, length);
  for (int i = 0; i < length; i++)
  {
    cout << input[i] << " ";
  }
}
