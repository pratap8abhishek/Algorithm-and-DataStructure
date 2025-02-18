#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;
    Node(int x){
        data = x;
        next = nullptr;
    }
};
void deleteNode(Node* node)
{
    if(node == nullptr || node->next == nullptr){
        cout << "Node cannot be deleted" << endl;
        return;
    }
    
    // Copy the data of the next node into the current node
    Node* nextNode = node->next;
    node->data = nextNode->data;
    
    // Update the next pointer to skip the next node
    node->next = nextNode->next;
    
    // Delete the next node
    delete nextNode;
}


void print(Node* head)
{
    Node* temp = head;
    
    while(temp){
        cout<< temp->data<<" -> ";
        temp = temp->next;
    }
    cout<<"NULL"<< endl;
}
int main()
{
    Node* head = new Node(20);
    head->next = new Node(4);
    head->next->next = new Node(15);
    head->next->next->next = new Node(35);
    
    print(head);
    
    Node* del = head->next->next;
    
    deleteNode(del);
    
    cout<<"Final Linked List after deletion of 15:\n";
    
    print(head);
    return 0;
}