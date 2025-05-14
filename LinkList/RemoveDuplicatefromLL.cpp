#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};
void removeDuplicates(Node* head){
    Node* curr = head;
    Node* next_next;
    if(curr == NULL)
    return;
    
    while(curr->next != NULL){
        if(curr->data == curr->next->data){
            Node* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        }else{
            curr = curr->next;
        }
    }
} 
void printList(Node* node){
    while(node != NULL){
        cout<<" "<<node->data;
        node = node->next;
    }
}
int main()
{
  Node* head = new Node(1);
  head->next = new Node(2);
  head->next->next = new Node(3);
  head->next->next->next = new Node(4);
  head->next->next->next->next = new Node(4);
  cout << "Linked list before duplicate removal " << endl;
  printList(head);

  removeDuplicates(head);

  cout << "\nLinked list after duplicate removal " << endl;
  printList(head);
  return 0;
}