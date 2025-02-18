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
Node* intersectPoint(Node *head1,Node *head2)
{
    Node *ptr1 = head1;
    Node* ptr2 = head2;
    
    if(ptr1 ==nullptr ||ptr2 == nullptr)
    return nullptr;
    
    while(ptr1 != ptr2){
        ptr1 = ptr1 ? ptr1->next : head2;
        ptr2 = ptr2 ? ptr2->next : head1;
    }
    return ptr1;
}
int main()
{
    // First linked list: 5 -> 10 -> 15
    Node *head1 = new Node(50);
    head1->next = new Node(15);
    head1->next->next = new Node(30);

    // Second linked list: 2 -> 3 -> 20
    Node *head2 = new Node(2);
    head2->next = new Node(3);
    head2->next->next = new Node(20);
    
    head2->next->next->next = head1->next;
    
    Node *intersectionPoint = intersectPoint(head1, head2);

    if (intersectionPoint == nullptr)
        cout << "-1";
    else
        cout << intersectionPoint->data << endl;
}