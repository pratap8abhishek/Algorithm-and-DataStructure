#include<bits./stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = nullptr;
    }
};

void deleteList(Nod* curr){
    
    while(curr != nullptr){

        Node* temp = curr->next;

        delete curr;

        curr = temp;
    }
}
int main() {

    // Create a hard-coded linked list:
    // 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    deleteList(head);
    head = nullptr; 
 
    cout << "NULL";

    return 0;
}