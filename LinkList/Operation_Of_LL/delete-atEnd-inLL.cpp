#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = nullptr;
    }
};
Node* removeLastNode(struct Node* head)
{
   if (head == nullptr) {
      return nullptr;
    }
    if(head->next == nullptr){
        delete head;
        return nullptr;
    }
    
    Node* temp = head;
    while(temp->next->next != nullptr){
        temp = temp->next;
    }
    delete(temp->next);

    temp->next = nullptr;

    return head;

}
void printList(Node* head)
{
    while (head != nullptr) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "nullptr" << endl;
}
int main()
{
    // Creating a static linked list
    // 1 -> 2 -> 3 -> 4 -> 5 -> nullptr
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Original list: ";
    printList(head);

    // Removing the last node
    head = removeLastNode(head);

    cout << "List after removing the last node: ";
    printList(head);


    return 0;
}