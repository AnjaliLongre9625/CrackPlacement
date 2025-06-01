#include <iostream>
#include <stack>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
private:
    stack<TreeNode*>myStack;
public:
    // Constructor initializes the iterator by pushing all left children of root onto the stack
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    // Returns the next smallest number in the BST
    int next() {
        // Get the top element from the stack
        TreeNode* temp = myStack.top();
        myStack.pop();

        // If there is a right subtree, push all its left children
        pushAll(temp->right);
        return temp->val;
    }

    // Returns true if there is a next smallest element
    bool hasNext() {
        return !myStack.empty();
    }

private:
    // Helper function to push all left children of a node onto the stack
    void pushAll(TreeNode* node) {
        while (node != NULL) {
            myStack.push(node);
            node = node->left;
        }
    }
};

void inorder(TreeNode* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    // Creating a sample BST
    TreeNode* root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);

    // Initialize the BST iterator
    BSTIterator iterator(root);

    // Iterate over the BST
    cout << "BST Inorder Traversal: ";
    while (iterator.hasNext()) {
        cout << iterator.next() << " ";
    }
    cout << endl;

    return 0;
}
