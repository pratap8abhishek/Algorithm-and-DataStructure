#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
};
Node* newNode(int data){
    Node* temp = new Node();
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
int height(Node* node)
{
    if (node == NULL)
        return 0;

    return 1 + max(height(node->left), height(node->right));
}
bool isBalance(Node* root)
{
    int lh;
    int rh;
    if (root == NULL)
        return 1;
    lh = height(root->left);
    rh = height(root->right);

    if (abs(lh - rh) <= 1 && isBalance(root->left) && isBalance(root->right))
        return 1;

    return 0;
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