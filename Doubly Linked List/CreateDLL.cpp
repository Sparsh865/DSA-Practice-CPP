#include <bits/stdc++.h>
using namespace std;

void inputVector(vector<int> & arr){
    for(int i=0;i<arr.size();i++){
        cin>>arr[i];
    }
}

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int val){
        data=val;
        next=prev=nullptr;
    }
    Node(int val,Node* next1, Node* prev1){
        data=val;
        next=next1;
        prev=prev1;
    }
};

Node* createDLL(vector<int> arr){
    if(arr.empty()) return nullptr;

    Node* head = new Node(arr[0]);
    Node* prev = head;

    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i],nullptr,prev);
        prev->next= temp;
        prev=temp;

    }
    return head;
}

void print(Node* head){
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    int size;
    cin>>size;

    vector<int> arr(size);

    inputVector(arr);
    Node* head = createDLL(arr);

    print(head);
}