#include <iostream>
#include <climits>
using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
public:
    bool solve(Node *root, int min, int max) {
        if (!root)
            return false;
        
        // If the current node is a leaf node and min equals max, it's a dead end.
        if (min == max)
            return true;

        return solve(root->left, min, root->data - 1) || solve(root->right, root->data + 1, max);
    }

    bool isDeadEnd(Node *root) {
        return solve(root, 1, INT_MAX);
    }
};

Node* insert(Node* root, int key) {
    if (root == nullptr)
        return new Node(key);
    
    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);

    return root;
}

int main() {
    Solution solution;
    
    Node* root = nullptr;
    root = insert(root, 8);
    root = insert(root, 5);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 11);
    root = insert(root, 4);

    if (solution.isDeadEnd(root))
        cout << "The BST contains a dead end.\n";
    else
        cout << "The BST does not contain any dead end.\n";

    return 0;
}
