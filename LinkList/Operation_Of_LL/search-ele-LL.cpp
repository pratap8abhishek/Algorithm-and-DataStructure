
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
bool searchEle(Node* head,int target){
    Node* curr = head;
    if(curr == nullptr)
    return false;

    while(curr != nullptr){
        if (curr->data == target)
            return true;

        // Move to the next node
        curr = curr->next;
    }
    return false;
    
}
int main()
{
 Node* head = new Node(1);
 head->next = new Node(2);
 head->next->next = new Node(3);
 head->next->next->next = new Node(4);
 
 int key = 3;

 searchEle(head,key);
 return 0;

}