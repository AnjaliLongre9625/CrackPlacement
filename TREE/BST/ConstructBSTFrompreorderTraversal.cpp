#include <iostream>
#include <vector>
#include <climits>  // For INT_MAX and INT_MIN
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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;  // Index to track the current element in preorder
        return helper(preorder, i, INT_MAX);  // Pass INT_MAX as the initial bound
    }

    TreeNode* helper(vector<int>& preorder, int &i, int bound) {
        // Base case: return NULL if index exceeds array size or current value exceeds bound
        if (i == preorder.size() || preorder[i] > bound) {
            return NULL;
        }

        // Create a new root node with the current value
        TreeNode* root = new TreeNode(preorder[i++]);

        // Recursively construct the left and right subtrees
        root->left = helper(preorder, i, root->val);  // Left subtree has values < root->val
        root->right = helper(preorder, i, bound);     // Right subtree has values < bound

        return root;
    }
};

// Utility function to print the tree (inorder traversal for testing purposes)
void inorder(TreeNode* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    // Test the implementation with a sample preorder traversal
    vector<int> preorder = {8, 5, 1, 7, 10, 12};
    
    // Create an instance of the Solution class
    Solution solution;
    
    // Construct the BST from the preorder traversal
    TreeNode* root = solution.bstFromPreorder(preorder);

    // Print the inorder traversal of the constructed BST
    cout << "Inorder traversal of constructed BST: ";
    inorder(root);
    cout << endl;

    return 0;
}
