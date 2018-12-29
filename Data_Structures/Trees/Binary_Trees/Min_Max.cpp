#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode
{
public:
  T data;
  BinaryTreeNode<T> *left;
  BinaryTreeNode<T> *right;

  BinaryTreeNode(T data)
  {
    this->data = data;
    left = NULL;
    right = NULL;
  }
};

class PairAns
{
public:
  int min;
  int max;
};

using namespace std;

BinaryTreeNode<int> *takeInput()
{
  int rootData;
  //cout << "Enter root data : ";
  cin >> rootData;
  if (rootData == -1)
  {
    return NULL;
  }
  BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
  queue<BinaryTreeNode<int> *> q;
  q.push(root);
  while (!q.empty())
  {
    BinaryTreeNode<int> *currentNode = q.front();
    q.pop();
    int leftChild, rightChild;
    //cout << "Enter left child of " << currentNode -> data << " : ";
    cin >> leftChild;
    if (leftChild != -1)
    {
      BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
      currentNode->left = leftNode;
      q.push(leftNode);
    }
    //cout << "Enter right child of " << currentNode -> data << " : ";
    cin >> rightChild;
    if (rightChild != -1)
    {
      BinaryTreeNode<int> *rightNode = new BinaryTreeNode<int>(rightChild);
      currentNode->right = rightNode;
      q.push(rightNode);
    }
  }
  return root;
}

#include <climits>

PairAns minMax(BinaryTreeNode<int> *root)
{
  if (root == NULL)
  {
    PairAns p;
    p.min = INT_MAX;
    p.max = INT_MIN;
    return p;
  }
  PairAns left = minMax(root->left);
  PairAns right = minMax(root->right);

  PairAns final;
  final.max = max(root->data, max(left.max, right.max));
  final.min = min(root->data, min(left.min, right.min));
  return final;
}

int main()
{
  BinaryTreeNode<int> *root = takeInput();
  PairAns ans = minMax(root);
  cout << ans.max << " " << ans.min << endl;
}