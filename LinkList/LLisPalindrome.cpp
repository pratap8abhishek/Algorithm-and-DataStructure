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
bool isPalindrome(Node* head)
{
    Node* curr = head;
    
    stack<int> s;
    
    while(curr != nullptr){
        s.push(curr->data);
        curr = curr->next;
    }
    while(head != nullptr)
    {
        int c = s.top();
        s.pop();
        
        if(head->data != c){
            return false
        }
        head = head->next;
    }
    return true;
}
int main()
{
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(1);
    
    bool result = isPalindrome(head);

    if (result)
        cout << "true\n";
    else
        cout << "false\n";

    return 0;
  
}