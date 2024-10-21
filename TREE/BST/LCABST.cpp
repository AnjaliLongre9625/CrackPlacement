#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // Function to find the lowest common ancestor in a BST
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return NULL;

        if (root->val < p->val && root->val < q->val) {
            return lowestCommonAncestor(root->right, p, q);
        }
        if (root->val > p->val && root->val > q->val) {
            return lowestCommonAncestor(root->left, p, q);
        }
        return root;
    }
};

void insert(TreeNode*& root, int val) {
    if (root == NULL) {
        root = new TreeNode(val);
        return;
    }
    if (val < root->val) {
        insert(root->left, val);
    } else {
        insert(root->right, val);
    }
}

int main() {
    // Sample binary search tree
    TreeNode* root = NULL;
    insert(root, 6);
    insert(root, 2);
    insert(root, 8);
    insert(root, 0);
    insert(root, 4);
    insert(root, 7);
    insert(root, 9);
    insert(root, 3);
    insert(root, 5);

    TreeNode* p = root->left;  // Node with value 2
    TreeNode* q = root->left->right;  // Node with value 4

    Solution solution;
    TreeNode* lca = solution.lowestCommonAncestor(root, p, q);

    if (lca != NULL) {
        cout << "Lowest Common Ancestor of " << p->val << " and " << q->val << " is: " << lca->val << endl;
    } else {
        cout << "Lowest Common Ancestor not found." << endl;
    }

    return 0;
}
