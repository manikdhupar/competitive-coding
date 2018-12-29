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

void printLevelATNewLine(BinaryTreeNode<int> *root)
{
  queue<BinaryTreeNode<int> *> q;
  q.push(root);
  q.push(NULL);
  while (!q.empty())
  {
    BinaryTreeNode<int> *first = q.front();
    q.pop();
    if (first == NULL)
    {
      if (q.empty())
      {
        break;
      }
      cout << endl;
      q.push(NULL);
      continue;
    }
    cout << first->data << " ";
    if (first->left != NULL)
    {
      q.push(first->left);
    }
    if (first->right != NULL)
    {
      q.push(first->right);
    }
  }
}

BinaryTreeNode<int> *helper(int *postorder, int *inorder, int inStart, int inEnd, int postStart, int postEnd)
{
  if (inStart > inEnd || postStart > postEnd)
  {
    return NULL;
  }

  int rootValue = postorder[postEnd];

  int linStart = inStart;
  int k = -1;
  for (int i = inStart; i <= inEnd; i++)
  {
    if (inorder[i] == rootValue)
    {
      k = i;
      break;
    }
  }
  int linEnd = k - 1;
  int lpostStart = postStart;
  int lpostEnd = linEnd - linStart + lpostStart;
  int rinStart = k + 1;
  int rinEnd = inEnd;
  int rpostStart = lpostEnd + 1;
  int rpostEnd = postEnd - 1;

  BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootValue);
  root->left = helper(postorder, inorder, linStart, linEnd, lpostStart, lpostEnd);
  root->right = helper(postorder, inorder, rinStart, rinEnd, rpostStart, rpostEnd);
  return root;
}

BinaryTreeNode<int> *getTreeFromPostorderAndInorder(int *postorder, int postLength, int *inorder, int inLength)
{
  int inStart = 0;
  int inEnd = inLength - 1;
  int postStart = 0;
  int postEnd = postLength - 1;
  return helper(postorder, inorder, inStart, inEnd, postStart, postEnd);
}

int main()
{
  int size;
  cin >> size;
  int *post = new int[size];
  int *in = new int[size];
  for (int i = 0; i < size; i++)
    cin >> post[i];
  for (int i = 0; i < size; i++)
    cin >> in[i];
  BinaryTreeNode<int> *root = getTreeFromPostorderAndInorder(post, size, in, size);
  printLevelATNewLine(root);
}
