#include <iostream>
using namespace std;

struct Node {
    int keys[2];       // can hold up to 2 keys
    Node* children[3]; // can have up to 3 children
    int numKeys;       // number of keys currently in node

    Node() {
        numKeys = 0;
        for (int i = 0; i < 3; i++) children[i] = nullptr;
    }
};

// Utility: search in a 2–3 tree
bool search(Node* root, int key) {
    if (!root) return false;
    if (key == root->keys[0] || (root->numKeys == 2 && key == root->keys[1]))
        return true;
    if (key < root->keys[0]) return search(root->children[0], key);
    else if (root->numKeys == 1 || key < root->keys[1]) return search(root->children[1], key);
    else return search(root->children[2], key);
}

// Simplified insertion (full implementation requires splitting logic)
Node* insert(Node* root, int key) {
    if (!root) {
        root = new Node();
        root->keys[0] = key;
        root->numKeys = 1;
        return root;
    }
    // For brevity, only handle leaf insert without split
    if (root->numKeys == 1) {
        if (key < root->keys[0]) {
            root->keys[1] = root->keys[0];
            root->keys[0] = key;
        } else {
            root->keys[1] = key;
        }
        root->numKeys = 2;
    } else {
        cout << "Split required (not implemented in this demo)." << endl;
    }
    return root;
}

int main() {
    Node* root = nullptr;
    root = insert(root, 10);
    root = insert(root, 20);

    cout << "Search 10: " << (search(root, 10) ? "Found" : "Not Found") << endl;
    cout << "Search 15: " << (search(root, 15) ? "Found" : "Not Found") << endl;

    return 0;
}
