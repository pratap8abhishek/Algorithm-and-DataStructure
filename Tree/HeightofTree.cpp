#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
};
int height(Node* node){
    if(node==NULL){
        return 0;
    }else{
        return 1+max(height(node->left),height(node->right));
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
    Node* node = newNode(1);
    node->left = newNode(2);
    node->right = newNode(3);
    node->left->left = newNode(4);
    node->left->right = newNode(5);
    cout << "Height of tree is " << height(node);
    return 0;
}