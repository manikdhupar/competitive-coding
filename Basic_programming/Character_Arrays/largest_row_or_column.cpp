#include <iostream>
using namespace std;
#include <climits>

void findLargest(int arr[][1000], int m, int n)
{
  // value of largest row/column
  int value = INT_MIN;
  // index of row/column
  int rc;
  bool row = true;
  // calculating largest row and its value
  for (int i = 0; i < m; i++)
  {
    int sum = 0;
    for (int j = 0; j < n; j++)
    {
      sum += arr[i][j];
    }
    if (sum > value)
    {
      value = sum;
      rc = i;
    }
  }
  // calculating largest column and its value
  for (int j = 0; j < n; j++)
  {
    int sum = 0;
    for (int i = 0; i < m; i++)
    {
      sum += arr[i][j];
    }
    if (sum > value)
    {
      value = sum;
      rc = j;
      row = false;
    }
  }
  // comparing largest of row or column
  if (row)
  {
    cout << "row ";
  }
  else
  {
    cout << "column ";
  }
  cout << rc << " " << value << endl;
}

int main()
{
  int row, col;
  cin >> row >> col;

  int input[1000][1000];
  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < col; j++)
    {
      cin >> input[i][j];
    }
  }
  findLargest(input, row, col);
}