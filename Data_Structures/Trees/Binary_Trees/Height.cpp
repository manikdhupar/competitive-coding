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

int height(BinaryTreeNode<int> *root)
{
  if (root == NULL)
  {
    return 0;
  }

  int heightLeftChild = height(root->left);
  int heightRightChild = height(root->right);
  if (heightLeftChild > heightRightChild)
  {
    return 1 + heightLeftChild;
  }
  else
  {
    return 1 + heightRightChild;
  }
}

int main()
{
  BinaryTreeNode<int> *root = takeInput();
  cout << height(root) << endl;
}
