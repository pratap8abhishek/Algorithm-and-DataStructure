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
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

int checkLevelLeafNode(Node *root)
{
    if (!root)
        return 1;

    queue<Node *> q;
    q.push(root);

    int flag = 0;

    while (!q.empty())
    {
        int n = q.size();

        for (int i = 0; i <= n; i++)
        {
            Node* temp = q.front();
            q.pop();

            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }

            if (temp->left == NULL && temp->right == NULL)
                flag = 1;
        }
        if (flag && !q.empty())
            return 0;
    }
    return 1;
}

int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->right = newNode(4);
    root->right->left = newNode(5);
    root->right->right = newNode(6);

    int result = checkLevelLeafNode(root);
    if (result)
        cout << "All leaf nodes are at same level\n";
    else
        cout << "Leaf nodes not at same level\n";
    return 0;
}