#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }

    Node(int val, Node *next1)
    {
        data = val;
        next = next1;
    }
};

void inputVector(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }
}

void print(Node *head)
{
    if (head == nullptr)
        return;
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

}

Node *convert(vector<int> arr)
{
    if (arr.empty())
        return nullptr;
    Node *head = new Node(arr[0]);
    Node *mover = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void mergeAlternate(Node* head1,Node* head2){
    Node* curr1 = head1;
    Node* curr2 = head2;

    Node* next1 = nullptr;
    Node* next2=nullptr;

    while(curr1 && curr2){
        next1 = curr1->next;
        next2=curr2->next;

        curr1->next=curr2;
        curr2->next=next1;
        
        curr1 =next1;
        curr2 = next2;

    }
    if (!curr1)
    {
        Node *tail = head1;
        while (tail->next)
        {
            tail = tail->next;
        }
        tail->next = curr2;
    }
}

int main()
{
    int n,m;
    cin >> n >> m;
    vector<int> input1(n);
    vector<int> input2(m);
    inputVector(input1);
    inputVector(input2);
    Node *head1 = convert(input1);
    Node *head2 = convert(input2);

    mergeAlternate(head1,head2);

    print(head1);
    

    return 0;
}