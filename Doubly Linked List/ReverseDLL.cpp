#include <bits/stdc++.h>
using namespace std;

void inputVector(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }
}

class Node
{
public:
    int data;
    Node *next;
    Node *back;

    Node(int val)
    {
        data = val;
        next = back = nullptr;
    }
    Node(int val, Node *next1, Node *back1)
    {
        data = val;
        next = next1;
        back = back1;
    }
};

Node *createDLL(vector<int> arr)
{
    if (arr.empty())
        return nullptr;

    Node *head = new Node(arr[0]);
    Node *prev = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* reverseDL(Node* head){
    Node* temp=head;
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
    int size;
    cin >> size;
    vector<int> input(size);
    inputVector(input);

    Node *head = createDLL(input);

    head = reverseDL(head);
    print(head);
}