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
int GetNth(Node* head,int index)
{
    Node* curr = head;
    int count = 1;

    while(curr != nullptr){
        if(count == index)
        return curr->data;

        count++;
        curr = curr->next;
    }
    return -1;
}
int main() {
  
    // Create a hard-coded linked list:
    // 1 -> 2 -> 3 -> 4 -> 5
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Element at index 3 is " << GetNth(head, 3) << endl;

    return 0;
}