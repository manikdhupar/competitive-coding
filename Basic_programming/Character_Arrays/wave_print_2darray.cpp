#include <iostream>
using namespace std;

void wavePrint(int input[][1000], int row, int col)
{

  for (int j = 0; j < col; j++)
  {
    if (j % 2 == 0)
    {
      for (int i = 0; i < row; i++)
      {
        cout << input[i][j] << " ";
      }
    }
    else
    {
      for (int i = row - 1; i >= 0; i--)
      {
        cout << input[i][j] << " ";
      }
    }
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
  wavePrint(input, row, col);
}