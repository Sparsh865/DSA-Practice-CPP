<<<<<<< HEAD
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

// bool searchBST(TreeNode* root,int key){

//     while(root != nullptr ){
//         if(key==root->data) return true;
//         else if(key<root->data) root=root->left;
//         else{
//             root=root->right;
//         }
//     }
//     return false;
// }
void printVector(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}
TreeNode* searchBST(TreeNode* root,int key){
    while(root!=nullptr && root->data!=key){
        if(key<root->data) root=root->left;
        else root=root->right;
    }
    return root;
}
int main(){
    int n;
    cin>>n;
    vector<int> input(n);
    inputVector(input);
    TreeNode* root= createTree(input);
    int key;
    cin>>key;

    TreeNode* node = searchBST(root,key);
    
    printVector(node);
    // cout<<searchBST(root,key);
=======
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

// bool searchBST(TreeNode* root,int key){

//     while(root != nullptr ){
//         if(key==root->data) return true;
//         else if(key<root->data) root=root->left;
//         else{
//             root=root->right;
//         }
//     }
//     return false;
// }
void printVector(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}
TreeNode* searchBST(TreeNode* root,int key){
    while(root!=nullptr && root->data!=key){
        if(key<root->data) root=root->left;
        else root=root->right;
    }
    return root;
}
int main(){
    int n;
    cin>>n;
    vector<int> input(n);
    inputVector(input);
    TreeNode* root= createTree(input);
    int key;
    cin>>key;

    TreeNode* node = searchBST(root,key);
    
    printVector(node);
    // cout<<searchBST(root,key);
>>>>>>> 087af673ca299ee247e54bd933affbfecfd387ce
}