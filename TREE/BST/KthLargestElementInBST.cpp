#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int result = -1;
    int cnt = 0;

    void inorder(TreeNode* root, int target) {
        if (!root || result != -1) return;

        inorder(root->left, target);

        cnt++;
        if (cnt == target) {
            result = root->val;
            return;
        }
        inorder(root->right, target);
    }

    int countNodes(TreeNode* root) {
        if (!root) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    int kthLargest(TreeNode* root, int k) {
        int n = countNodes(root);
        int target = n - k + 1;  // kth largest = (n - k + 1)th smallest
        cnt = 0;
        result = -1;
        inorder(root, target);
        return result;
    }
};