#include <bits/stdc++.h>
using namespace std;
class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

TreeNode *createTree(vector<int> arr)
{
    if (arr.empty())
        return nullptr;

    TreeNode *root = new TreeNode(arr[0]);
    vector<TreeNode *> nodes = {root};
    int parentIndex = 0;

    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] != -1)
        {
            TreeNode *newNode = new TreeNode(arr[i]);
            if (i % 2 == 1)
            {
                nodes[parentIndex]->left = newNode;
            }
            else
            {
                nodes[parentIndex]->right = newNode;
                parentIndex++;
            }
            nodes.push_back(newNode);
        }
    }
    return root;
}

vector<int> levelOrder(TreeNode *root)
{
    vector<int> result;
    if (root == nullptr)
        return result;

    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode *newNode = q.front();
            q.pop();
            if (newNode->left != nullptr)
                q.push(newNode->left);
            if (newNode->right != nullptr)
                q.push(newNode->right);
            result.push_back(newNode->data);
        }
    }
    return result;
}

void inputVector(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }
}

void printVector(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> input(n);
    inputVector(input);
    TreeNode *root = createTree(input);
    vector<int> arr = levelOrder(root);
    printVector(arr);
}