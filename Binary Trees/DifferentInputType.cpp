#include <bits/stdc++.h>
using namespace std;

class TreeNode{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val)
    {
        data = val;
        left = right = nullptr;
    }

    TreeNode(int val, TreeNode *left, TreeNode *right)
    {
        this->data = val;
        this->left = left;
        this->right = right;
    }
};

void inputVectorSize(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }
}
void inputVectorWithoutSize(vector<int>& arr){
    int input;
    while(cin>>input && input!=-1){
        arr.push_back(input);
    }
}

void inputVectorString(vector<int>& arr,string& str){
    // for(char c: str){ arr.push_back(c-'0');}
    for(char c:str){ arr.push_back(stoi(string(1,c)));}
}

void printVector(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

TreeNode *createTree(vector<int> &arr)
{
    if (arr.empty())
        return nullptr;

    TreeNode *root = new TreeNode(arr[0]);
    int parentIndex = 0;
    vector<TreeNode *> nodes = {root};
    for (int i = 1; i < arr.size(); i++){
        TreeNode *newNode = new TreeNode(arr[i]);
        if (arr[i] != -1){
            if (i % 2 != 0){
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

void postOrder(TreeNode* root,vector<int>& postOrderVector){
    if(root==nullptr) return;

    postOrder(root->left,postOrderVector);
    postOrder(root->right, postOrderVector);
    postOrderVector.push_back(root->data);
}

vector<int> postOrderTraversal(TreeNode* root){
    vector<int> postOrderVector;
    postOrder(root,postOrderVector);
    return postOrderVector;
}


int main(){
    string str;
    getline(cin, str);
    vector<int> input;
    inputVectorString(input,str);
    TreeNode* root = createTree(input);
    vector<int> postOrder = postOrderTraversal(root);
    printVector(postOrder);

}