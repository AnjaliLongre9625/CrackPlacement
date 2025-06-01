#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == NULL) return new TreeNode(val);
        TreeNode* curr = root;
        while (true) {
            if (curr->val <= val) {
                if (curr->right != NULL) {
                    curr = curr->right;
                } else {
                    curr->right = new TreeNode(val);
                    break;  // Add break here to stop loop after insertion
                }
            } else {
                if (curr->left != NULL) {
                    curr = curr->left;
                } else {
                    curr->left = new TreeNode(val);
                    break;
                }
            }
        }
        return root;
    }
};

void inorder(TreeNode* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    Solution sol;
    TreeNode* root = new TreeNode(5);
    sol.insertIntoBST(root, 3);
    sol.insertIntoBST(root, 7);
    sol.insertIntoBST(root, 2);
    sol.insertIntoBST(root, 4);
    sol.insertIntoBST(root, 6);
    sol.insertIntoBST(root, 8);

    // Print inorder traversal of the tree
    inorder(root);
    cout << endl;
    return 0;
}
