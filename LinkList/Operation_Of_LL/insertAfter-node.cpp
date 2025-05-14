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
Node* insertAfter(Node* head,int key, int newData){
    Node* curr = head;

    while(curr != nullptr){
        if(curr->data == key)
        break;
        curr = curr->next;
    }

    if (curr == nullptr) {
    	cout << "Node not found" << endl;  
        // Return the head of the original linked list
      	return head;
    }

    Node* newNode = new Node(newData);
    newNode->next = curr->next;
    curr->next = newNode;
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

    head = insertAfter(head, key, newData);
    
    printList(head);

    return 0;
}









