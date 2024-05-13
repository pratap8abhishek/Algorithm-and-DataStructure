#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    int hd;
    Node *left;
    Node *right;
};
void topview(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> q;
    map<int, int> m;
    int hd = 0;
    root->hd = hd;
    q.push(root);

    cout << "The top view of the tree is : \n";

    while (q.size())
    {
        hd = root->hd;
        if (m.count(hd) == 0)
            m[hd] = root->data;
        if (root->left)
        {
            root->left->hd = hd - 1;
            q.push(root->left);
        }
        if (root->right)
        {
            root->right->hd = hd + 1;
            q.push(root->right);
        }
        q.pop();
        root = q.front();
    }
    for (auto i = m.begin(); i != m.end(); i++)
    {
        cout << i->second << " ";
    }
}
// Utility function of a Node
Node *newNode(int data)
{
    Node *temp = new Node();
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
    root->left->right = newNode(4);
    root->left->right->right = newNode(5);
    root->left->right->right->right = newNode(6);
    topview(root);
    return 0;
}