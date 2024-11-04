#include <iostream>
#include <map>
#include <vector>

using namespace std;

// TreeNode structure
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Main function to build the binary tree from preorder and inorder traversals
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Create a map to store indices of elements in the inorder traversal
        map<int, int> mpp;
        for (int i = 0; i < inorder.size(); i++) {
            mpp[inorder[i]] = i;
        }
        // Call the helper function to build the tree recursively
        return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, mpp);
    }

private:
    // Recursive helper function to build the tree
    TreeNode* buildTree(vector<int>& preorder, int preStart, int preEnd, 
                        vector<int>& inorder, int inStart, int inEnd, map<int, int>& mpp) {
        // Base case: if indices are out of bounds, return NULL
        if (preStart > preEnd || inStart > inEnd) return NULL;
        
        // Create a new node with the current root value from preorder
        TreeNode* root = new TreeNode(preorder[preStart]);

        // Find the root index in the inorder traversal
        int inRoot = mpp[root->val];
        int numsLeft = inRoot - inStart;

        // Recursively build the left and right subtrees
        root->left = buildTree(preorder, preStart + 1, preStart + numsLeft, inorder, inStart, inRoot - 1, mpp);
        root->right = buildTree(preorder, preStart + numsLeft + 1, preEnd, inorder, inRoot + 1, inEnd, mpp);
        
        return root;
    }
};

// Helper function to print the inorder traversal of a tree
void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    Solution sol;
    TreeNode* root = sol.buildTree(preorder, inorder);

    cout << "Inorder traversal of the constructed tree: ";
    printInorder(root);
    cout << endl;

    return 0;
}
