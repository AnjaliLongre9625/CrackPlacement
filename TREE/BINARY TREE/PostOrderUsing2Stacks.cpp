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
        
        stack<TreeNode*> st1, st2;
        st1.push(root);

        while (!st1.empty()) {
            root = st1.top();
            st1.pop();
            st2.push(root);

            if (root->left != NULL) {
                st1.push(root->left);
            }
            if (root->right != NULL) {
                st1.push(root->right);
            }
        }

        while (!st2.empty()) {
            postorder.push_back(st2.top()->val);
            st2.pop();
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

// Helper function to create the binary tree structure for testing
TreeNode* createSampleTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(6);
    root->left->right->right = new TreeNode(7);
    root->right->right->left = new TreeNode(9);
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
    // Ideally, you'd implement a destructor or a function to delete nodes
    return 0;
}
