#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Define the TreeNode structure
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Function to perform preorder traversal
    // of a binary tree iteratively
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        
        // If the root is null, return an empty result
        if (root == nullptr) {
            return preorder;
        }
        
        stack<TreeNode*> st;
        st.push(root);
        
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            
            // Visit the root node
            preorder.push_back(node->val);
            
            // Push right and left children to stack
            // (right child pushed first so that left child is processed first)
            if (node->right) {
                st.push(node->right);
            }
            if (node->left) {
                st.push(node->left);
            }
        }
        
        return preorder;
    }
};

int main() {
    // Creating a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // Initializing Solution class
    Solution sol;

    // Getting the preorder traversal result
    vector<int> result = sol.preorderTraversal(root);

    // Displaying the preorder traversal
    cout << "Preorder Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
