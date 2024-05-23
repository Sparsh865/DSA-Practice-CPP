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

void inputVector(vector<int> &arr){
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }
}

TreeNode* constructBST(vector<int>nums,int start,int end){
    if(start>end) return nullptr;

    int mid= start+(end-start)/2;

    TreeNode* root = new TreeNode(nums[mid]);
    root->left=constructBST(nums,0,mid-1);
    root->right=constructBST(nums,mid+1,end);
    return root;
}
TreeNode* constructBST(vector<int> nums){
    if(nums.empty()) return nullptr;
    return constructBST(nums,0,nums.size()-1);
}

int main()
{
    int n;
    cin >> n;
    vector<int> input(n);
    inputVector(input);
    TreeNode *root = constructBST(input);
    cout<<root->data;

}