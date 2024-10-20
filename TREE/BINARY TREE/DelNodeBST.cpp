#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) return NULL;
        if (root->val == key) return helper(root);
        TreeNode* dummy = root;
        while (root != NULL) {
            if (root->val > key) {
                if (root->left != NULL && root->left->val == key) {
                    root->left = helper(root->left);
                    break;
                } else {
                    root = root->left;
                }
            } else {
                if (root->right != NULL && root->right->val == key) {
                    root->right = helper(root->right);
                    break;
                } else {
                    root = root->right;
                }
            }
        }
        return dummy;
    }

    TreeNode* helper(TreeNode* root) {
        if (root->left == NULL) {
            return root->right;
        }
        if (root->right == NULL) {
            return root->left;
        }
        TreeNode* rightChild = root->right;
        TreeNode* lastRight = findlast(root->left);
        lastRight->right = rightChild;
        return root->left;
    }

    TreeNode* findlast(TreeNode* root) {
        if (root->right == NULL) {
            return root;
        }
        return findlast(root->right);
    }
};

// Helper function to print the BST in inorder traversal
void inorder(TreeNode* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    // Create a sample BST
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);

    cout << "Original BST (inorder traversal): ";
    inorder(root);
    cout << endl;

    Solution sol;
    int key = 3;
    
    // Delete the node with the specified key
    root = sol.deleteNode(root, key);

    cout << "BST after deleting node with key " << key << " (inorder traversal): ";
    inorder(root);
    cout << endl;

    return 0;
}
