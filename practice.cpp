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

TreeNode* createTree(vector<int>& arr){
    if(arr.empty()) return nullptr;
    
    TreeNode* root = new TreeNode(arr[0]);
    vector<TreeNode*> nodes = {root};
    int parentIndex=0;

    for(int i=1;i<arr.size();i++){
        TreeNode *newNode = new TreeNode(arr[i]);
        if(arr[i]!=-1){
            if(i%2!=0){
                nodes[parentIndex]->left = newNode;
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

void printVector(vector<int>& arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}

int heightTree(TreeNode* root,int& diameter){
    if(root==nullptr) return 0;
    int lh = heightTree(root->left,diameter);
    int rh = heightTree(root->right,diameter);
    diameter = max(diameter,lh+rh);
    return 1+ max(lh,rh);
}

int dfsHeight(TreeNode* root){
    if (root==nullptr) return 0;

    int lh = dfsHeight(root->left);
    if(lh==-1) return -1;
    
    int rh = dfsHeight(root->right);
    if(rh==-1) return -1;

    if(abs(lh-rh)>1) return -1;

    return 1+max(lh,rh);
 }
bool balanced(TreeNode* root){
    return dfsHeight(root)!=-1;
}

int sumRootToLeaf(TreeNode* root,int currentSum){
    if(root==nullptr) return 0;
    currentSum=currentSum* 10 + root->data;
    if(root->left ==nullptr && root->right==nullptr){
        return currentSum;
    }
    return sumRootToLeaf(root->left, currentSum) + sumRootToLeaf(root->right, currentSum);
}

vector<int> levelOrder(TreeNode* root){
    vector<int> result;
    if(root==nullptr) return result;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size;i++){
            TreeNode* newNode = q.front();
            q.pop();
            if(newNode->left!= nullptr) q.push(newNode->left);
            if(newNode->right!= nullptr) q.push(newNode->right);
            result.push_back(newNode->data);
        }
    }
    return result;
}

bool isMirror(TreeNode* left,TreeNode* right){
    if (!left && !right)
        return true;

    if(!left ||!right) return false;

    return (left->data==right->data) && isMirror(left->left,right->right) && isMirror(left->right,right->left);
}

bool isSymetric(TreeNode* root){
    if(root==nullptr) return true;
    return isMirror(root->left,root->right);
}


int main(){
    int n;
    cout<<"Size of vector: ";
    cin>>n;
    vector<int> arr1(n);
    inputVector(arr1);
    TreeNode* root = createTree(arr1);
    int diameter=0;
    int currentSum=0;
    int height = heightTree(root,diameter);
    int result = sumRootToLeaf(root, currentSum);
    cout<< "Height: " << height << endl;
    cout<<"Diameter: "<<diameter<<endl;
    if(balanced(root)) cout<<"Tree is Balanced"<<endl;
    else cout<<"Tree is not Balanced"<<endl;
    cout<<"Sum Root To Leaf: "<<result<<endl;
    vector<int> level = levelOrder(root);
    printVector(level);
    cout<<endl;
    cout<<isSymetric(root);

    return 0;


}