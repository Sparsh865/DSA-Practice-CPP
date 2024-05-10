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

TreeNode* insertBST(TreeNode* root,int key){
    if(root==nullptr) return new TreeNode(key);

    TreeNode* curr =root;
    while(true){
        if(curr->data <= key){
            if(curr->right!=nullptr){
            curr=curr->right;
            }
            else{
                curr->right = new TreeNode(key);
                break;
            }
        }
        else{
            if(curr->left!=nullptr){
                curr=curr->left;
            }
            else{
                curr->left=new TreeNode(key);
                break;
            }
        }
    }
    return root;
}



int main()
{
    int n;
    cin >> n;
    vector<int> input(n);
    inputVector(input);
    TreeNode *root = createTree(input);
    int key;
    cin>>key;
    TreeNode* node=insertBST(root,key);
}