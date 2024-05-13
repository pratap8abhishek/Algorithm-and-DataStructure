#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};
void push(Node **head_ref, int new_data)
{
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int MiddleEle(Node* head)
{
    Node *slow_p = head;
    Node *fast_p = head;

    if (head != NULL)
    {
        while (fast_p != NULL && fast_p->next != NULL)
        {
            fast_p = fast_p->next->next;
            slow_p = slow_p->next;
        }
        cout << "The middle element is [" << slow_p->data << "]" << endl;
    }
}

int main()
{
    Node* head = NULL;
    push(&head, 10);
    push(&head, 11);
    push(&head, 12);
    push(&head, 13);
    push(&head, 14);
    push(&head, 15);

    cout << MiddleEle(head);
    return 0;
}