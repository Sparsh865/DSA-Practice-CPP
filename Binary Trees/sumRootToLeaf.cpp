#include <bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val){
        data=val;
        left=right=NULL;
    }

};

TreeNode* createTree(vector<int> arr){
    if(arr.empty()) return nullptr;

    TreeNode* root= new TreeNode(arr[0]);
    vector<TreeNode*> nodes= {root};
    int parentIndex=0;

    for(int i=1;i<arr.size();i++){
        if(arr[i]!=-1){
            TreeNode* newNode = new TreeNode(arr[i]);
            if(i%2==1){
                nodes[parentIndex]->left = newNode;
            }
            else{
                nodes[parentIndex]->right = newNode;
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

int sumRootToLeaf(TreeNode* root,int currentSum){
    if(root==nullptr) return 0;
    currentSum= currentSum*10 +root->data;
    if(root->left ==NULL && root->right == NULL){
        return currentSum;
    }
    return sumRootToLeaf(root->left,currentSum) + sumRootToLeaf(root->right,currentSum);
}

int main(){
    int n;
    cin>>n;
    vector<int> input(n);
    inputVector(input);
    TreeNode* root = createTree(input);
    int result= sumRootToLeaf(root,0);
    cout<<"Result: "<<result;


}