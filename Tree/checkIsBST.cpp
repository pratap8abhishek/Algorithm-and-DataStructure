#include <bits/stdc++.h>
using namespace std;
#include <climits>  // Include this for INT_MIN

class Node {
public:
    int data;
    Node* left;
    Node* right;
};

int maxValue(Node* node) {
    if (node == NULL) {
        return INT_MIN;
    }
    int value = node->data;
    int leftmax = maxValue(node->left);
    int rightmax = maxValue(node->right);

    return max(value, max(leftmax, rightmax));
}

int minValue(Node* node) {
    if (node == NULL) {
        return INT_MIN;
    }
    int value = node->data;
    int leftmin = minValue(node->left);
    int rightmin = minValue(node->right);

    return min(value, min(leftmin, rightmin));
}

bool isBST(Node* node) {
    if (node == NULL)
        return true;

    if (node->left != NULL && maxValue(node->left) > node->data)
        return false;

    if (node->right != NULL && minValue(node->right) <= node->data)  // Fix logic error here
        return false;

    if (!isBST(node->left) || !isBST(node->right))
        return false;

    return true;
}

Node* newNode(int data) {
    Node* temp = new Node();
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

int main() {
    Node* root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(5);
    root->left->left = newNode(1);
    root->left->right = newNode(3);

    if (isBST(root))
        cout << "Is BST";
    else
        cout << "Not a BST";

    return 0;
}




// // Optimized BST checker using value range
bool isBSTUtil(Node* node, int minVal, int maxVal) {
    if (node == NULL)
        return true;

    if (node->data <= minVal || node->data >= maxVal)
        return false;

    return isBSTUtil(node->left, minVal, node->data) &&
           isBSTUtil(node->right, node->data, maxVal);
}

// Wrapper function
bool isBST(Node* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}
