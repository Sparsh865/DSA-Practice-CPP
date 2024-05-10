#include <bits/stdc++.h>
using namespace std;

void inputVector(vector<int> &input)
{
    for (int i = 0; i < input.size(); i++)
    {
        cin >> input[i];
    }
}

void printVector(vector<int> &result)
{
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
}

class TreeNode{
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

TreeNode *createTree(vector<int> &arr)
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

void preOrder(TreeNode* root,vector<int>& result){
    if(root==nullptr) return;

    result.push_back(root->data);
    preOrder(root->left,result);
    preOrder(root->right,result);
}

vector<int> preOrderTraversal(TreeNode* root){
    vector<int> result;
    preOrder(root,result);
    return result;
}

int main()
{
    int n;
    cin >> n; // size of input
    vector<int> input(n);
    inputVector(input);
    TreeNode *root = createTree(input);
    vector<int> arr=preOrderTraversal(root);
    printVector(arr);

    return 0;
}