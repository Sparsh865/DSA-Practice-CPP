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

void inputVector(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }
}

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

int maxVal(TreeNode* root){
    if(root==nullptr) return -1;

    if(root->right){
        return maxVal(root->right);
    }
    else return root->data;
}
int minVal(TreeNode *root)
{
    if (root == nullptr)
        return -1;

    if (root->left)
    {
        return minVal(root->left);
    }
    else
        return root->data;
}

int main()
{
    int n;
    cin >> n;
    vector<int> input(n);
    inputVector(input);
    TreeNode *root = createTree(input);
    cout<<minVal(root)<<" "<<maxVal(root);
}