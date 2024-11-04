#include <iostream>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* prev = NULL; // Initialize a previous node pointer

    void flatten(TreeNode* root) {
        if (root == NULL) return; // Base case: if the node is null, return

        // Flatten the right subtree first
        flatten(root->right);
        // Flatten the left subtree
        flatten(root->left);

        // Process the current node
        root->right = prev; // The right child of the current node points to the previous node
        root->left = NULL;  // Set the left child to null

        // Update prev to the current node
        prev = root; 
    }
};

// Helper function to print the flattened tree
void printFlattenedTree(TreeNode* root) {
    TreeNode* curr = root;
    while (curr) {
        std::cout << curr->val << " ";
        curr = curr->right; // Move to the next right node
    }
    std::cout << std::endl;
}

// Example usage
int main() {
    // Creating a sample tree: [1,2,5,3,4,null,6]
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);

    Solution solution;
    solution.flatten(root); // Flatten the tree

    // Print the flattened tree
    printFlattenedTree(root); // Expected output: 1 2 3 4 5 6 

    // Clean up memory (not shown)
    return 0;
}
