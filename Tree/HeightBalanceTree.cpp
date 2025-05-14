#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
};
int height(Node* node){
    if(node == NULL)
    return 0;
    
    return 1 + max(height(node->left),height(node->right));
}

bool isBalance(Node* root){
    if (root == NULL)
        return true;

    int lh = height(root->left);
    int rh = height(root->right);

    if (abs(lh - rh) <= 1 && isBalance(root->left) && isBalance(root->right))
        return true;

    return false;
}
Node* newNode(int data){
    Node* temp = new Node();
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);

    if (isBalance(root))
    {
        cout << "Given tree is Balance Tree"<<" ";
    }
    else
    {
        cout << "Given Tree is Not a Balance Tree"<<" ";
    }

    return 0;
}