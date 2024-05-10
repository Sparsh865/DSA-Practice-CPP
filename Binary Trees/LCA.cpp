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

    TreeNode* root =new TreeNode(arr[0]);
    vector<TreeNode*> nodes={root};
    int parentIndex=0;

    for(int i=1;i<arr.size();i++){
        if(arr[i]!=-1){
            TreeNode* newNode= new TreeNode(arr[i]);
            if(i%2==1){
                nodes[parentIndex]->left=newNode;
            }
            else{
                nodes[parentIndex]->right=newNode;
                parentIndex++;
            }
            nodes.push_back(newNode);
        }
    }
    return root;
}

void inputVector(vector<int>& arr){
    for(int i=0;i<arr.size();i++){
        cin>>arr[i];
    }
}

TreeNode* lca(TreeNode* root,int p,int q){
    if(root==nullptr) return NULL;
    if(root->data==p || root->data==q){
        return root;
    }
    TreeNode* left = lca(root->left,p,q);
    TreeNode* right = lca(root->right,p,q);

    if(left !=nullptr && right != nullptr ) return root;
    if(left!= nullptr) return left;
    return right;
}

int main(){
    int n;
    cin>>n;
    vector<int> input(n);
    inputVector(input);
    int p,q;
    cin>>p>>q;
    TreeNode* root= createTree(input);
    TreeNode* result= lca(root,p,q);
    cout<<result->data;
    return 0;
}