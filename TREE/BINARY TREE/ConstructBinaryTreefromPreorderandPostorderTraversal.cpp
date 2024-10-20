#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Public method to initiate the tree construction
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        // Call the dfs function with initial indices
        return dfs(pre, 0, pre.size() - 1, post, 0, post.size() - 1);
    }
    
private:
    // Helper method to construct the binary tree recursively
    TreeNode* dfs(vector<int>& pre, int preStart, int preEnd, vector<int>& post, int postStart, int postEnd) {
        // Base case: if there are no elements to construct the tree
        if (preStart > preEnd) return nullptr;
        
        // Create the root node with the first element of preorder traversal
        TreeNode* root = new TreeNode(pre[preStart]);
        
        // If there is only one element, return the root node
        if (preStart == preEnd) return root;
        
        // Find the index of the next element in the preorder in the postorder array
        int postIndex = postStart;
        while (post[postIndex] != pre[preStart + 1]) postIndex++;
        
        // Calculate the length of the left subtree
        int len = postIndex - postStart + 1;
        
        // Recursively construct the left subtree
        root->left = dfs(pre, preStart + 1, preStart + len, post, postStart, postIndex);
        
        // Recursively construct the right subtree
        root->right = dfs(pre, preStart + len + 1, preEnd, post, postIndex + 1, postEnd - 1);
        
        // Return the constructed root node
        return root;
    }
};

// Helper function to print the binary tree in inorder traversal
void printInorder(TreeNode* root) {
    if (root == nullptr) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    // Example 1
    vector<int> preorder1 = {1, 2, 4, 5, 3, 6, 7};
    vector<int> postorder1 = {4, 5, 2, 6, 7, 3, 1};

    Solution solution;

    // Construct the binary tree
    TreeNode* root1 = solution.constructFromPrePost(preorder1, postorder1);

    // Print the tree in inorder to verify the result
    cout << "Inorder traversal of the constructed tree (Example 1): ";
    printInorder(root1); // Expected Output: 4 2 5 1 6 3 7
    cout << endl;

    // Example 2
    vector<int> preorder2 = {1};
    vector<int> postorder2 = {1};

    // Construct the binary tree
    TreeNode* root2 = solution.constructFromPrePost(preorder2, postorder2);

    // Print the tree in inorder to verify the result
    cout << "Inorder traversal of the constructed tree (Example 2): ";
    printInorder(root2); // Expected Output: 1
    cout << endl;

    return 0;
}
