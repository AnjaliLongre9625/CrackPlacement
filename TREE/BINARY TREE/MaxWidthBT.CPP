#include <iostream>
#include <queue>
#include <algorithm>
#include <utility>
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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        long long ans = 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        while (!q.empty()) {
            int size = q.size();
            long long mmin = q.front().second;
            long long first, last;
            
            for (int i = 0; i < size; i++) {
                long long curr_id = q.front().second - mmin;
                TreeNode* node = q.front().first;
                q.pop();
                
                if (i == 0) first = curr_id;
                if (i == size - 1) last = curr_id;
                
                if (node->left) q.push({node->left, curr_id * 2 + 1});
                if (node->right) q.push({node->right, curr_id * 2 + 2});
            }
            
            ans = max(ans, last - first + 1);
        }
        
        return ans;
    }
};

// Helper function to create a sample binary tree
TreeNode* createSampleTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(9);
    return root;
}

int main() {
    Solution solution;
    TreeNode* root = createSampleTree();

    int width = solution.widthOfBinaryTree(root);
    cout << "Maximum width of the binary tree is: " << width << endl;

    // Clean up the allocated memory for the tree nodes
    delete root->left->left;
    delete root->left->right;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
