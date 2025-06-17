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
int count(Node* head , int k){
  if(head == NULL)
  return 0;
  
   int count = 0;
   Node* curr = head;
   while(curr != nullptr){
       if(curr->data == k){
           count++;
       }
       curr = curr->next;
   }
   return count;
}
int main()
{
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(1);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(1);
	
  	int key = 1;

    cout << count(head, key);
    return 0;
}
