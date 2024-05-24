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

Node *insertBeforeHead(Node *head, int el)
{
    Node *newNode = new Node(el);
    if (head == nullptr)
        return newNode;

    newNode->next = head;
    head->back = newNode;
    head = newNode;

    return head;
}

Node *insertAfterHead(Node *head, int el)
{
    Node *newNode = new Node(el);
    if (head == nullptr)
        return newNode;

    newNode->next = head->next;
    newNode->back = head;

    if (head->next != nullptr)
    {
        head->next->back = newNode;
    }
    head->next = newNode;
    return head;
}

Node *insertAfterTail(Node *head, int el)
{
    Node *newNode = new Node(el);
    if (head == nullptr)
        return newNode;

    Node *tail = head;
    while (tail->next)
    {
        tail = tail->next;
    }
    tail->next = newNode;
    newNode->back = tail;
    return head;
}

Node *insertBeforeTail(Node *head, int el)
{
    if (head->next == nullptr)
        return insertBeforeHead(head, el);

    Node *tail = head;

    while (tail->next)
    {
        tail = tail->next;
    }
    Node *prev = tail->back;
    Node *newNode = new Node(el, tail, prev);
    prev->next = newNode;
    tail->back = newNode;
    return head;
}

Node *insertBeforeK(Node *head, int k, int val)
{
    if (head == nullptr)
    {
        if (k == 1)
        {
            return new Node(val);
        }
        else
        {
            return nullptr;
        }
    }

    if (k == 1)
    {
        return insertBeforeHead(head, val);
    }
    Node *temp = head;
    int count = 0;
    while (temp)
    {
        count++;
        if (count == k)
        {
            break;
        }
        temp = temp->next;
    }

    Node *prev = temp->back;
    Node *newNode = new Node(val, temp, prev);
    prev->next = newNode;
    temp->back = newNode;
    return head;
}
Node *insertAfterK(Node *head, int k, int val){
    if (head == nullptr)
    {
        if (k == 1)
        {
            return new Node(val);
        }
        else
        {
            return nullptr;
        }
    }

    Node *temp = head;
    int count = 1;
    while (temp){
        if (count == k)
        {
            break;
        }
        temp = temp->next;
        count++;
    }

    if (temp == nullptr){
        // If k is greater than the length of the list, do nothing or handle as needed
        return head;
    }

    Node *newNode = new Node(val, temp->next, temp);

    if (temp->next != nullptr){
        temp->next->back = newNode;
    }
    temp->next = newNode;

    return head;
}

int main()
{
    int size;
    cin >> size;
    vector<int> input(size);
    inputVector(input);

    Node *head = createDLL(input);

    head = insertBeforeHead(head, 15);
    head = insertAfterHead(head, 45);

    head = insertAfterTail(head, 25);
    head = insertBeforeTail(head, 35);

    print(head);
}