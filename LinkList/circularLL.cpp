#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node* next;
};
void push(Node **head_ref, int new_data)
{
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
bool isCircular(Node *head)
{
    if (head == NULL)
    {
        return false;
    }
    Node *slow = head;
    Node *fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        if (slow == fast)
        {
            return true;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return false;
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
    if (isCircular)
    {
        cout << "Circular"
             << " ";
    }
    else
    {
        cout << "not circular"
             << " ";
    }
}