#include <iostream>
using namespace std;
#include <vector>

template <typename T>
class TreeNode
{
public:
  T data;
  vector<TreeNode<T> *> children;

  TreeNode(T data)
  {
    this->data = data;
  }

  ~TreeNode()
  {
    for (int i = 0; i < children.size(); i++)
    {
      delete children[i];
    }
  }
};

#include <queue>

TreeNode<int> *takeInputLevelWise()
{
  int rootData;
  cin >> rootData;
  TreeNode<int> *root = new TreeNode<int>(rootData);

  queue<TreeNode<int> *> pendingNodes;

  pendingNodes.push(root);
  while (pendingNodes.size() != 0)
  {
    TreeNode<int> *front = pendingNodes.front();
    pendingNodes.pop();
    int numChild;
    cin >> numChild;
    for (int i = 0; i < numChild; i++)
    {
      int childData;
      cin >> childData;
      TreeNode<int> *child = new TreeNode<int>(childData);
      front->children.push_back(child);
      pendingNodes.push(child);
    }
  }
  return root;
}

int sum(TreeNode<int> *root)
{
  int result = 0;
  result += root->data;
  for (int i = 0; i < root->children.size(); i++)
  {
    result += sum(root->children[i]);
  }
  return result;
}

TreeNode<int> *maxSumNode(TreeNode<int> *root)
{
  vector<int> main;

  for (int i = 0; i < root->children.size(); i++)
  {
    int result = sum(root->children[i]);
    main.push_back(result);
  }

  int maxIndex = 0;
  int max = main[0];
  for (int i = 1; i < root->children.size(); i++)
  {
    if (main[i] > max)
    {
      max = main[i];
      maxIndex = i;
    }
  }

  return root->children[maxIndex];
}

int sum(TreeNode<int> *root)
{
  int result = root->data;
  for (int i = 0; i < root->children.size(); i++)
  {
    result += root->children[i]->data;
  }
  return result;
}

TreeNode<int> *maxSumNode(TreeNode<int> *root)
{
  TreeNode<int> *node = root;
  int value = sum(root);

  for (int i = 0; i < root->children.size(); i++)
  {
    TreeNode<int> *tempNode = maxSumNode(root->children[i]);
    int temp = sum(tempNode);
    if (value < temp)
    {
      node = tempNode;
      value = temp;
    }
  }
  return node;
}

int main()
{
  TreeNode<int> *root = takeInputLevelWise();
  TreeNode<int> *ans = maxSumNode(root);
  if (ans != NULL)
  {
    cout << ans->data << endl;
  }
}