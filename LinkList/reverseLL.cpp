#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node* next;
};

Node* reverse(Node* head)
{
    if (!head)
        return NULL;
    Node* curr = head;
    Node* next = NULL;
    Node* prev = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

    //  if (next != NULL)
    //     head->next = reverse(next);


    //  return prev;   
// }

void push(Node** head_ref, int new_data)
{
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
void printList(Node* node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
}
int main()
{
    Node* head = NULL;
    push(&head, 9);
    push(&head, 8);
    push(&head, 7);
    push(&head, 6);
    push(&head, 5);
    push(&head, 3);
    push(&head, 2);
    push(&head, 4);
    cout << "Given Linklist \n";
    printList(head);
    head = reverse(head);
    cout << "\nReverse LL of Given LL \n"<<" ";
    printList(head);
    head = reverse(head);
}