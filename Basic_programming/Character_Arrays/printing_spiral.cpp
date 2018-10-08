#include <iostream>
using namespace std;

void spiralPrint(int arr[][1000], int row, int col)
{
  int count = 0;
  int rowStart = 0, rowEnd = row - 1, colStart = 0, colEnd = col - 1;
  while (count < (row * col))
  {
    // first row
    cout << "* ";
    for (int j = colStart; j <= colEnd; j++)
    {
      cout << arr[rowStart][j] << " ";
      count++;
    }
    rowStart++;

    // last column
    for (int i = rowStart; i <= rowEnd; i++)
    {
      cout << arr[i][colEnd] << " ";
      count++;
    }
    colEnd--;

    // last row
    for (int j = colEnd; j >= colStart; j--)
    {
      cout << arr[rowEnd][j] << " ";
      count++;
    }
    rowEnd--;

    // first column
    for (int i = rowEnd; i >= rowStart; i--)
    {
      cout << arr[i][colStart] << " ";
      count++;
    }
    colStart++;
  }
}

int main()
{
  int input[1500][1000];
  int row, col;
  cin >> row >> col;

  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < col; j++)
    {
      cin >> input[i][j];
    }
  }
  spiralPrint(input, row, col);
}