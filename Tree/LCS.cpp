#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
};
Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
Node* findLCA(Node* node,int n1,int n2){
    if(node == NULL)
    return NULL;
    if(node->data == n1 || node->data ==n2){
        return node;
    }
    Node* left_lca = findLCA(node->left,n1,n2);
    Node* right_lca = findLCA(node->right,n1,n2);

    if (left_lca && right_lca)
        return node;
 
    
    return (left_lca != NULL) ? left_lca : right_lca;
}

int main()
{
    Node *node = newNode(1);
    node->left = newNode(2);
    node->right = newNode(3);
    node->left->left = newNode(4);
    node->left->right = newNode(5);
    cout << "LCA(4, 5) = " << findLCA(node, 4, 5)->data;
}