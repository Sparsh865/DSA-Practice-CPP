#include<bits/stdc++.h>
using namespace std;

void inputVector(vector<int>& input){
    for(int i =0;i<input.size();i++){
        cin>>input[i];
    }
}

class TreeNode{
    public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val){
        data=val;
        left=right=nullptr;
    }

};

TreeNode *createTree(vector<int> arr){
    if (arr.empty())
        return nullptr;

    TreeNode *root = new TreeNode(arr[0]);
    vector<TreeNode *> nodes = {root};
    int parentIndex = 0;

    for (int i = 1; i < arr.size(); i++){
        if (arr[i] != -1){
            TreeNode *newNode = new TreeNode(arr[i]);
            if (i % 2 == 1){
                nodes[parentIndex]->left = newNode;
            }
            else{
                nodes[parentIndex]->right = newNode;

            }
            nodes.push_back(newNode);
        }

        if (i % 2 == 0){
            parentIndex++;
        }
    }

    return root;
}

int dfsHeight(TreeNode *root)
{

    if (root == NULL)
        return 0;

    int leftHeight = dfsHeight(root->left);

    if (leftHeight == -1)
        return -1;
    
    int rightHeight = dfsHeight(root->right);

    if (rightHeight == -1)
        return -1;

    if (abs(leftHeight - rightHeight) > 1)
        return -1;

    return max(leftHeight, rightHeight) + 1;
}
bool isBalanced(TreeNode *root)
{
    return dfsHeight(root) != -1;
}

int main(){
    int n;
    cin>>n;
    vector<int> input(n);
    inputVector(input);
    TreeNode *root = createTree(input);
    if(isBalanced(root)) cout<<"Yes";
    else cout<<"No";
   
    return 0;
}