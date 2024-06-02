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

bool search(TreeNode* root, int key){
    if(root==nullptr) return false;
    while(root!=nullptr){
        if(root->data==key) return true;
        else if(key<root->data) root=root->left;
        else root=root->right;
    }
    return false;
}

TreeNode* insertBST(TreeNode* root,int key){
    if(root==nullptr) return new TreeNode(key);
    TreeNode* curr =root;
    while(true){
        if(curr->data<=key){
            if(curr->right!=nullptr){
                curr=curr->right;
            }
            else{
                curr->right = new TreeNode(key);
                break;
            }
        }
        else{
            if(curr->left!=nullptr){
                curr=curr->left;
            }
            else{
                curr->left = new TreeNode(key);
                break;
            }
        }
    }
    return root;
}


TreeNode* findLastRight(TreeNode* root){
    if(root->right==nullptr) return root;
    return findLastRight(root->right);
}

TreeNode* helper(TreeNode* root){
    if(root->left==nullptr) return root->right;
    if(root->right==nullptr) return root->left;

    TreeNode* rightSide=root->right;
    TreeNode* lastRight = findLastRight(root->left);
    lastRight->right = rightSide;
    return root->left;
}

TreeNode* deleteBST(TreeNode* root, int key){
    if(root==nullptr) return nullptr;
    if(root->data == key){
        return helper(root);
    }

    TreeNode* dummy = root;

    while(root){
        if(root->data>key){
            if(root->left !=nullptr && root->left->data==key){
                root->left = helper(root->left);
                break;
            }
            else{
                root=root->left;
            }
        }
        else{
            if(root->right !=nullptr && root->right->data==key){
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

int maxVal(TreeNode* root){
    if(root==nullptr) return -1;
    if(root->right){
        return maxVal(root->right);
    }
    else return root->data;
}

int minVal(TreeNode* root){
    if(root==nullptr) return -1;
    if(root->left){
        return minVal(root->left);
    }
    else return root->data;
}
int main(){
    int size;
    cin>>size;
    vector<int> arr(size);
    inputVector(arr);

    TreeNode* root = createTree(arr);
    cout << search(root, 10);
    cout<<endl;
    root= insertBST(root,10);
    cout<<search(root,10);
    cout << endl;
    root = deleteBST(root, 10);
    cout << search(root, 10);
    cout<<endl;
    cout<<maxVal(root)<<" "<<minVal(root)<<endl;


    return 0;

}