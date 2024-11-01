                            
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Node structure for the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;
    // Constructor to initialize the node with a value
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to get the Preorder,Inorder and Postorder traversal Of Binary Tree in One traversal
vector<vector<int>> preInPostTraversal(Node* root) {
    stack<pair<Node*,int>>st;
    st.push({root,1});
    vector<int>pre,post,in;
    if(root==NULL) return {};

    while(!st.empty()){
        auto it=st.top();
        st.pop();

        if (it.second == 1) {
            pre.push_back(it.first->data);
            it.second = 2;
            st.push(it);

            if (it.first->left != NULL) {
                st.push({it.first->left, 1});
            }
        }
        // Inorder
        else if (it.second == 2) {
            in.push_back(it.first->data);
            it.second = 3;
            st.push(it);

            if (it.first->right != NULL) {
                st.push({it.first->right, 1});
            }
        }
        // Postorder
        else {
            post.push_back(it.first->data);
        }
    }
    return {pre, in, post};
}


// Function to print the
// elements of a vector
void printVector(const vector<int>& vec) {
    // Iterate through the vector
    // and print each element
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

// Main function
int main()
{
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // Getting the pre-order, in-order,
    // and post-order traversals
    vector<int> pre, in, post;
    vector<vector<int>> traversals = preInPostTraversal(root);

    // Extracting the traversals
    // from the result
    pre = traversals[0];
    in = traversals[1];
    post = traversals[2];

    // Printing the traversals
    cout << "Preorder traversal: ";
    for (int val : pre) {
        cout << val << " ";
    }
    cout << endl;

    cout << "Inorder traversal: ";
    for (int val : in) {
        cout << val << " ";
    }
    cout << endl;

    cout << "Postorder traversal: ";
    for (int val : post) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
                            
                        