#include <iostream>
using namespace std;

// Definition for a BST Node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

// Function to insert nodes into BST
Node* insert(Node* root, int key) {
    if (!root) return new Node(key);
    
    if (key < root->data)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    
    return root;
}

// Inorder traversal for visual confirmation of BST
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Floor-finding function inside a class (as per your code)
class Solution {
public:
    int floor(Node* root, int x) {
        int ans = -1;

        while (root) {
            if (root->data == x) {
                return root->data; // Exact match
            }
            if (root->data < x) {
                ans = root->data;     // Potential floor
                root = root->right;   // Try for better (greater but still ≤ x)
            } else {
                root = root->left;    // Go left to find smaller values
            }
        }

        return ans;
    }
};

int main() {
    Node* root = NULL;
    
    // Sample BST: [10, 5, 11, 4, 7, N, N, N, N, N, 8]
    root = insert(root, 10);
    insert(root, 5);
    insert(root, 11);
    insert(root, 4);
    insert(root, 7);
    insert(root, 8);

    cout << "Inorder Traversal of BST: ";
    inorder(root);
    cout << endl;

    int x = 6;
    Solution sol;
    int result = sol.floor(root, x);

    if (result == -1)
        cout << "No floor exists for " << x << " in the BST." << endl;
    else
        cout << "Floor of " << x << " is: " << result << endl;

    return 0;
}