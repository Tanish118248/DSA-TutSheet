#include <iostream>
#include <climits>
using namespace std;
class Node {
    public:
    int data;
    Node *left, *right;
    
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
bool isBST(Node* root, long long minVal, long long maxVal) {
    if (root == NULL)
        return true;
    if (root->data <= minVal || root->data >= maxVal)
        return false;
    return isBST(root->left, minVal, root->data) &&
           isBST(root->right, root->data, maxVal);
}
int main() {
    Node* root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(10);
    root->left->left = new Node(1);
    root->left->right = new Node(6);
    root->right->right = new Node(14);

    if (isBST(root, LLONG_MIN, LLONG_MAX)) cout << "The tree is a BST\n";
    else cout << "The tree is NOT a BST\n";

    return 0;
}
