#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // Inorder traversal of the tree
    void inorder(TreeNode* root, vector<int> &v) {
        if (!root) return;
        inorder(root->left, v);
        v.push_back(root->val); // Store node's value
        inorder(root->right, v);
    }

    // Function to find if there exists two numbers in BST that sum up to k
    bool findTarget(TreeNode* root, int k) {
        vector<int> v;
        inorder(root, v); // Perform inorder traversal to get sorted elements

        // Two-pointer approach to check for the target sum
        int l = 0, r = v.size() - 1;
        while (l < r) {
            if (v[l] + v[r] == k) {
                return true; // Found a pair
            } else if (v[l] + v[r] < k) {
                l++; // Increase the left pointer
            } else {
                r--; // Decrease the right pointer
            }
        }
        return false; // No pair found
    }
};

// Helper function to insert a new node in a BST
TreeNode* insertBST(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val) root->left = insertBST(root->left, val);
    else root->right = insertBST(root->right, val);
    return root;
}

int main() {
    Solution solution;

    // Create the binary search tree
    TreeNode* root = nullptr;
    root = insertBST(root, 5);
    root = insertBST(root, 3);
    root = insertBST(root, 6);
    root = insertBST(root, 2);
    root = insertBST(root, 4);
    root = insertBST(root, 7);

    // Example usage of findTarget
    int target = 9; // We are looking for two numbers that sum up to 9
    if (solution.findTarget(root, target)) {
        cout << "Found two numbers in the tree that sum up to " << target << endl;
    } else {
        cout << "No such pair found." << endl;
    }

    return 0;
}
