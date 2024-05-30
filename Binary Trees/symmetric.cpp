#include<bits/stdc++.h>
using namespace std;

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

TreeNode* createTree(vector<int> arr){
    if(arr.empty()) return nullptr;

    TreeNode* root= new TreeNode(arr[0]);
    vector<TreeNode*> nodes={root};
    int parentIndex=0;

    for(int i=1;i<arr.size();i++){
        if(arr[i]!=-1){
            TreeNode* newNode =new TreeNode(arr[i]);
            if(i%2==1){
                nodes[parentIndex]->left =newNode;
            }
            else{
                nodes[parentIndex]->right = newNode;
                
            }
            nodes.push_back(newNode);
        }
        if(i%2==0){
            parentIndex++;
        }
    }
    return root;
}

void inputVector(vector<int>& arr){
    for(int i=0;i<arr.size();i++){
        cin>>arr[i];
    }
}

bool isMirror(TreeNode* left,TreeNode* right){
    if(!left && !right){
        return true;
    }
    if(!left || !right){
        return false;
    }

    return (left->data == right->data) && isMirror(left->left,right->right)&& isMirror(left->right,right->left);
}

bool isSymmetric(TreeNode *root)
{
    if (!root)
        return true;
    return isMirror(root->left, root->right);
}
int main(){
    int n;
    cin>>n;
    vector<int> input(n);
    inputVector(input);
    TreeNode* root= createTree(input);

    cout<<isSymmetric(root);
}