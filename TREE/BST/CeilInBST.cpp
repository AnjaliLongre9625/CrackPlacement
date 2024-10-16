#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

int findCeil(Node* root, int input) {
    if (root == nullptr) return -1; 

    int ceil = -1;

    while (root) {
        if (root->data == input) {
            ceil = root->data; // Exact match
            return ceil;
        } else if (root->data < input) {
            root = root->right; // Go right to find a larger value
        } else {
            ceil = root->data; // Potential ceil found
            root = root->left; // Go left to find a smaller candidate
        }
    }
    return ceil; 
}

void inOrder(Node* root) {
    if (root != nullptr) {
        inOrder(root->left);
        std::cout << root->data << " ";
        inOrder(root->right);
    }
}

int main() {
    Node* root = nullptr;

    root = insert(root, 8);
    insert(root, 4);
    insert(root, 12);
    insert(root, 2);
    insert(root, 6);
    insert(root, 10);
    insert(root, 14);

    // Displaying the BST in-order
    std::cout << "In-order traversal of the BST: ";
    inOrder(root);
    std::cout << std::endl;

    // Test the findCeil function
    int input = 5;
    int ceilValue = findCeil(root, input);
    if (ceilValue != -1) {
        std::cout << "Ceil value for " << input << " is " << ceilValue << std::endl;
    } else {
        std::cout << "No ceil value found for " << input << std::endl;
    }

    // Test for another input
    input = 13;
    ceilValue = findCeil(root, input);
    if (ceilValue != -1) {
        std::cout << "Ceil value for " << input << " is " << ceilValue << std::endl;
    } else {
        std::cout << "No ceil value found for " << input << std::endl;
    }

    return 0;
}
