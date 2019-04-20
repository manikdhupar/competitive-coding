#include <iostream>
#include <vector>
using namespace std;

vector<int> helper(vector<int> &A)
{
  int carry = 1;
  for (int i = A.size() - 1; i >= 1; i--)
  {
    int val = A[i] + carry;
    if (val > 9)
    {
      A[i] = 0;
      carry = 1;
    }
    else
    {
      A[i] = val;
      carry = 0;
    }
  }

  if (carry + A[0] > 9)
  {
    A[0] = 0;
    A.insert(A.begin(), 1);
  }
  else
  {
    A[0] += carry;
  }

  int count = 0;
  for (int i = 0; i < A.size(); i++)
  {
    if (A[i] != 0)
    {
      break;
    }
    count++;
  }

  if (count > 0)
  {
    A.erase(A.begin(), A.begin() + count);
  }

  return A;
}

int main()
{
  int n;
  cin >> n;
  vector<int> vc;
  for (int i = 0; i < n; i++)
  {
    int temp;
    cin >> temp;
    vc.push_back(temp);
  }

  vc = helper(vc);
  for (int i = 0; i < vc.size(); i++)
  {
    cout << vc[i] << endl;
  }
}