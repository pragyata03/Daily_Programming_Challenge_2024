#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
    
    Node(int data) {
        value = data;
        left = right = nullptr;
    }
};

bool are_Mirrors(Node* left_Subtree, Node* right_Subtree) {
    //Both empty then they are mirrors
    if (!left_Subtree && !right_Subtree)
        return true;

    // If one is empty and the other isn't, they aren't mirrors
    if (!left_Subtree || !right_Subtree)
        return false;

    // Both nodes must have the same value and their children must be mirrors
    return (left_Subtree->value == right_Subtree->value) &&
           are_Mirrors(left_Subtree->left, right_Subtree->right) &&
           are_Mirrors(left_Subtree->right, right_Subtree->left);
}

bool is_Symmetric(Node* root) {
    if (!root)
        return true;
    
    // Compare left and right subtrees
    return are_Mirrors(root->left, root->right);
}

//Main Function
int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(4);
    root->right->right = new Node(3);

    if (is_Symmetric(root)) {
        cout << "The tree is symmetric" << endl;
        cout<<"True!"<<endl;
    } else {
        cout << "The tree is not symmetric" << endl;
        cout<<"False!"<<endl;
    }
    return 0;
}
