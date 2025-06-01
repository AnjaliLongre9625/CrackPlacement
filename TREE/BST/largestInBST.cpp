#include <iostream>
#include <vector>
using namespace std;

// Node structure for a Binary Search Tree
struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Function to perform inorder traversal of the BST and store elements in an array
void inorder(Node* node, vector<int>& arr) {
    if (!node) {
        return;
    }
    
    
    inorder(node->left, arr);// Recursive call to the left subtree
    
    arr.push_back(node->data);// Store the current node's data
    
    inorder(node->right, arr);// Recursive call to the right subtree
}

int kthLargest(Node* root, int K) {
    vector<int> arr;
    
    inorder(root, arr);
    
    int kLargest = arr[arr.size() - K];
    return kLargest;
}

Node* insert(Node* root, int key) {
    if (!root) {
        return new Node(key);
    }
    
    if (key < root->data) {
        root->left = insert(root->left, key);
    } else if (key > root->data) {
        root->right = insert(root->right, key);
    }
    
    return root;
}

// Driver program to test the functions
int main() {
    Node* root = nullptr;
    
    // Inserting nodes into the BST
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    
    int K = 3;  // Find the 3rd largest element
    
    // Finding and printing the Kth largest element in the BST
    cout << "The " << K << "rd largest element is: " << kthLargest(root, K) << endl;
    
    return 0;
}
