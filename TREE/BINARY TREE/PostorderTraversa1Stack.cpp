#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        if (root == NULL) return postorder;

        stack<TreeNode*> st;
        TreeNode* lastVisited = nullptr;

        while (!st.empty() || root != nullptr) {
            if (root != nullptr) {
                st.push(root);
                root = root->left;
            } else {
                TreeNode* node = st.top();
                if (node->right != nullptr && lastVisited != node->right) {
                    root = node->right;
                } else {
                    postorder.push_back(node->val);
                    lastVisited = node;
                    st.pop();
                }
            }
        }

        return postorder;
    }
};

// Function to print the elements of a vector
void printVector(const vector<int>& vec) {
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

// Helper function to create a sample binary tree for testing
TreeNode* createSampleTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    return root;
}

// Main function
int main() {
    // Create a sample binary tree
    TreeNode* root = createSampleTree();

    // Create an object of Solution class
    Solution sol;

    // Get the postorder traversal result
    vector<int> result = sol.postorderTraversal(root);

    // Print the postorder traversal result
    cout << "Postorder traversal: ";
    printVector(result);

    // Free allocated memory (if necessary)
    return 0;
}
