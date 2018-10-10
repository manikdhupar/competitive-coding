#include <iostream>
using namespace std;

void BubbleSort(int arr[], int n)
{
  // Write your code here
  for (int i = 0; i < n - 1; i++)
  {
    int start = 0, end = n - 1 - i;
    while (start < end)
    {
      if (arr[start] > arr[start + 1])
      {
        int temp = arr[start];
        arr[start] = arr[start + 1];
        arr[start + 1] = temp;
      }
      start++;
    }
    end--;
  }
}

int main()
{

  int size;
  cin >> size;

  int *input = new int[1 + size];

  for (int i = 0; i < size; i++)
    cin >> input[i];

  BubbleSort(input, size);

  for (int i = 0; i < size; i++)
    cout << input[i] << " ";
}
