#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;

    Node(int val) {
        key = val;
        left = right = nullptr;
    }
};

// Inorder traversal to display BST
void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

// Function to insert a new node
Node* insert(Node* root, int key) {
    if (root == nullptr) return new Node(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);

    return root;
}

// Find minimum value node in a subtree
Node* findMin(Node* root) {
    while (root->left != nullptr)
        root = root->left;
    return root;
}

// Function to delete a node
Node* deleteNode(Node* root, int key) {
    if (root == nullptr) return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        // Case 1: No child
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }
        // Case 2: One child
        else if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // Case 3: Two children
        else {
            Node* temp = findMin(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }
    return root;
}

int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    cout << "Inorder traversal before deletion: ";
    inorder(root);
    cout << endl;

    root = deleteNode(root, 50);

    cout << "Inorder traversal after deleting 50: ";
    inorder(root);
    cout << endl;

    return 0;
}
