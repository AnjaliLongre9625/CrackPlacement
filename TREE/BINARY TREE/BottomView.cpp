#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

// Definition of a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
   vector<int> bottomView(Node* root) {
        vector<int> ans;
        if (root == NULL) return ans;

        map<int,int> mp;                  // vertical distance -> node data
        queue<pair<Node*, int>> q;        // node with vertical distance
        q.push({root, 0});

        while (!q.empty()) {
            auto it = q.front();
            q.pop();

            Node* node = it.first;
            int line = it.second;

            mp[line] = node->data;        // overwrite to get bottom-most node

            if (node->left) q.push({node->left, line - 1});
            if (node->right) q.push({node->right, line + 1});
        }

        for (auto it : mp) ans.push_back(it.second);  // extract bottom view
        return ans;
    }
};

// Driver code to test the bottom view
int main() {
    // Building the specific binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->left = new Node(8);
    root->right->left->right = new Node(9);

    Solution solution;
    vector<int> bottomView = solution.bottomView(root);

    cout << "Bottom View Traversal: " << endl;
    for (int node : bottomView) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
