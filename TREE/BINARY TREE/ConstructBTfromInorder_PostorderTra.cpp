#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// TreeNode definition
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Create a map to store the index of each value in inorder for quick lookup
        unordered_map<int, int> inorder_map;
        for (int i = 0; i < inorder.size(); i++) {
            inorder_map[inorder[i]] = i;
        }
        // Call the recursive function to build the tree
        return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inorder_map);
    }

private:
    TreeNode* buildTree(vector<int>& preorder, int preStart, int preEnd, 
                        vector<int>& inorder, int inStart, int inEnd, 
                        unordered_map<int, int>& inorder_map) {
        // Base case: if there are no elements to construct the tree
        if (preStart > preEnd || inStart > inEnd) return nullptr;

        // The root is the first element in preorder traversal
        TreeNode* root = new TreeNode(preorder[preStart]);

        // Find the root in inorder to divide left and right subtrees
        int inRoot = inorder_map[root->val];
        int numsLeft = inRoot - inStart; // Number of nodes in the left subtree

        // Recursively construct the left and right subtrees
        root->left = buildTree(preorder, preStart + 1, preStart + numsLeft,
                               inorder, inStart, inRoot - 1, inorder_map);
        root->right = buildTree(preorder, preStart + numsLeft + 1, preEnd,
                                inorder, inRoot + 1, inEnd, inorder_map);

        return root;
    }
};

// Helper function to print the tree in level order for verification
void printTreeLevelOrder(TreeNode* root) {
    if (!root) return;
    vector<TreeNode*> queue = {root};
    while (!queue.empty()) {
        TreeNode* node = queue.front();
        queue.erase(queue.begin());
        if (node) {
            cout << node->val << " ";
            queue.push_back(node->left);
            queue.push_back(node->right);
        } else {
            cout << "null ";
        }
    }
    cout << endl;
}

// Test the solution with main
int main() {
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    Solution sol;
    TreeNode* root = sol.buildTree(preorder, inorder);

    cout << "Level Order of Constructed Tree: ";
    printTreeLevelOrder(root);

    return 0;
}
