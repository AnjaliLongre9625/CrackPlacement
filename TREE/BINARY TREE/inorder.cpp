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
    void helper(TreeNode* node, vector<int>& path) {
        if (node == NULL) return;
        helper(node->left, path);
        path.push_back(node->val);
        helper(node->right, path);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> path;
        helper(root, path);
        return path;
    }
};

int main() {
    // Construct the binary tree: [1, null, 2, 3]
    //        1
    //         \
    //          2
    //         /
    //        3
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution sol;
    vector<int> result = sol.inorderTraversal(root);

    // Print the result
    cout << "Inorder Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    // Free memory
    delete root->right->left;
    delete root->right;
    delete root;

    return 0;
}