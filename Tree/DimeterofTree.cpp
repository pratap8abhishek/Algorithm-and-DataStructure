#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
};
int max(int a, int b) {
     return (a > b) ? a : b;
      }

int height(Node* node);

int diameter(Node* root){
    if(root == NULL)
        return 0;

        // get the height of left and right sub-trees
       int lheight = height(root->left);
       int rheight = height(root->right);

        // get the diameter of left and right sub-trees
        int ldiameter = diameter(root->left);
        int rdiameter = diameter(root->right);

        return max(lheight + rheight + 1,max(ldiameter, rdiameter));
    
}
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
    cout << "Diameter of the given binary tree is "<< diameter(node);
 
    return 0;
}