#include <bits/stdc++.h>
using namespace std;
struct TreeNode{
 int val;
 TreeNode *left,*right;
 TreeNode(int x):val(x),left(NULL),right(NULL){}
};
class Solution{
public:
    int sum;
    void dfs(TreeNode *node)
    {
        if (node->left != nullptr)
        {
            if (node->left->left == nullptr && node->left->right == nullptr)
                sum += node->left->val;
            dfs(node->left);
        }
        if (node->right != nullptr)
        {
            dfs(node->right);
        }
    }
    int sumOfLeftLeaves(TreeNode *root)
    {
        sum = 0;
        dfs(root);
        return sum;
    }
};

int main(){
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution sol;
    cout << "The sum of left leaves is: " << sol.sumOfLeftLeaves(root) << endl;
    
    return 0;
}