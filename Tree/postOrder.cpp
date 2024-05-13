#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
};

// Utility function to create New Node
Node* newNode(int data){
 Node* temp = new Node();
 temp->data = data;
 temp->left = NULL;
 temp->right = NULL;
 return temp;
}
void printPostorder(Node* node){
    if(node == NULL){
        return;
    }
    printPostorder(node->left);
    printPostorder(node->right);
    cout<<node->data<<" ";
}

int main(){
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    cout<<"Post Order Traversal of Given Tree is :"<<" ";
    printPostorder(root);
    return 0;
}