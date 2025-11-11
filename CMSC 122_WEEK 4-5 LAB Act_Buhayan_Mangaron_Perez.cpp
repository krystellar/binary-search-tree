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
    Node* root; // points to the first or the root node of the tree
    binarySearchTree () { root = nullptr; } // points to nowhere for the first state of the bst (empty)

    // insert function
    void insert(int data){
        root = insertNode(root, data);
    }
    Node* insertNode(Node* root, int data){
        if (root == nullptr){
            return new Node(data); // creates new node if an empty spot if found
        }
        // recur down the tree if no empty spot found for the root
        if (data < root->data){ // if value is less than the parent, go to left
            root->left = insertNode(root->left, data);
        } else if (data > root->data){ // if value is more than the parent, go to right
            root->right = insertNode(root->right, data);
        }
        return root;
    }
};
