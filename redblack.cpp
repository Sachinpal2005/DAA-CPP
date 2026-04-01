#include <iostream>
using namespace std;

enum Color { RED, BLACK };

struct Node {
    int data;
    Color color;
    Node *left, *right, *parent;

    Node(int val) {
        data = val;
        color = RED; // new nodes are always red initially
        left = right = parent = nullptr;
    }
};

class RedBlackTree {
    Node* root;

    void rotateLeft(Node* &pt) {
        Node* pt_right = pt->right;
        pt->right = pt_right->left;
        if (pt_right->left != nullptr)
            pt_right->left->parent = pt;
        pt_right->parent = pt->parent;
        if (pt->parent == nullptr)
            root = pt_right;
        else if (pt == pt->parent->left)
            pt->parent->left = pt_right;
        else
            pt->parent->right = pt_right;
        pt_right->left = pt;
        pt->parent = pt_right;
    }

    void rotateRight(Node* &pt) {
        Node* pt_left = pt->left;
        pt->left = pt_left->right;
        if (pt_left->right != nullptr)
            pt_left->right->parent = pt;
        pt_left->parent = pt->parent;
        if (pt->parent == nullptr)
            root = pt_left;
        else if (pt == pt->parent->left)
            pt->parent->left = pt_left;
        else
            pt->parent->right = pt_left;
        pt_left->right = pt;
        pt->parent = pt_left;
    }

    void fixViolation(Node* &pt) {
        while (pt != root && pt->parent->color == RED) {
            Node* parent = pt->parent;
            Node* grandparent = parent->parent;

            if (parent == grandparent->left) {
                Node* uncle = grandparent->right;
                if (uncle != nullptr && uncle->color == RED) {
                    grandparent->color = RED;
                    parent->color = BLACK;
                    uncle->color = BLACK;
                    pt = grandparent;
                } else {
                    if (pt == parent->right) {
                        rotateLeft(parent);
                        pt = parent;
                        parent = pt->parent;
                    }
                    rotateRight(grandparent);
                    swap(parent->color, grandparent->color);
                    pt = parent;
                }
            } else {
                Node* uncle = grandparent->left;
                if (uncle != nullptr && uncle->color == RED) {
                    grandparent->color = RED;
                    parent->color = BLACK;
                    uncle->color = BLACK;
                    pt = grandparent;
                } else {
                    if (pt == parent->left) {
                        rotateRight(parent);
                        pt = parent;
                        parent = pt->parent;
                    }
                    rotateLeft(grandparent);
                    swap(parent->color, grandparent->color