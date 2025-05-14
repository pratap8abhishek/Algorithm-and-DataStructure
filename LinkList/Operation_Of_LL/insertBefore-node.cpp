#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(int new_data)
    {
        data = new_data;
        next = nullptr;
    }
};
void printList(Node* head){
    while(head != nullptr){
        cout << head->data <<" ";
        head = head->next;
    }
    cout << endl;
}
Node* insertBeforeKey(Node* head,int key, int newData){
    if(head == nullptr){
        return nullptr;
    }
    // Special case: if the key is at the head
    if(head->data == key){
        Node* new_node = new Node(newData);
        new_node->next = head;
        return new_node;
    }

    Node* curr = head;
    Node* prev = nullptr;

    // Traverse the list to find the key
    while (curr != nullptr && curr->data != key) {
        prev = curr;
        curr = curr->next;
    }

    if(curr != nullptr){
        Node* new_node = new Node(newData);
        prev->next = new_node;
        new_node->next = curr;
    }
    return head;
}
int main()
{
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(4);
    head->next->next->next = new Node(5);
    cout << "Original Linked List :";
    printList(head);

    cout << "After inserting Nodes at the front :";
    int key = 4, newData = 10;

    head = insertBeforeKey(head, key, newData);
    
    printList(head);

    return 0;
}









