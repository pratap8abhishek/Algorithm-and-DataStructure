#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
};

int detectLoop(Node* list){
    Node *slow_ptr = list,*fast_ptr = list;

    while(slow_ptr && fast_ptr && fast_ptr->next){
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
        if(slow_ptr == fast_ptr){
            return 1;
        }
    }
    return 0;
}

void push(Node** head_ref,int new_data){
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main()
{
    Node* head = NULL;

    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 10);

    /* Create a loop for testing */
    head->next->next->next->next = head;

    if (detectLoop(head))
        cout << "Loop Found";
    else
        cout << "No Loop";

    return 0;
}
