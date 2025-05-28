#include <iostream>
#include <queue>

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

        int ans = 0;
        // Queue stores pair of node and its index as long long
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});  //node,index

        while (!q.empty()) {
            int size = q.size();
            long long mini = q.front().second;  // minimum index at this level
            long long first = 0, last = 0;

            for (int i = 0; i < size; i++) {
                long long curr = q.front().second - mini;
                TreeNode* node = q.front().first;
                q.pop();

                if (i == 0) first = curr;
                if (i == size - 1) last = curr;

                if (node->left) q.push({node->left, 2 * curr + 1});
                if (node->right) q.push({node->right, 2 * curr + 2});
            }

            ans = max(ans, (int)(last - first + 1));
        }

        return ans;
    }
};

int main() {
    // Create a binary tree example
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    Solution sol;
    int maxWidth = sol.widthOfBinaryTree(root);

    cout << "Maximum width of the binary tree is: " << maxWidth << endl;


    return 0;
}
