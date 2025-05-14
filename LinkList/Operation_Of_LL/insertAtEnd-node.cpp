#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
    
        // Constructor to initialize a new node with data
        Node(int new_data) {
            data = new_data;
            next = nullptr;
        }
    };
void printList(Node* node) {
        while (node != nullptr) {
            cout << " " << node->data;
            node = node->next;
        }
    }

Node* append(Node* head, int new_data) {

 Node* new_node = new Node(new_data);
 if (head == nullptr) {
    return new_node;
}

Node* last = head;

while (last->next != nullptr) {
    last = last->next;
}

last->next = new_node;

return head;

}
int main() {
  
    // Create a hard-coded linked list:
    // 2 -> 3 -> 4 -> 5 -> 6
    Node* head = new Node(2);
    head->next = new Node(3);
    head->next->next = new Node(4);
    head->next->next->next = new Node(5);
    head->next->next->next->next = new Node(6);

    cout << "Created Linked list is:";
    printList(head);

    // Example of appending a node at the end
    head = append(head, 1);

    cout << "\nAfter inserting 1 at the end:";
    printList(head);

    return 0;
}