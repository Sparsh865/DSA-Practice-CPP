#include <bits/stdc++.h>
using namespace std;

// Function to input elements into a vector
void inputVector(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }
}

// Node class representing each element in the linked list
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

// Function to convert a vector into a linked list
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

// Function to traverse and print the linked list
void traversal(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to remove the head of the linked list
Node *removeHead(Node *head)
{
    if (!head)
        return nullptr;
    Node *temp = head;
    head = head->next;
    delete temp;
    return head;
}

// Function to add a new head to the linked list
Node *addHead(Node *head, int el)
{
    return new Node(el, head);
}

// Function to get the length of the linked list
int lengthOfLL(Node *head)
{
    Node *temp = head;
    int count = 0;
    while (temp)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

// Function to reverse the linked list using a stack
Node *reverseLL(Node *head)
{
    if (!head)
        return nullptr;
    Node *temp = head;
    stack<int> st;

    while (temp)
    {
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while (temp)
    {
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }
    return head;
}

// Function to find the middle of the linked list
Node *findMiddle(Node *head)
{
    if (!head)
        return nullptr;
    Node *slow = head;
    Node *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Function to check if an element exists in the linked list
bool check(Node *head, int el)
{
    Node *temp = head;
    while (temp)
    {
        if (temp->data == el)
            return true;
        temp = temp->next;
    }
    return false;
}

// Function to get the index of an element in the linked list
int checkIndex(Node *head, int el)
{
    Node *temp = head;
    int count = 0;
    while (temp)
    {
        if (temp->data == el)
            return count;
        count++;
        temp = temp->next;
    }
    return -1;
}

// Function to insert an element at the tail of the linked list
Node *insertAtTail(Node *head, int el)
{
    if (head == nullptr)
        return new Node(el);
    Node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = new Node(el);
    return head;
}

// Function to remove the element at the tail of the linked list
Node *removeAtTail(Node *head)
{
    if (!head)
        return nullptr;
    if (!head->next)
    {
        delete head;
        return nullptr;
    }
    Node *temp = head;
    while (temp->next->next)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    return head;
}

// Function to remove the kth element of the linked list
Node *removeK(Node *head, int k)
{
    if (!head)
        return nullptr;
    if (k == 1)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    int count = 0;
    Node *temp = head;
    Node *prev = nullptr;

    while (temp)
    {
        count++;
        if (count == k)
        {
            prev->next = temp->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

// Function to add a element at position k
Node *insertAtK(Node *head, int el, int k)
{
    if (head == nullptr)
    {
        if (k == 1)
            return new Node(el);
        else
            return head;
    }
    if (k == 1)
        return new Node(el, head);
    Node *temp = head;
    int count = 0;
    while (temp)
    {
        count++;
        if (count == k - 1)
        {
            Node *x = new Node(el, temp->next);
            temp->next = x;
            break;
        }
        temp = temp->next;
    }
    return head;
}

// Remove by Value

Node *removeByValue(Node *head, int el)
{
    if (head == nullptr)
        return nullptr;
    if (head->data == el)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node *temp = head;
    Node *prev = nullptr;
    while (temp)
    {
        if (temp->data == el)
        {
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

// Add before Value
Node *addBeforeValue(Node *head, int el, int key)
{
    if (head == nullptr)
        return nullptr;
    if (head->data == key)
    {
        return new Node(el, head);
    }
    Node *temp = head;
    while (temp)
    {
        if (temp->next->data == key)
        {
            Node *x = new Node(el, temp->next);
            temp->next = x;
            break;
        }
        temp = temp->next;
    }
    return head;
}

// Add after Value
Node *addAfterValue(Node *head, int el, int key)
{
    if (head == nullptr)
        return nullptr;

    Node *temp = head;
    while (temp)
    {
        if (temp->data == key)
        {
            Node *x = new Node(el, temp->next);
            temp->next = x;
            break;
        }
        temp = temp->next;
    }
    return head;
}

int main()
{
    int size;
    cin >> size; //Size 5 arr={1,2,3,4,5}
    vector<int> arr(size);
    inputVector(arr);

    // Converting vector to linked list
    Node *head = convert(arr);
    traversal(head);

    // Removing head
    head = removeHead(head);
    traversal(head);

    // Adding element to head
    head = addHead(head, 10);
    traversal(head);

    // Reverse linked list
    head = reverseLL(head);
    traversal(head);

    // Find middle
    Node *middle = findMiddle(head);
    cout << "Middle element: " << middle->data << endl;

    // Insert at tail
    head = insertAtTail(head, 15);
    traversal(head);

    // Check element existence
    cout << "Element 10 exists: " << (check(head, 10) ? "Yes" : "No") << endl;
    cout << "Index of element 2: " << checkIndex(head, 2) << endl;

    // Remove at tail
    head = removeAtTail(head);
    traversal(head);

    // Remove at k
    head = removeK(head, 2);
    traversal(head);

    // Remove by value
    head = removeByValue(head, 2);
    traversal(head);

    // Add before value
    head = addBeforeValue(head, 15, 3);
    traversal(head);

    // Add after value
    head = addAfterValue(head, 25, 15);
    traversal(head);

    return 0;
}
