#include <iostream>
#include <climits>
using namespace std;

// Node structure for the binary tree
class Node {
public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize node data and children
    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

//BST using in-order traversal
bool validate_BST(Node* root, int& previous) {
    if (root == nullptr)
        return true;

    // Check the left subtree
    if (!validate_BST(root->left, previous))
        return false;

    //current node's data is greater than the previous node's
    if (root->data <= previous)
        return false;
    previous = root->data;
    // Check the right subtree
    return validate_BST(root->right, previous);
}

// Function to check if the binary tree is a BST
bool is_BST(Node* root) {
    int previous = INT_MIN;
    return validate_BST(root, previous);
}

int main() {
    Node* root = new Node(2);
    root->left = new Node(1);
    root->right = new Node(3);

    if (is_BST(root)) {
        cout << "True";
    } else {
        cout << "False";
    }
    return 0;
}
