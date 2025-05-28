#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int result = 0, cnt = 0;

    void inorder(TreeNode* root, int k) {
        if (!root) return;

        inorder(root->left, k);
        
        cnt++;
        if (cnt == k) {
            result = root->val;
            return;
        }

        inorder(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return result;
    }
};

// Helper function to insert nodes in a BST
TreeNode* insert(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

// Test function
int main() {
    // Example 1: BST = [3,1,4,null,2], k = 1
    TreeNode* root1 = new TreeNode(3);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(4);
    root1->left->right = new TreeNode(2);

    Solution sol;
    cout << "Example 1:\n";
    cout << "K-th smallest (k=1): " << sol.kthSmallest(root1, 1) << endl; // Output: 1

    // Example 2: BST = [5,3,6,2,4,null,null,1], k = 3
    TreeNode* root2 = new TreeNode(5);
    root2->left = new TreeNode(3);
    root2->right = new TreeNode(6);
    root2->left->left = new TreeNode(2);
    root2->left->right = new TreeNode(4);
    root2->left->left->left = new TreeNode(1);

    Solution sol2;
    cout << "Example 2:\n";
    cout << "K-th smallest (k=3): " << sol2.kthSmallest(root2, 3) << endl; // Output: 3

    return 0;
}