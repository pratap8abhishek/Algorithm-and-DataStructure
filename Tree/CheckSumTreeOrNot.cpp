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
    Node *temp = new Node();
    temp->data = data;
    temp -> left = NULL;
    temp->right = NULL;
    return temp;
}
int sum(Node *node)
{
    if (node == NULL)
        return 0;

    return sum(node->left) + node->data + sum(node->right);
}
bool isSumTree(Node *node)
{
    int ls, rs;

    if (node == NULL && node->left == NULL && node->right == NULL)
        return 1;

    ls = sum(node->left);
    rs = sum(node->right);

    if ((node->data == ls + rs) && isSumTree(node->left) && isSumTree(node->right))
        return 1;

    return 0;
}

int main()
{
    Node *root = newNode(26);
    root->left = newNode(10);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(6);
    root->right->right = newNode(3);

    if (isSumTree(root))
        cout << "The given tree is a SumTree ";
    else
        cout << "The given tree is not a SumTree ";
    return 0;
}