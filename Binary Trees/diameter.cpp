#include<bits/stdc++.h>
using namespace std;

void inputVector(vector<int>& input){
    for(int i=0;i<input.size();i++){
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

TreeNode* createTree(vector<int> arr){
    if(arr.empty()) return nullptr;

    TreeNode* root= new TreeNode(arr[0]);
    vector<TreeNode*> nodes={root};
    int parentIndex=0;

    for(int i=1;i<arr.size();i++){
        if(arr[i]!=-1){
            TreeNode* newNode = new TreeNode(arr[i]);

            if(i%2==1){
                nodes[parentIndex]->left=newNode;
            }
            else{
                nodes[parentIndex]->right=newNode;
                
            }
            nodes.push_back(newNode);
        }
        if(i%2==0){
            parentIndex++;
        }
    }
    return root;
}
// int maxDepth(TreeNode* root){
//     if(root==nullptr) return 0;

//     int lh=maxDepth(root->left);
//     int rh=maxDepth(root->right);

//     return 1+max(lh,rh);
// }

// int diameterBT(TreeNode* root){
//     if (root == nullptr)
//         return 0;

//     int lh = maxDepth(root->left);
//     int rh = maxDepth(root->right);

//     int ld=diameterBT(root->left);
//     int rd=diameterBT(root->right);

//     return max(lh+rh,max(ld,rd));
// }

int height(TreeNode *root, int &diameter)
{
    if (root == nullptr)
        return 0;

    int lh = height(root->left, diameter);
    int rh = height(root->right, diameter);
    diameter = max(diameter, lh + rh);
    return 1 + max(lh, rh);
}

int main(){
    int n;
    cin>>n;

    vector<int> input(n);

    inputVector(input);
    TreeNode* root = createTree(input);
    int diameter=0;
    height(root,diameter);
    cout<<diameter;
}