<<<<<<< HEAD
#include <bits/stdc++.h>
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

TreeNode* findLastRight(TreeNode* root){
    if(root->right==nullptr) return root;
    return findLastRight(root->right);
}
TreeNode* helper(TreeNode* root){
    if(root->left ==nullptr) return root->right;
    if(root->right == nullptr) return root->left;

    TreeNode* rightSide= root->right;
    TreeNode* lastRight= findLastRight(root->left);
    lastRight->right=rightSide;
    return root->left;
}

TreeNode *deleteBST(TreeNode *root, int key)
{
    if (root == nullptr)
        return nullptr;

    if (root->data == key)
    {
        return helper(root);
    }

    TreeNode *dummy = root;

    while (root != nullptr)
    {
        if (root->data > key){
            if (root->left != nullptr && root->left->data == key){
                root->left = helper(root->left);
                break;
            } else{
                root = root->left;
            }
        }
        else{
            if(root->right!=nullptr && root->right->data==key){
                root->right = helper(root->right);
                break;
            }
            else{
                root=root->right;
            }
        }
    }
    return dummy;
}

int main()
{
    int n;
    cin >> n;
    vector<int> input(n);
    inputVector(input);
    TreeNode *root = createTree(input);
    int key;
    cin >> key;
    TreeNode *node = deleteBST(root, key);
    cout<<node->data;
=======
#include <bits/stdc++.h>
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

TreeNode* findLastRight(TreeNode* root){
    if(root->right==nullptr) return root;
    return findLastRight(root->right);
}
TreeNode* helper(TreeNode* root){
    if(root->left ==nullptr) return root->right;
    if(root->right == nullptr) return root->left;

    TreeNode* rightSide= root->right;
    TreeNode* lastRight= findLastRight(root->left);
    lastRight->right=rightSide;
    return root->left;
}

TreeNode *deleteBST(TreeNode *root, int key)
{
    if (root == nullptr)
        return nullptr;

    if (root->data == key)
    {
        return helper(root);
    }

    TreeNode *dummy = root;

    while (root != nullptr)
    {
        if (root->data > key){
            if (root->left != nullptr && root->left->data == key){
                root->left = helper(root->left);
                break;
            } else{
                root = root->left;
            }
        }
        else{
            if(root->right!=nullptr && root->right->data==key){
                root->right = helper(root->right);
                break;
            }
            else{
                root=root->right;
            }
        }
    }
    return dummy;
}

int main()
{
    int n;
    cin >> n;
    vector<int> input(n);
    inputVector(input);
    TreeNode *root = createTree(input);
    int key;
    cin >> key;
    TreeNode *node = deleteBST(root, key);
    cout<<node->data;
>>>>>>> 087af673ca299ee247e54bd933affbfecfd387ce
}