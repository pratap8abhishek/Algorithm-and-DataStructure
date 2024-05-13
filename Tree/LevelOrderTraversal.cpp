#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
};
void printCurrentLevel(Node* root, int level);
int height(Node* node);

void printLevelOrder(Node* root)
{
    int h = height(root);

    for (int i = 1; i <= h; i++)
        printCurrentLevel(root, i);
}

void printCurrentLevel(Node* root, int level)
{
    if(root == NULL)
    return;
     if (level == 1)
        cout << root->data << " ";
     else if (level > 1) {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }   

}
int height(Node* root){
    if(root == NULL ){
         return 0;
    }else{
        return 1 + max(height(root->left),height(root->right));
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
    cout << "Level Order traversal of binary tree is \n";
    printLevelOrder(node);
    return 0;
}