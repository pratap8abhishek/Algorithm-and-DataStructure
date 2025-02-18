#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = nullptr;
    }
};

Node* reverseKNodes(Node* head,int k){
    if(!head || k <= 1) return head;

    Node* curr = head;
    Node* prev = nullptr;
    Node* next = nullptr;
    int count = 0;

// Count the number of nodes in the current group
    Node* temp = head;
    for(int i = 0;i < k && temp;i++){
        temp = temp->next;
        count++;
    }

   // Reverse `k` nodes if we have enough nodes
   if(count == k){
    count = 0;
    while(curr && count < k){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    // Recursively reverse the remaining list
        if (next) {
            head->next = reverseKNodes(next, k);
        }

    // `prev` is the new head after reversing the group
        return prev;
   } 
   // If there are fewer than `k` nodes, return the head as is
    curr = head;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

void printList(Node* head)
{
    while(head){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout << endl;
}
int main()
{
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(7);

    cout<<"Original List: ";
    printList(head);

    int k = 3;
    head = reverseKNodes(head,k);

    cout<<"Reversed List in group of " << k <<":";
    printList(head);
    return 0;

}