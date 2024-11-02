#include <iostream>
using namespace std;

// TreeNode structure
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        
        int lh=findleftheight(root);
        int rh=findrightheight(root);

        if(lh==rh) return (1<<lh)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
    int findleftheight(TreeNode* node){
        int height=0;
        while(node){
            height++;
            node=node->left;
        }
        return height;
    }
    int findrightheight(TreeNode* node){
        int height=0;
        while(node){
            height++;
            node=node->right;
        }
        return height;
    }
};

int main() {
    // Create a simple binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    
    Solution sol;
    cout << "Total number of nodes: " << sol.countNodes(root) << endl;

    return 0;
}
