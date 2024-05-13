#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    int hd;
    Node *left;
    Node *right;
};


Node* newNode(int data){
    Node *temp = new Node();
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void bottomView(Node *root)
{
    if(root == NULL)
    return;

    int hd = 0;
    queue<Node *> q;

    map<int, int> m;

    root->hd = hd;
    q.push(root);

    while(!q.empty()){
        Node *temp = q.front();
        q.pop();

        hd = temp->hd;

        m[hd] = temp->data;

        if(temp->left!= NULL){
            temp->left->hd = hd-1;
            q.push(temp->left);
        }

        if(temp->right!= NULL){
            temp->right->hd = hd+1;
            q.push(temp->right);
        }
    }
    for(auto i = m.begin();i!=m.end();i++)
    cout << i->second << " ";


}
int main(){
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->right = newNode(4);
    root->left->right->right = newNode(5);
    root->left->right->right->right = newNode(6);
    cout << "Bottom view of the given binary tree :\n";
    bottomView(root);
    return 0;
}