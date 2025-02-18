#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Function to rotate the linked list by k nodes
Node* rotateList(Node* head, int k) {
    if (!head || k == 0) return head; // No rotation needed if the list is empty or k is 0

    // Find the length of the linked list
    Node* current = head;
    int length = 1;
    while (current->next) {
        current = current->next;
        length++;
    }

    // Connect the last node to the head to form a circular list
    current->next = head;

    // Find the new head and tail
    k = k % length; // To handle cases where k >= length
    int stepsToNewHead = length - k;
    Node* newTail = head;

    for (int i = 1; i < stepsToNewHead; i++) {
        newTail = newTail->next;
    }

    Node* newHead = newTail->next;
    newTail->next = nullptr; // Break the circular connection

    return newHead;
}

// Function to print the linked list
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Original List: ";
    printList(head);

    int k = 3; // Number of rotations
    head = rotateList(head, k);

    cout << "Rotated List: ";
    printList(head);

    return 0;
}
