#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // Inorder traversal to store values in sorted order
    void inorder(TreeNode* root, vector<int>& ans) {
        if (root == NULL) return;
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }

    // Two-pointer approach to find if two elements sum to k
    bool findTarget(TreeNode* root, int k) {
        vector<int> ans;
        inorder(root, ans);
        int left = 0, right = ans.size() - 1;

        while (left < right) {
            int sum = ans[left] + ans[right];
            if (sum == k) return true;
            else if (sum > k) right--;
            else left++;
        }
        return false;
    }
};

// Helper function to build a test BST
TreeNode* createTestTree() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);
    return root;
}

int main() {
    Solution obj;
    TreeNode* root = createTestTree();

    int k1 = 9;
    int k2 = 28;

    cout << "Test Case 1 (k = 9): " << (obj.findTarget(root, k1) ? "true" : "false") << endl;
    cout << "Test Case 2 (k = 28): " << (obj.findTarget(root, k2) ? "true" : "false") << endl;

    return 0;
}