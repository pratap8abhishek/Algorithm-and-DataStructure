#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node* left;
        Node* right;
};

void printpreOrder(Node* node){
    if(node == NULL){
        return;
    }
    cout<<node->data<<" ";
    printpreOrder(node->left);
    printpreOrder(node->right);
    
}
//Utility Function to make a new Node
Node* newNode(int data){
 Node* temp = new Node();
 temp->data = data;
 temp->left = NULL;
 temp->left = NULL;
 return temp;
}
int main(){

    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    std::cout << "Inorder traversal of the binary tree is:\n";
    printpreOrder(root);

}