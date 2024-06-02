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
void inputVector(string str,vector<int>& arr){
    for(char c: str){
        arr.push_back(c- '0');
    }
}
void printVector(vector<int>& arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}

TreeNode* createTree(vector<int>& arr){
    if(arr.empty()) return nullptr;

    TreeNode* root = new TreeNode(arr[0]);
    vector<TreeNode*> nodes={root};
    int parentIndex=0;
    for(int i=1;i<arr.size();i++){
        TreeNode* newNode = new TreeNode(arr[i]);
        if(arr[i]!=-1){
            if(i%2==1){
                nodes[parentIndex]->left = newNode;
            }
            else{
                nodes[parentIndex]->right = newNode;
            }
            nodes.push_back(newNode);
        }
        if(i%2==0) parentIndex++;
    }
    return root;

}

void RecurrsionLeft(TreeNode* root,int level,vector<int>& result){
    if(root==nullptr) return;

    if(result.size()==level) result.push_back(root->data);

    RecurrsionLeft(root->left,level+1,result);
    RecurrsionLeft(root->right,level+1,result);
}
void RecurrsionRight(TreeNode* root,int level,vector<int>& result)
{
    if(root==nullptr) return;

    if(result.size()==level) result.push_back(root->data);

    RecurrsionRight(root->right,level+1,result);
    RecurrsionRight(root->left,level+1,result);
}
vector<int> leftView(TreeNode *root)
{
    vector<int> result;
    RecurrsionLeft(root, 0, result);
    return result;
}

vector<int> rightView(TreeNode *root)
{
    vector<int> result;
    RecurrsionRight(root, 0, result);
    return result;
}

vector<int> topView(TreeNode* root){
    map<int,int> mpp;
    vector<int> result;

    queue<pair<TreeNode*,int>> q;

    q.push({root,0});

    while(!q.empty()){
        auto it = q.front();
        q.pop();
        TreeNode* node = it.first;
        int line =it.second;

        if(mpp.find(line)==mpp.end()){
            mpp[line]=node->data;
        }
        if(node->left !=nullptr) q.push({node->left,line-1});
        if(node->right !=nullptr) q.push({node->right,line+1});

       
    }
    for (auto it : mpp)
    {
        result.push_back(it.second);
    }
    return result;
}

vector<int>bottomView(TreeNode* root){
    map<int,int> mpp;
    vector<int> result;
    queue<pair<TreeNode*,int>> q;

    q.push({root,0});

    while(!q.empty()){
        auto it = q.front();
        q.pop();

        TreeNode* node = it.first;
        int line = it.second;

        mpp[line]=node->data;

        if(node->left!=nullptr) q.push({node->left,line-1});
        if(node->right!=nullptr) q.push({node->right,line+1});

        
    }
    for (auto it : mpp)
    {
        result.push_back(it.second);
    }

    return result;
}
int main(){
    string str;
    getline(cin,str);
    vector<int> input;
    inputVector(str,input);

    TreeNode* root = createTree(input);
    vector<int> left = leftView(root);
    vector<int> right = rightView(root);
    vector<int> top = topView(root);
    vector<int> bottom = bottomView(root);

    cout<<"Top View: ";
    printVector(top);
    cout<<endl;
    cout << "Bottom View: ";
    printVector(bottom);
    cout << endl;
    cout << "Left View: ";
    printVector(left);
    cout << endl;
    cout << "Right View: ";
    printVector(right);
    cout << endl;

    return 0;
}