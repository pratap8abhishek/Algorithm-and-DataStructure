#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node* next;
};
void removeDuplicates(Node *start)
{
    Node *ptr1, *ptr2, *dup;
    ptr1 = start;

    while (ptr1 != NULL && ptr1->next != NULL)
    {
        ptr2 = ptr1;
        while (ptr2->next != NULL)
        {
            if (ptr1->data == ptr2->next->data)
            {
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                delete (dup);
            }
            else
                ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
}
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