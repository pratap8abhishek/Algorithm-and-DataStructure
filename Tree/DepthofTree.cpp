#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
};
int maxDepth(Node* node){
    if(node ==NULL){
        return 0;
    }else{
        int ldepth = maxDepth(node->left);
        int rdepth = maxDepth(node->right);
        if(ldepth>rdepth){
            return (ldepth+1);
        }else{
            return (rdepth+1);
    }

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
   cout << "Depth of tree is " << maxDepth(node);
    return 0;
}