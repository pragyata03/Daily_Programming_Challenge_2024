#include <iostream>
using namespace std;

// Binary tree node structure
struct Tree_Node {
    int val;
    Tree_Node* left;
    Tree_Node* right;
    Tree_Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to find the LCA of two given nodes in the binary tree
Tree_Node* lowest_Common_Ancestor(Tree_Node* root, Tree_Node* p, Tree_Node* q) {
    //Null Root
    if (root == nullptr || root == p || root == q)
        return root;

    // Recursion for left and right subtrees
    Tree_Node* left = lowest_Common_Ancestor(root->left, p, q);
    Tree_Node* right = lowest_Common_Ancestor(root->right, p, q);
    
    // If both left and right are non-null, root is the LCA
    if (left != nullptr && right != nullptr)
        return root;
    // Otherwise, return the non-null node
    return left != nullptr ? left : right;
}

//Creation of binary tree:
Tree_Node* create_Binary_Tree() {
    Tree_Node* root = new Tree_Node(3);
    root->left = new Tree_Node(5);
    root->right = new Tree_Node(1);
    root->left->left = new Tree_Node(6);
    root->left->right = new Tree_Node(2);
    root->right->left = new Tree_Node(0);
    root->right->right = new Tree_Node(8);
    root->left->right->left = new Tree_Node(7);
    root->left->right->right = new Tree_Node(4);
    return root;
}

//Main Function
int main() {
    // Creating the binary tree
    Tree_Node* root = create_Binary_Tree();
    
    // Nodes for which we need to find the LCA
    Tree_Node* p = root->left;  // Node 5
    Tree_Node* q = root->right; // Node 1
    
    Tree_Node* lca = lowest_Common_Ancestor(root, p, q);
    if (lca)
        cout << "LCA of " << p->val << " and " << q->val << " is: " << lca->val << endl;
    else
        cout << "LCA not found." << endl;
    return 0;
}
