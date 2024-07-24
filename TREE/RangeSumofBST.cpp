#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    int rangeSumBST(TreeNode *root, int low, int high)
    {
        if (!root)
            return 0;
        if (root->val >= low && root->val <= high)
        {
            return root->val +
                   rangeSumBST(root->left, low, high) +
                   rangeSumBST(root->right, low, high);
        }
        else if (root->val < low)
        {
            return rangeSumBST(root->right, low, high);
        }
        else
        {
            return rangeSumBST(root->left, low, high);
        }
    }
};

int main()
{
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right->right = new TreeNode(18);

    Solution sol;
    int low = 7, high = 15;
    cout << "Range Sum of BST: " << sol.rangeSumBST(root, low, high) << endl;

    return 0;
}