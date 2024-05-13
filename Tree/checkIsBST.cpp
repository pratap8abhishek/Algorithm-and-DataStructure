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
int maxValue(Node *node)
{
    if (node == NULL) {
        return INT16_MIN;
    }
    int value = node->data;
    int leftmax = maxValue(node->left);
    int rightmax = maxValue(node->right);

    return max(value, max(leftmax, rightmax));
}
int minValue(Node *node)
{
   if (node == NULL) {
        return INT16_MAX;
    }
    int value = node->data;
    int leftMax = minValue(node->left);
    int rightMax = minValue(node->right);

    return min(value, min(leftMax, rightMax));
}

int isBST(Node *node)
{
    if (node == NULL)
        return 1;

    if (node->left != NULL && maxValue(node->left) > node->data)
        return 0;

    if (node->right != NULL && minValue(node->right) > node->data)
        return 0;

    if (!isBST(node->left) || !isBST(node->right))
        return 0;

    return 1;
}
int main()
{
    Node *root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(5);
    // root->right->left = newNode(7);
    root->left->left = newNode(1);
    root->left->right = newNode(3);

    // Function call
    if (isBST(root))
        cout<<"Is BST";
    else
        cout<<"Not a BST";

    return 0;
}