#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int new_data){
        data = new_data;
        next = nullptr;
    } 
};

Node* deleteK(Node* head,int k){
    if(head == nullptr || k <= 0)
    return head;
    
    Node* curr = head ;
    Node* prev = nullptr;
    
    int count = 0;
    
    while(curr != nullptr){
        count++;
        
        if(count % k == 0){
            if(prev != nullptr){
                prev->next = curr->next;
            }else{
                head = curr->next;
            }
        }
        else{
            prev = curr;
        }
        curr = curr->next;
    }
    return head;
}

void printList(Node* head) {
  
    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
}
int main()
{
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    int k = 2;
    head = deleteK(head, k);
    printList(head);
    return 0;
}
