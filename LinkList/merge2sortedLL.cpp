#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;
    Node(int x)
    {
        data = x;
        next = nullptr;
    }
};
Node* sortedMerge(Node* head1,Node* head2){
    vector<int> arr;
    
    while(head1 != nullptr){
        arr.push_back(head1->data);
        head1 = head1->next;
    }
    while(head2 != nullptr){
        arr.push_back(head2->data);
        head2 = head2->next;
    }
    
    sort(arr.begin(),arr.end());
    
    Node* dummy = new Node(-1);
    Node* curr = dummy;

    for(int i = 0;i < arr.size();i++){
        curr->next = new Node(arr[i]);
        curr = curr->next;
    }
    return dummy->next; 
}
void printList(Node *curr) {
    while (curr != nullptr) {
        cout << curr->data;
        if (curr->next != nullptr)
            cout << " ";
        curr = curr->next;
    }
    cout << endl;
}
int main()
{
    // First linked list: 5 -> 10 -> 15
    Node *head1 = new Node(5);
    head1->next = new Node(10);
    head1->next->next = new Node(15);

    // Second linked list: 2 -> 3 -> 20
    Node *head2 = new Node(2);
    head2->next = new Node(3);
    head2->next->next = new Node(20);
    
    // Merging the two sorted linked lists
    Node *res = sortedMerge(head1, head2);
     printList(res);
    return 0;
}
/////////////////////////////////////////////////////////////////////////////////////

// Function to merge two sorted linked lists iteratively

Node* sortedMerge(Node* head1, Node* head2) {
  
    // Create a dummy node to simplify 
    // the merging process
    Node* dummy = new Node(-1);
    Node* curr = dummy;

    // Iterate through both linked lists
    while (head1 != nullptr && head2 != nullptr) {
      
        // Add the smaller node to the merged list
        if (head1->data <= head2->data) {
            curr->next = head1;
            head1 = head1->next;
        } else {
            curr->next = head2;
            head2 = head2->next;
        }
        curr = curr->next;
    }

    // If any list is left, append it to
    // the merged list
    if (head1 != nullptr) {
        curr->next = head1;
    } else {
        curr->next = head2;
    }

    // Return the merged list starting
    // from the next of dummy node
    return dummy->next;
}

void printList(Node *curr) {
    while (curr != nullptr) {
        cout << curr->data;
        if (curr->next != nullptr)
            cout << " ";
        curr = curr->next;
    }
    cout << endl;
}
int main()
{
    // First linked list: 5 -> 10 -> 15
    Node *head1 = new Node(5);
    head1->next = new Node(10);
    head1->next->next = new Node(15);

    // Second linked list: 2 -> 3 -> 20
    Node *head2 = new Node(2);
    head2->next = new Node(3);
    head2->next->next = new Node(20);
    
    // Merging the two sorted linked lists
    Node *res = sortedMerge(head1, head2);
     printList(res);
    return 0;
}