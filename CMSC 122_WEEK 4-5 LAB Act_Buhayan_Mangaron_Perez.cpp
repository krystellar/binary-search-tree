// PEREZ, Krystel Mikylla
// MANGARON, Michael James
// BUHAYAN, Joseph Francis

// WEEK 4-5 LAB ACTIVITY

#include <iostream>
using namespace std;

class Node {
    public:
        // variables need for the binary search tree
        int data;
        Node* left; // the left child
        Node* right; // the right child

        // constructor to initialize
        Node (int value){
            data = value;
            left = right = nullptr;
            // nullptr means it's pointing nowhere yet
        }
};

class binarySearchTree {
private:
    Node* root; // points to the first or the root node of the tree

    Node* insertNode(Node* root, int data){
        if (root == nullptr){
            return new Node(data);
        }
        if (data < root->data){
            root->left = insertNode(root->left, data);
        } else if (data > root->data){
            root->right = insertNode(root->right, data);
        }
        return root;
    }

    void inOrder(Node* node) {
        if (node != nullptr) {
            inOrder(node->left);
            cout << node->data << " ";
            inOrder(node->right);
        }
    }

    void preOrder(Node* node) {
        if (node != nullptr) {
            cout << node->data << " ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }

public:
    binarySearchTree () { root = nullptr; }

    // Public methods
    void insert(int data){
        root = insertNode(root, data);
    }

    void inOrderTraversal() {
        cout << "In-order: ";
        inOrder(root);
        cout << endl;
    }

    void preOrderTraversal() {
        cout << "Pre-order: ";
        preOrder(root);
        cout << endl;
    }
};