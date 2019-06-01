#include <iostream>
using namespace std;

void reverse(int *arr, int si, int ei)
{
  while (si < ei)
  {
    int temp = arr[si];
    arr[si] = arr[ei];
    arr[ei] = temp;
    si++;
    ei--;
  }
}

int main()
{
  int T;
  cin >> T;
  for (int i = 0; i < T; i++)
  {
    int N, d;
    cin >> N;
    int *arr = new int[N];
    for (int j = 0; j < N; j++)
    {
      cin >> arr[j];
    }
    cin >> d;
    reverse(arr, 0, d - 1);
    reverse(arr, d, N - 1);
    reverse(arr, 0, N - 1);
    for (int temp = 0; temp < N; temp++)
    {
      cout << arr[temp] << " ";
    }
    delete[] arr;
    cout << endl;
  }
  return 0;
}