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

void printNodes(Node* head){

    Node* curr = head;

    while(curr != nullptr){
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}
int main(){
    Node* head = new Node(1);
    head->next = new Node(4);
    head->next->next = new Node(5);
    printNodes(head);
    return 0;
}