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

void printLevelWise(BinaryTreeNode<int> *root)
{
  /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Print output and don't return it.
     * Taking input is handled automatically.
     */
  if (root == NULL)
  {
    return;
  }

  queue<BinaryTreeNode<int> *> main;
  main.push(root);

  while (main.size() != 0)
  {
    BinaryTreeNode<int> *front = main.front();
    main.pop();
    if (front != NULL)
    {
      cout << front->data << ":";
    }
    if (front->left != NULL)
    {
      cout << "L:" << front->left->data << ",";
      main.push(front->left);
    }
    else
    {
      cout << "L:" << -1 << ",";
    }
    if (front->right != NULL)
    {
      cout << "R:" << front->right->data << endl;
      main.push(front->right);
    }
    else
    {
      cout << "R:" << -1 << endl;
    }
  }
}

int main()
{
  BinaryTreeNode<int> *root = takeInput();
  printLevelWise(root);
}
