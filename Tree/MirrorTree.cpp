#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
};
void inOrder(Node* node){
    if(node == NULL){
        return;
    }
    inOrder(node->left);
    cout<<node->data<<" ";
    inOrder(node->right); 
}
void MirrorTree(Node* node){
    if(node == NULL){
        return;
    }else{
        Node* temp ;
        MirrorTree(node->left);
        MirrorTree(node->right);


        temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
}
Node* newNode(int data){
    Node* temp = new Node();
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

int main(){
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    cout<<"Inorder of Original Tree "<<endl;
    inOrder(root);
    MirrorTree(root);
    cout<<"Inorder of Original Tree converted to mirror "<<endl;
    inOrder(root);
    return 0;
}