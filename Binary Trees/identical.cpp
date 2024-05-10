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

void inputVector(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }
}

bool isIdentical(TreeNode* r1,TreeNode* r2){
    if(r1==nullptr|| r2==nullptr) return (r1==r2);

    return (r1->data == r2->data) && isIdentical(r1->left,r2->left) && isIdentical(r1->right,r2->right);
}
int main()
{
    int n;
    cin >> n;
    vector<int> v1(n);
    inputVector(v1);
    int m;
    cin >> m;
    vector<int> v2(m);
    inputVector(v2);

    TreeNode *r1 = createTree(v1);
    TreeNode *r2 = createTree(v2);

    if(isIdentical(r1,r2)) cout<<"Identical";
    else cout<<"Non-Identical";

    return 0;
}