#include<bits/stdc++.h>
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

void zigzag(TreeNode* root){
    if(!root) return;
    stack<TreeNode*> currentLevel;
    stack<TreeNode*> nextLevel;
    bool leftToRight = true;

    currentLevel.push(root);

    while(!currentLevel.empty()){
        TreeNode* node = currentLevel.top();
        currentLevel.pop();

        if(node){
            cout<<node->data<<" ";

            if(leftToRight){
                if(node->left) nextLevel.push(node->left);
                if(node->right) nextLevel.push(node->right);
            }
            else{
                if(node->right) nextLevel.push(node->right);
                if(node->left) nextLevel.push(node->left);
            }
        }

        if(currentLevel.empty()){
            swap(currentLevel,nextLevel);
            leftToRight = !leftToRight;
        }
    }
    cout<<endl;

}

int main(){
    vector<int> arr={1,2,3,4,5,6,7};
    TreeNode* root = createTree(arr);
    zigzag(root);
    return 0;
}