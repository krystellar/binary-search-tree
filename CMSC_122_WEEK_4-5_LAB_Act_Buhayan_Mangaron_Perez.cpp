// PEREZ, Krystel Mikylla
// MANGARON, Michael James
// BUHAYAN, Joseph Francis

// WEEK 4-5 LAB ACTIVITY

#include <iostream>
#include <queue>
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
            inOrder(node->left);        // Traverse left subtree
            cout << node->data << " ";  // Process current node
            inOrder(node->right);       // Traverse right subtree
        }
    }

    void preOrder(Node* node) {
        if (node != nullptr) {
            cout << node->data << " ";  // Process current node first
            preOrder(node->left);       // Traverse left subtree
            preOrder(node->right);      // Traverse right subtree
        }
    }

    void postOrder(Node* node){
        if (node != nullptr) {
            postOrder(node->left);       // Traverse left subtree
            postOrder(node->right);      // Traverse right subtree
            cout << node->data << " ";  // Process current node last
        }
    }

    void breadthFirst(Node* node){
        queue<Node*> toVisit;           // FIFO queue to store nodes in visiting order
        toVisit.push(node);

        while (!toVisit.empty()) {
            Node* current = toVisit.front();
            toVisit.pop();
            cout << current->data << " ";

            if (current->left != nullptr) {
                toVisit.push(current->left);    // Enqueue left child for later visit
            }
            if (current->right != nullptr) {
                toVisit.push(current->right);   // Enqueue right child for later visit
            }
        }
    }

    public:
        binarySearchTree () { root = nullptr; }  // Constructor - initialize empty tree

        // Public methods
        void insert(int data){
            root = insertNode(root, data);  // Insert new value into BST
        }

        void inOrderTraversal() {
            cout << "In-order: ";
            inOrder(root);                  // Start in-order traversal from root
            cout << endl;
        }

        void preOrderTraversal() {
            cout << "Pre-order: ";
            preOrder(root);                 // Start pre-order traversal from root
            cout << endl;
        }

        void postOrderTraversal(){
            cout << "Post-order: ";
            postOrder(root);                 // Start post-order traversal from root
            cout << endl;
        }

        void breadthFirstTraversal(){
            cout << "Breadth-First: ";
            breadthFirst(root);                 // Start breadth-first traversal from root
            cout << endl;
        }
};

int main() {
    binarySearchTree bst;
    
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    
    bst.inOrderTraversal();   // Output: 20 30 40 50 70
    bst.preOrderTraversal();  // Output: 50 30 20 40 70
    bst.postOrderTraversal(); // Output: 20 40 30 70 50 
    bst.breadthFirstTraversal(); // Output: 50 30 70 20 40
    
    return 0;
}
