#include <iostream>
using namespace std;

void InsertionSort(int arr[], int n)
{
  // Write your code here
  for (int i = 1; i < n; i++)
  {
    int key = arr[i];
    int j;
    for (j = i - 1; j >= 0 && arr[j] > key; j--)
    {
      arr[j + 1] = arr[j];
    }
    arr[j + 1] = key;
  }
}

int main()
{

  int size;
  cin >> size;
  int *input = new int[1 + size];

  for (int i = 0; i < size; i++)
    cin >> input[i];

  InsertionSort(input, size);

  for (int i = 0; i < size; i++)
    cout << input[i] << " ";

  return 0;
}
