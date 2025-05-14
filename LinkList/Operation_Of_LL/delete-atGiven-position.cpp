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

Node* deleteNode(Node* head,int position){
    
    Node* prev;
    Node* temp = head;

    if(temp == NULL)
    return head;

    // Case 1: Head is to be deleted
    if(position == 1){
        head = temp->next;
        free(temp);
        return head;
    }

    // Case 2: Node to be deleted is in middle
    // Traverse till given position
    for (int i = 1; i != position; i++) {
        prev = temp;
        temp = temp->next;
    }

    // If given position is found, delete node
    if (temp != NULL) {
        prev->next = temp->next;
        free(temp);
    }
    // If given position is not present
    else {
        cout << "Data not present\n";
    }

    return head;
}


void printList(Node* curr) {
  while (curr != nullptr) {
    cout << curr->data << " ";
     curr = curr->next; 
    }
}
int main()
{
    Node* head = new Node(3);
    head->next = new Node(12);
    head->next->next = new Node(15);
    head->next->next->next = new Node(18);
    head = deleteHead(head);
    cout << "Original list: ";
    printList(head);

    // Deleting node at position 2
    int position = 2;
    head = deleteNode(head, position);

    cout << "List after deletion : ";
    printList(head);

    // Cleanup remaining nodes
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}