#include <iostream>
#include <vector>
#include <climits>
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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return helper(preorder, i, INT_MAX);
    }

    TreeNode* helper(vector<int>& preorder, int &i, int bound) {
        if (i == preorder.size() || preorder[i] > bound) return NULL;

        TreeNode* root = new TreeNode(preorder[i++]);
        root->left = helper(preorder, i, root->val);
        root->right = helper(preorder, i, bound);
        return root;
    }
};

// Utility function for postorder traversal to verify BST structure
void postorder(TreeNode* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}

// Main function
int main() {
    vector<int> preorder = {40, 30, 35, 80, 100};
    Solution sol;
    TreeNode* root = sol.bstFromPreorder(preorder);

    cout << "BST IS : ";
    postorder(root);  // Should print: 35 30 100 80 40
    cout << endl;

    return 0;
}
// 📊 Time and Space Complexity
// Metric	Value
// ⏱ Time	O(N)
// 🧠 Auxiliary Space (Recursion)	O(N) (in worst case, like skewed tree)

// 🧠 Steps to Explain in Interview
// You can say:
// 1.	I use preorder traversal to construct the BST recursively. The idea is to simulate how nodes would be added to a BST if inserted one-by-one in preorder order.
// 2.	I maintain an index i that tracks the current root candidate in preorder.
// 3.	I also pass a bound parameter that limits the values that can be placed in the current subtree.
// 4.	In each call:
// o	If preorder[i] > bound, it means this node doesn't belong here (it's a right child of some ancestor), so I return NULL.
// o	Otherwise, I create a node, increment i, then recursively build the left subtree with a tighter bound (root->val) and the right subtree with the original bound.
// 5.	This is a top-down recursive construction using BST property and preorder order, all in O(N) time with a single pass.


//brute
// #include <iostream>
// #include <vector>
// using namespace std;

// // Tree node definition
// struct TreeNode {
//     int val;
//     TreeNode *left, *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

// // Function to insert a node into BST
// TreeNode* insert(TreeNode* root, int key) {
//     if (root == NULL) return new TreeNode(key);

//     if (key < root->val)
//         root->left = insert(root->left, key);
//     else
//         root->right = insert(root->right, key);

//     return root;
// }

// // Main function to build BST from preorder using brute force
// TreeNode* bstFromPreorder(vector<int>& preorder) {
//     if (preorder.empty()) return NULL;

//     TreeNode* root = new TreeNode(preorder[0]);
//     for (int i = 1; i < preorder.size(); ++i) {
//         insert(root, preorder[i]);
//     }

//     return root;
// }

// // Postorder traversal to verify correctness
// void postorder(TreeNode* root) {
//     if (!root) return;
//     postorder(root->left);
//     postorder(root->right);
//     cout << root->val << " ";
// }

// // Main driver code
// int main() {
//     vector<int> preorder = {40, 30, 35, 80, 100};
//     TreeNode* root = bstFromPreorder(preorder);

//     cout << "Postorder Traversal: ";
//     postorder(root);  // Output: 35 30 100 80 40
//     cout << endl;

//     return 0;
// }
// 📊 Time and Space Complexity
// Metric	Value
// ⏱ Time Complexity	O(N^2) (worst case: skewed BST)
// 🧠 Auxiliary Space	O(H) (call stack for insert, H = height)

// 🧠 How to Explain in an Interview
// 1.	I use a brute-force approach where I insert each node from the preorder array into the BST one-by-one.
// 2.	The first element becomes the root. Then I iterate from index 1 to N-1 and insert every value using the standard BST insert logic.
// 3.	BST insert function checks whether the key is smaller or larger than the current node and places it accordingly in left or right subtree.
// 4.	Since this doesn't use any optimization or bounds, the worst-case time complexity becomes O(N^2) when the BST is skewed (like inserting sorted input).
// 5.	This solution is simple and intuitive but not efficient for large inputs or skewed trees. That's why I prefer the optimized O(N) bound-based approach for real-world usage.
