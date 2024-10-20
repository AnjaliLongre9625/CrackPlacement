#include <iostream>
#include <limits.h>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return helper(root, (long long)INT_MIN - 1, (long long)INT_MAX + 1);
    }
    
    bool helper(TreeNode* root, long long minVal, long long maxVal) {
        if (root == NULL) return true;
        if (root->val <= minVal || root->val >= maxVal) return false;
        return helper(root->left, minVal, root->val) && helper(root->right, root->val, maxVal);
    }
};

int main() {
    // Example test case
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    Solution sol;
    cout << "Is the tree a valid BST? " << (sol.isValidBST(root) ? "Yes" : "No") << endl; // Expected: Yes

    // Test with another case: [5, 1, 4, null, null, 3, 6]
    TreeNode* root2 = new TreeNode(5);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(4);
    root2->right->left = new TreeNode(3);
    root2->right->right = new TreeNode(6);

    cout << "Is the second tree a valid BST? " << (sol.isValidBST(root2) ? "Yes" : "No") << endl; // Expected: No

    // Cleanup
    delete root->left;
    delete root->right;
    delete root;

    delete root2->left;
    delete root2->right->left;
    delete root2->right->right;
    delete root2->right;
    delete root2;

    return 0;
}
