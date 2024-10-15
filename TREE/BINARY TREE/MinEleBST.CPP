#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct Node {
    int data;
    Node* left;
    Node* right;
    
    // Constructor to create a new node
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
  public:
    // Function to find the minimum value in the BST
    int minValue(Node* root) {
        if (root == nullptr) {
            return -1;  // Return -1 if the tree is empty
        }

        // Traverse to the leftmost node
        while (root->left != nullptr) {
            root = root->left;
        }

        return root->data;  // The leftmost node contains the minimum value
    }
};

// Function to create and test the BST
int main() {
    // Example 1: Constructing the first tree
    Node* root1 = new Node(5);
    root1->left = new Node(4);
    root1->right = new Node(6);
    root1->left->left = new Node(3);
    root1->left->left->left = new Node(1);

    // Create an instance of the Solution class
    Solution solution;

    // Call minValue() function for the first tree
    cout << "Minimum value in BST (Tree 1): " << solution.minValue(root1) << endl;  // Expected Output: 1

    return 0;
}
