#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* first = NULL;
    TreeNode* second = NULL;
    TreeNode* prev = NULL;

    // In-order traversal to detect the two swapped nodes
    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        if (prev && prev->val > root->val) {
            if (!first) {
                first = prev;  // First violation
            }
            second = root;  // Second violation
        }
        prev = root;
        inorder(root->right);
    }

    // Function to recover the BST
    void recoverTree(TreeNode* root) {
        inorder(root);
        if (first && second) swap(first->val, second->val);
    }
};

// Helper function to insert a new node in the tree
TreeNode* insert(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

// Helper function to print the in-order traversal of the tree
void inorderPrint(TreeNode* root) {
    if (!root) return;
    inorderPrint(root->left);
    cout << root->val << " ";
    inorderPrint(root->right);
}

// Main function to test the recoverTree function
int main() {
    // Construct the tree: [3, 1, 4, null, null, 2]
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(2);

    cout << "Before recovery: ";
    inorderPrint(root);
    cout << endl;

    // Recover the tree
    Solution sol;
    sol.recoverTree(root);

    cout << "After recovery: ";
    inorderPrint(root);
    cout << endl;

    return 0;
}
