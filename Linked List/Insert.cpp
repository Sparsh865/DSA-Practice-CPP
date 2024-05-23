#include<bits/stdc++.h>
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

Node* convert(vector<int>& arr){
    if(arr.empty()) return nullptr;

    Node* head= new Node(arr[0]);
    Node* mover= head;

    for(int i=1;i<arr.size();i++){
        Node* temp= new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}

void print(Node* head){
    Node* temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

Node* insertAtHead(Node* head,int val){
    return new Node(val,head);
}

Node *insertAtTail(Node *head, int val){
    if(head==nullptr) return new Node(val);
    Node* temp = head;
    while(temp->next){
        temp=temp->next;
    }
    Node* newNode = new Node(val);
    temp->next=newNode;
    return head;
}

Node* insertAtPosition(Node* head,int el, int k){
    if(head==nullptr){
        if(k==1){
            return new Node(el);
        }
        else{
            return head;
        }
    }
    if(k==1){
        return new Node(el,head);
    }
    int counter=0;
    Node* temp= head;
    while(temp){
        counter++;
        if(counter==(k-1)){
            Node* x = new Node(el,temp->next);
            temp->next=x;
            break;
        }
        temp=temp->next;
    }
    return head;

}

Node* insertBeforeValue(Node* head,int el,int before){
    if(head==nullptr) return nullptr;

    if(head->data==before){
        return new Node(el,head);
    }
    Node*temp=head;
    while(temp){
        if(temp->next->data==before){
            Node* x = new Node(el,temp->next);
            temp->next=x;
            break;
        }
        temp=temp->next;
    }
    return head;
}

Node *insertAfterValue(Node *head, int el, int after)
{
    if (head == nullptr) return nullptr;

    Node *temp = head;
    while (temp)
    {
        if (temp->data == after)
        {
            Node *x = new Node(el, temp->next);
            temp->next = x;
            break;
        }
        temp = temp->next;
    }
    return head;
}

int main(){
    vector<int> arr = {1,2,8,6,7};

    Node* head = convert(arr);
    // head=insertAtHead(head,10);
    // head= insertAtTail(head,20);
    head=insertAfterValue(head,15,1);
    print(head);
}

