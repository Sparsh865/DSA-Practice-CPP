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

void recurssionRight(TreeNode* root, int level,vector<int>& result){
    if(root==nullptr) return;

    if(result.size()==level) result.push_back(root->data);

    recurssionRight(root->right,level+1,result);
    recurssionRight(root->left,level+1,result);
}

void recurssionLeft(TreeNode *root, int level, vector<int> &result)
{
    if (root == nullptr)
        return;

    if (result.size() == level)
        result.push_back(root->data);

    recurssionLeft(root->left, level + 1, result);
    recurssionLeft(root->right, level + 1, result);
    
}

vector<int> rightSideView(TreeNode* root){
    vector<int> result;
    recurssionRight(root,0,result);
    return result;
}

vector<int> leftSideView(TreeNode* root){
    vector<int> result;
    recurssionLeft(root,0,result);
    return result;
}

int main(){
    int n;
    cin>>n;
    vector<int> input(n);
    inputVector(input);
    TreeNode* root= createTree(input);

    vector<int> left = leftSideView(root);
    vector<int> right = rightSideView(root);

    printVector(left);
    cout<<endl;
    printVector(right);

    return 0;

}