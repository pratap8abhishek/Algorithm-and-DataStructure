#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
};
Node* newNode(int data)
{
    Node *temp = new Node();
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

int toSumTree(Node* node){
    if(node ==NULL)
    return 0;

    int old_val = node->data;

    node->data = toSumTree(node->left)+toSumTree(node->right);

    return node->data+old_val;
}
void printInorder(Node* node){
    if(node==NULL){
        return;
    }
    printInorder(node->left);
    cout<<node->data<<" ";
    printInorder(node->right);

}
int main()
{
    Node *root = newNode(10);
    root->left = newNode(-2);
    root->right = newNode(6);
    root->left->left = newNode(8);
    root->left->right = newNode(-4);
    root->right->left = newNode(7);
    root->right->right = newNode(5);

    toSumTree(root);

    cout << "Inorder Traversal of the resultant tree is: \n";
    printInorder(root);
    return 0;
}