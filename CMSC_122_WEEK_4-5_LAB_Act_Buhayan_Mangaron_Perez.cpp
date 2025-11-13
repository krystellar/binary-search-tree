// PEREZ, Krystel Mikylla
// MANGARON, Michael James
// BUHAYAN, Joseph Francis

// WEEK 4-5 LAB ACTIVITY

#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;

class Node {
    public:
        // variables need for the binary search bst
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
    Node* root; // points to the first or the root node of the bst
    bool deleted = false; 
    // insert function
    Node* insertNode(Node* root, int data){
        if (root == nullptr){
            return new Node(data); // creates new node if an empty root spot if found
        }
        // recur down the bst if no empty root spot is found
        if (data < root->data){
            root->left = insertNode(root->left, data); // if value is less than the parent, go left
        } else if (data > root->data){
            root->right = insertNode(root->right, data); // if value is greater than the parent, go right
        }
        return root;
    }

    // delete function
    Node* deleteNode(Node* root, int data, bool &deleted){
        if(root == nullptr){
            return root;
        }
        
        if(data < root->data){
            root->left = deleteNode(root->left, data, deleted);
        } else if (data > root->data){
            root->right = deleteNode(root->right, data, deleted);
        } else {
            deleted = true;
            // case 1: no child
            if (root->left == nullptr && root->right == nullptr) {
                delete root;
                return nullptr;
            }
            // case 2: one child
            if (root->left ==nullptr){
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr){
                Node* temp = root->left;
                delete root;
                return temp;
            }
            // case 3: two children
            Node* temp = findMinimum(root->right);
            root->data = temp-> data;
            root->right = deleteNode(root->right, temp->data, deleted);
        }
        return root;
    }

    Node* findMinimum(Node* root){
        if (root == nullptr){
            return nullptr;
        }
        while (root->left != nullptr){
            root=root->left;
        }
        return root;
    }

    // Helper function to get tree height
    int getHeight(Node* node) {
        if (node == nullptr) return 0;
        return 1 + max(getHeight(node->left), getHeight(node->right));
    }

    // Compact top-down display
    void displayTree(Node* root) {
        if (root == nullptr) {
            cout << "Tree is empty!" << endl;
            return;
        }

        queue<Node*> q;
        q.push(root);
        int level = 0;
        int height = getHeight(root);

        while (!q.empty()) {
            int levelSize = q.size();
            int indent = pow(2, height - level) - 2;
            
            // Print indentation
            for (int i = 0; i < indent; i++) {
                cout << " ";
            }

            // Print nodes
            for (int i = 0; i < levelSize; i++) {
                Node* current = q.front();
                q.pop();

                if (current != nullptr) {
                    cout << (current->data < 10 ? " " : "") << current->data;
                    q.push(current->left);
                    q.push(current->right);
                } else {
                    cout << " *";
                    q.push(nullptr);
                    q.push(nullptr);
                }

                // Space between nodes
                if (i < levelSize - 1) {
                    for (int j = 0; j < indent * 2 + 2; j++) {
                        cout << " ";
                    }
                }
            }
            cout << endl;
            level++;
            
            // Stop if we've reached maximum levels
            if (level > height) break;
        }
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
        if (node == nullptr) return;
        
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
        binarySearchTree () { root = nullptr; }  // Constructor - initialize empty bst

        // Public methods
        void insert(int data){
            root = insertNode(root, data); // insert new value into bst
        }
        void remove(int data){
            bool deleted = false;
            root = deleteNode(root, data, deleted); // delete value in bst
            if (!deleted) cout << "DNE" << endl; 
        }
        
        void showTree() {
            cout << "\nBinary Search Tree Structure:\n";
            cout << "=============================\n";
            displayTree(root);
            cout << "=============================\n";
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
    
    // Test with balanced tree
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);
    bst.insert(10);
    bst.insert(25);
    bst.insert(35);
    bst.insert(45);
    
    cout << "=== BINARY SEARCH TREE DEMONSTRATION ===\n" << endl;
    
    cout << "Tree Structure:" << endl;
    bst.showTree();
    
    cout << "\nTree Traversals:" << endl;
    bst.inOrderTraversal();   
    bst.preOrderTraversal();  
    bst.postOrderTraversal(); 
    bst.breadthFirstTraversal();

    // Interactive menu
    int choice, value;

    do {
        cout << "\n====== BINARY SEARCH TREE MENU ======\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Inorder Traversal\n";
        cout << "4. Preorder Traversal\n";
        cout << "5. Postorder Traversal\n";
        cout << "6. Breadth-First Traversal\n";
        cout << "7. Display Tree\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                bst.insert(value);
                break;

            case 2:
                cout << "Enter value to delete: ";
                cin >> value;
                bst.remove(value);
                break;

            case 3:
                bst.inOrderTraversal();
                break;

            case 4:
                bst.preOrderTraversal();
                break;

            case 5:
                bst.postOrderTraversal();
                break;

            case 6:
                bst.breadthFirstTraversal();
                break;

            case 7:
                bst.showTree();
                break;

            case 8:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 8);
    
    return 0;
}