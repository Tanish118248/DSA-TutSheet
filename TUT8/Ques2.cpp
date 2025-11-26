#include <iostream>
using namespace std;
class Node {
    public:
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int key) {
    if (root == NULL)
        return createNode(key);
    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);
    return root;
}

bool searchRecursive(Node* root, int key) {
    if (!root) return false;
    if (root->data == key) return true;
    return key < root->data ? searchRecursive(root->left, key) : searchRecursive(root->right, key);
}

bool searchIterative(Node* root, int key) {
    while (root) {
        if (root->data == key) return true;
        root = (key < root->data) ? root->left : root->right;
    }
    return false;
}

Node* findMin(Node* root) {
    while (root && root->left)
        root = root->left;
    return root;
}

Node* findMax(Node* root) {
    while (root && root->right)
        root = root->right;
    return root;
}

Node* inorderSuccessor(Node* root, Node* node) {
    if (node->right)
        return findMin(node->right);

    Node* successor = NULL;
    while (root) {
        if (node->data < root->data) {
            successor = root;
            root = root->left;
        } else if (node->data > root->data)
            root = root->right;
        else break;
    }
    return successor;
}

Node* inorderPredecessor(Node* root, Node* node) {
    if (node->left)
        return findMax(node->left);

    Node* predecessor = NULL;
    while (root) {
        if (node->data > root->data) {
            predecessor = root;
            root = root->right;
        } else if (node->data < root->data)
            root = root->left;
        else break;
    }
    return predecessor;
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;

    cout << "Search (Recursive): " << (searchRecursive(root, 60) ? "Found" : "Not Found") << endl;
    cout << "Search (Iterative): " << (searchIterative(root, 90) ? "Found" : "Not Found") << endl;

    cout << "Minimum: " << findMin(root)->data << endl;
    cout << "Maximum: " << findMax(root)->data << endl;

    Node* node = root->left->right; 
    cout << "Inorder Successor of " << node->data << ": " << inorderSuccessor(root, node)->data << endl;
    cout << "Inorder Predecessor of " << node->data << ": " << inorderPredecessor(root, node)->data << endl;
}
