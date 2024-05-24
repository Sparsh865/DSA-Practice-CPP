#include<bits/stdc++.h>
using namespace std;

void inputVector(vector<int>& arr){
    for(int i=0;i<arr.size();i++){
        cin>>arr[i];
    }
}

class Node{
    public:
    int data;
    Node* next;
    Node* back;

    Node(int val){
        data=val;
        next=back=nullptr;
    }
    Node(int val,Node* next1,Node* back1){
        data=val;
        next=next1;
        back=back1;
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


Node* deleteHead(Node* head){
    if(head==nullptr || head->next ==nullptr) return nullptr;

    Node* prev = head;
    head = head->next;

    head->back=nullptr;
    prev->next = nullptr;

    delete prev;
    return head;
}

Node* deleteTail(Node* head){
    if(head==nullptr || head->next ==nullptr) return nullptr;
    Node* tail = head;

    while(tail->next){
        tail=tail->next;

    }
    Node* newTail = tail->back;
    newTail->next = nullptr;
    tail->back = nullptr;
    delete tail;
    return head;
}

Node* deleteK(Node* head,int k){
    if(head==nullptr) return nullptr;
    int count=0;
    Node* kNode = head;

    while(kNode){
        count++;
        if(count==k) break;
        kNode=kNode->next;
    }

    Node* prev = kNode->back;
    Node* front = kNode->next;

    if(prev==NULL && front ==NULL) return nullptr;
    else if(prev==NULL) return deleteHead(head);
    else if(front==NULL) return deleteTail(head);

    prev->next = front;
    front->back = prev;

    kNode->back=kNode->next=nullptr;
    delete kNode;
    return head;
}

Node *deleteByValue(Node *head, int k)
{
    if (head == nullptr)
        return nullptr;
    Node *kNode = head;

    while (kNode)
    {
        if (kNode->data == k)
            break;
        kNode = kNode->next;
    }

    Node *prev = kNode->back;
    Node *front = kNode->next;

    if (prev == NULL && front == NULL)
        return nullptr;
    else if (prev == NULL)
        return deleteHead(head);
    else if (front == NULL)
        return deleteTail(head);

    prev->next = front;
    front->back = prev;

    kNode->back = kNode->next = nullptr;
    delete kNode;
    return head;
}

void deleteNode(Node* temp){
    Node* prev = temp->back;
    Node* front = temp->next;

    if(front==nullptr){
        prev->next = nullptr;
        temp->back = nullptr;
        delete temp;
        break;
    }

    prev->next=front;
    front->back= prev;

    temp->next=temp->back=nullptr;
    delete temp;

}
int main(){
    int size;
    cin>>size;
    vector<int> input(size);
    inputVector(input);

    Node* head = createDLL(input);

    head = deleteByValue(head,2);
    print(head);
    // head = deleteHead(head);
    // print(head);
    // head = deleteTail(head);
    // print(head);
}