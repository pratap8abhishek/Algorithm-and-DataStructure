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

// Function to find the middle of the linked list
Node* findMiddle(Node* head) {
    if (!head) return nullptr; // If the list is empty, return nullptr

    Node* slow = head;
    Node* fast = head;

    // Move fast by two steps and slow by one step until fast reaches the end
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow; // Slow pointer will be at the middle node
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
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);

    cout << "Original List: ";
    printList(head);

    Node* middle = findMiddle(head);
    if (middle) {
        cout << "Middle Node: " << middle->data << endl;
    } else {
        cout << "The list is empty." << endl;
    }

    return 0;
}
