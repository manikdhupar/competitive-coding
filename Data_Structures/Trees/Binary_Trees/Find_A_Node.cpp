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

bool isNodePresent(BinaryTreeNode<int> *root, int x)
{
  /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
  if (root == NULL)
  {
    return false;
  }

  if (root->data == x)
  {
    return true;
  }

  bool one = isNodePresent(root->left, x);
  if (one)
  {
    return true;
  }
  bool two = isNodePresent(root->right, x);
  if (two)
  {
    return true;
  }
}

int main()
{
  BinaryTreeNode<int> *root = takeInput();
  int x;
  cin >> x;
  if (isNodePresent(root, x))
  {
    cout << "true";
  }
  else
  {
    cout << "false";
  }
}
