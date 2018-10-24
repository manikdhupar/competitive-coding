#include <iostream>
using namespace std;

// input - input array
// size - length of input array

int binarySearch(int input[], int startIndex, int endIndex, int element)
{
  if (startIndex > endIndex)
  {
    return -1;
  }

  int mid = (startIndex + endIndex) / 2;
  if (input[mid] == element)
  {
    return mid;
  }
  else if (input[mid] < element)
  {
    return binarySearch(input, mid + 1, endIndex, element);
  }
  else
  {
    return binarySearch(input, startIndex, mid - 1, element);
  }
}

int binarySearch(int input[], int length, int element)
{
  return binarySearch(input, 0, length - 1, element);
}

int main()
{
  int input[100000], length, element, ans;
  cin >> length;
  for (int i = 0; i < length; i++)
  {
    cin >> input[i];
    ;
  }

  cin >> element;
  ans = binarySearch(input, length, element);
  cout << ans << endl;
}
