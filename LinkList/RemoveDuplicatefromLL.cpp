#include <bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;
};

void removeDuplicates(Node* head){
    Node* curr = head;
    Node* next_next;
    if(curr == NULL)
    return;

    while(curr->next!=NULL){
        if(curr->data == curr->next->data){
            next_next = curr->next->next;
            free(curr->next);
            curr->next = next_next;
        }
        else{
            curr = curr->next;
        }
    }
}

void push(Node** head_ref,int new_data){
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
void printList(Node* node){
    while(node != NULL){
        cout<<" "<<node->data;
        node = node->next;
    }
}
int main()
{
    Node* head = NULL;
    push(&head, 10);
    push(&head, 10);
    push(&head, 11);
    push(&head, 11);
    push(&head, 12);
    push(&head, 12);
    push(&head, 13);
    push(&head, 13);

    cout << "Linked list before duplicate removal " << endl;
    printList(head);

    removeDuplicates(head);

    cout << "\nLinked list after duplicate removal " << endl;
    printList(head);

    return 0;
}