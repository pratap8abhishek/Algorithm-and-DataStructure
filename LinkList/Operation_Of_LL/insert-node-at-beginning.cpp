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
        cout << head->data <<" "
        head = head->next;
    }
    cout << endl;
}
Node* insertAtFront(Node* head,int new_data)
{
    Node* new_node = new Node(new_data);

    new_node->next = head;

    return new_node;
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
    int data = 10;

    head = insertAtFront(head, data);
    printList(head);

    return 0;
}