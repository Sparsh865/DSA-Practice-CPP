#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data=val;
        next=nullptr;
    }
    Node(int val,Node* next1){
        data=val;
        next=next1;
    }
};

Node* convert(vector<int> arr){
    if(arr.empty()) return nullptr;

    Node* head = new Node(arr[0]);
    Node* mover = head;

    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;

}
void inputVector(vector<int>& arr){
    for(int i=0;i<arr.size();i++){
        cin>>arr[i];
    }
}

void print(Node* head){
    Node* temp = head;

    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

Node* reverse(Node* head){
    Node* temp = head;

    stack<int> st;

    while(temp){
        st.push(temp->data);
        temp=temp->next;
    }

    temp=head;

    while(temp){
        temp->data=st.top();
        st.pop();
        temp=temp->next;
    }
    return head;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    inputVector(arr);
    Node* head = convert(arr);
    Node* head2 = reverse(head);
    print(head2);

    return 0;
}