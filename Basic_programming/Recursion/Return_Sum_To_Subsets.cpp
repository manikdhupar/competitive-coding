#include <iostream>
using namespace std;

int subsetSumToK(int input[], int n, int output[][50], int k, int length, int finalOutput[][50])
{

  if (n == 0)
  {
    output[0][0] = 0;
    return 1;
  }

  int smallOutput = subsetSumToK(input + 1, n - 1, output, k, length, finalOutput);

  for (int i = 0; i < smallOutput; i++)
  {
    output[i + smallOutput][0] = output[i][0] + 1;
    output[i + smallOutput][1] = input[0];
    for (int j = 1; j <= output[i][0]; j++)
    {
      output[i + smallOutput][j + 1] = output[i][j];
    }
  }

  if (n == length)
  {
    int count = 0;
    for (int i = 0; i < 2 * smallOutput; i++)
    {
      int sum = 0;
      for (int j = 1; j <= output[i][0]; j++)
      {
        sum += output[i][j];
      }
      if (sum == k)
      {
        finalOutput[count][0] = output[i][0];
        for (int b = 1; b <= finalOutput[count][0]; b++)
        {
          finalOutput[count][b] = output[i][b];
        }
        count++;
      }
    }
    return count;
  }
  return 2 * smallOutput;
}

int subsetSumToK(int input[], int n, int output[][50], int k)
{
  int finalOutput[10000][50];
  int length = n;
  return subsetSumToK(input, n, finalOutput, k, length, output);
}

int main()
{
  int input[20], length, output[10000][50], k;
  cin >> length;
  for (int i = 0; i < length; i++)
    cin >> input[i];

  cin >> k;

  int size = subsetSumToK(input, length, output, k);

  for (int i = 0; i < size; i++)
  {
    for (int j = 1; j <= output[i][0]; j++)
    {
      cout << output[i][j] << " ";
    }
    cout << endl;
  }
}
