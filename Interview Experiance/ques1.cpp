// -----------------------------------------------Recursive Approach--------------------------------------
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
};
int preorder(Node* node){
    if(node == NULL)
    return;
    cout<<node->data<<" ";
    preorder(node->left);
    preorder(node->right);
}
Node* newNode(int data){
    Node* temp = new Node();;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
int main(){
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->right->right = newNode(5);
    preorder(root);
    return 0;
}

// -------------------------------------------------Iterative Approach-------------------------------------

void preorder(Node* node){
    if(node == NULL){
    return;
    }
   stack<Node*> st;
   st.push(node);
   
   while(!st.empty()){
       Node* node = st.top();
       st.pop();
       cout<<node->data<<" ";
       
       if(node->right)
       st.push(node->right);
       if(node->left)
       st.push(node->left);
   }
}
Node* newNode(int data){
    Node* temp = new Node();;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
int main(){
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->right->right = newNode(5);
    preorder(root);
    return 0;
}