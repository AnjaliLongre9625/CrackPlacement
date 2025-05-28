#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == NULL) return NULL;

        if(root->val == val) {
            return root;
        }
        else if(root->val < val) {
            return searchBST(root->right, val);
        }
        else {
            return searchBST(root->left, val);
        }
    }
};

// Helper function to insert nodes into the BST
TreeNode* insert(TreeNode* root, int val) {
    if(root == NULL) return new TreeNode(val);

    if(val < root->val) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

// Helper function for inorder traversal
void inorder(TreeNode* root) {
    if(root == NULL) return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    TreeNode* root = NULL;

    // Create BST by inserting nodes
    root = insert(root, 8);
    insert(root, 3);
    insert(root, 10);
    insert(root, 1);
    insert(root, 6);
    insert(root, 14);
    insert(root, 4);
    insert(root, 7);
    insert(root, 13);

    cout << "Inorder Traversal of BST: ";
    inorder(root);
    cout << endl;

    int key = 6;
    Solution sol;
    TreeNode* result = sol.searchBST(root, key);

    if(result != NULL)
        cout << "Node with value " << key << " found." << endl;
    else
        cout << "Node with value " << key << " not found." << endl;

    return 0;
}