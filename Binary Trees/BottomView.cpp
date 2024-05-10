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
void printVector(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}

vector<int> bottomView(TreeNode* root){
    vector<int> result;
    map<int,int> mpp;

    queue<pair<TreeNode*,int>> q;

    q.push({root,0});

    while(!q.empty()){
        auto it=q.front();
        q.pop();

        TreeNode* node = it.first;
        int line=it.second;

        mpp[line]=node->data;

        if(node->left!=nullptr) q.push({node->left,line-1});
        if(node->right != nullptr) q.push({node->right,line+1});
    }
    for(auto it:mpp){
        result.push_back(it.second);
    }
    return result;
}

int main()
{
    int n;
    cin >> n;
    vector<int> input(n);
    inputVector(input);
    TreeNode *root = createTree(input);
    vector<int> arr = bottomView(root);
    printVector(arr);
}