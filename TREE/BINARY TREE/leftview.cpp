#include <iostream>
#include <vector>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
   vector<int> leftsideView(Node* root) {
        vector<int> res;
        dfsleft(root, 0, res);
        return res;
    }
    void dfsleft(Node* node, int level, vector<int>& res) {
        if (!node) return;
        if (res.size()== level) res.push_back(node->data);
        dfsleft(node->left, level + 1, res);        // Traverse left subtree first
        dfsleft(node->right, level + 1, res);        // Then right subtree
    }
};

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->right->right = new Node(7);

    // Create Solution object and get right view
    Solution sol;
    vector<int> rightView = sol.leftsideView(root);

    // Print right view
    cout << "left View: ";
    for (int val : rightView) cout << val << " ";
    cout << endl;
    return 0;
}