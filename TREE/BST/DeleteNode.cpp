#include <iostream>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) return root; // If tree is empty, return NULL

        // Search for the node to delete
        if (root->val > key) {
            root->left = deleteNode(root->left, key); // Search in the left subtree
        } 
        else if (root->val < key) {
            root->right = deleteNode(root->right, key); // Search in the right subtree
        } 
        else { // Node found
            // Case 1: Node has no left child
            if (!root->left) return root->right;
            // Case 2: Node has no right child
            if (!root->right) return root->left;
            
            // Case 3: Node has both left and right children
            TreeNode* lastrightValue = findLastRight(root->left); // Find largest node in left subtree
            lastrightValue->right = root->right; // Attach right subtree to it
            return root->left; // Replace node with left subtree
        }
        return root;
    }

    // Function to find the rightmost node in a subtree
    TreeNode* findLastRight(TreeNode* root) { 
        while (root->right) root = root->right; // Stop at last right node
        return root; 
    }
};

// Helper function to print inorder traversal of BST
void inorder(TreeNode* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

// Main function to test deleteNode function
int main() {
    Solution sol;
    
    // Constructing BST
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);

    cout << "Original Tree (Inorder): ";
    inorder(root);
    cout << endl;

    int key = 5;
    root = sol.deleteNode(root, key);

    cout << "Tree after deleting " << key << " (Inorder): ";
    inorder(root);
    cout << endl;

    return 0;
}
