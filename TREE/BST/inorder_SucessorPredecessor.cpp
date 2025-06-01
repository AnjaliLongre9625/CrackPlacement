#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Insert node into BST (helper)
Node* insert(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);
    return root;
}

class Solution {
  public:
  
    vector<Node*> findPreSuc(Node* root, int key) {
        Node* successor = nullptr;
        Node* predecessor = nullptr;
        
        Node* temp = root;  // save original root for second loop
        
        // Find successor
        while (temp) {
            if (key >= temp->data) {
                temp = temp->right;
            } else {
                successor = temp;
                temp = temp->left;
            }
        }
        
        temp = root;  // reset temp to root for predecessor search
        
        // Find predecessor
        while (temp) {
            if (key <= temp->data) {
                temp = temp->left;
            } else {
                predecessor = temp;
                temp = temp->right;
            }
        }
        
        return {predecessor, successor};
    }
};

int main() {
    Node* root = nullptr;
    // Constructing BST
    root = insert(root, 20);
    root = insert(root, 8);
    root = insert(root, 22);
    root = insert(root, 4);
    root = insert(root, 12);
    root = insert(root, 10);
    root = insert(root, 14);
    
    Solution sol;
    int key = 10;
    vector<Node*> res = sol.findPreSuc(root, key);
    
    if (res[0])
        cout << "Predecessor of " << key << " is: " << res[0]->data << "\n";
    else
        cout << "No Predecessor for " << key << "\n";
    
    if (res[1])
        cout << "Successor of " << key << " is: " << res[1]->data << "\n";
    else
        cout << "No Successor for " << key << "\n";
    
    return 0;
}

// #include <iostream>
// using namespace std;

// struct TreeNode {
//     int val;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

// class Solution {
// public:
//     TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
//         TreeNode* successor=NULL;
//         while (root)
//         {
//           if(p->val>=root->val){
//             root=root->right;
//           }
//           else{
//             successor=root;
//             root=root->left;
//           }
//         }
//         return successor;
        
//     }
// };

// // Optional: Function to print inorder traversal
// void printInOrder(TreeNode* root) {
//     if (!root) return;
//     printInOrder(root->left);
//     cout << root->val << " ";
//     printInOrder(root->right);
// }

// int main() {
//     // Creating the BST
//     TreeNode* root = new TreeNode(5);
//     root->left = new TreeNode(3);
//     root->right = new TreeNode(6);
//     root->left->left = new TreeNode(2);
//     root->left->right = new TreeNode(4);
//     root->right->right = new TreeNode(7);

//     cout << "Inorder Traversal: ";
//     printInOrder(root);
//     cout << endl;

//     Solution sol;
//     TreeNode* p = root->left->right; // node with value 4

//     TreeNode* succ = sol.inorderSuccessor(root, p);
//     if (succ) {
//         cout << "Inorder Successor of " << p->val << " is: " << succ->val << endl;
//     } else {
//         cout << "Inorder Successor of " << p->val << " does not exist." << endl;
//     }

//     return 0;
// }

// ✅ Time and Space Complexity
// •	Time Complexity: O(H) where H is the height of the BST (O(log N) for balanced, O(N) worst-case).
// •	Space Complexity: O(1) — No extra space used.

// ✅ Approach for Interviewer
// "We take advantage of the BST property where the left child is smaller and the right child is greater than the node.
// We keep a successor pointer initialized as NULL and traverse the tree.
// If the current node's value is greater than the target node's value, it is a potential successor, and we move left.
// If it's less than or equal, we move right.
// This way, we track the closest greater value than the target."
// ________________________________________
// 🔁 Steps
// 1.	Initialize successor as NULL.
// 2.	Traverse the tree:
// o	If current node value > target node value:
// 	Update successor, move left.
// o	Else:
// 	Move right.
// 3.	Return successor.
// ________________________________________

     
// #include <iostream>
// #include <vector>
// #include <climits> 
// using namespace std;

// // Definition of TreeNode structure
// // for a binary tree node
// struct TreeNode {
//     // Value of the node
//     int val;
    
//     // Pointer to the left child node
//     TreeNode* left;
    
//     // Pointer to the right child node
//     TreeNode* right;

//     // Constructor to initialize the node with a
//     // value and set left and right pointers to null
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };

// class Solution {
// public:
//     // Function to find the inorder 
//     // successor of a node in a BST
//     TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
//         // Store the inorder traversal of the tree
//         vector<int> inorder;
//         // Perform in-order traversal to
//         // generate the sorted list
//         inorderTraversal(root, inorder);
        
//         // Binary search to find the
//         // index of the node's value
//         int idx = binarySearch(inorder, p->val);
        
//         // If index is out of range or it's the
//         // last element, return nullptr
//         if (idx == inorder.size() - 1 || idx == -1) {
//             return nullptr;
//         }
        
//         // Return the next element
//         // as the inorder successor
//         return new TreeNode(inorder[idx + 1]);
//     }
    
//     // Function to perform in-order traversal
//     // and store in 'inorder' vector
//     void inorderTraversal(TreeNode* root, vector<int>& inorder) {
//         // Base case: If the node is NULL, return
//         if (root == NULL) {
//             return;
//         }
        
//         // Traverse left subtree
//         inorderTraversal(root->left, inorder);
        
//         // Store current node's value
//         // in 'inorder' vector
//         inorder.push_back(root->val);
        
//         // Traverse right subtree
//         inorderTraversal(root->right, inorder);
//     }
    
//     // Function to perform
//     // binary search on array
//     int binarySearch(vector<int>& arr, int target) {
//         // Initialize pointers for binary search
//         int left = 0;
//         int right = arr.size() - 1;
        
//         // Binary search algorithm to find the
//         // index of the target value
//         while (left <= right) {
//             int mid = left + (right - left) / 2;
            
//             // If target found, return the index
//             if (arr[mid] == target) {
//                 return mid;
//             } else if (arr[mid] < target) {
//                 left = mid + 1;
//             } else {
//                 right = mid - 1;
//             }
//         }
//         // If target not found,
//         // return the index for insertion
//         return left == arr.size() ? -1 : left;
//     }
// };

// // Function to perform an in-order traversal
// // of a binary tree and print its nodes
// void printInOrder(TreeNode* root) {
//     // Check if the current node
//     // is null (base case for recursion)
//     if (root == nullptr) {
//         // If null, return and
//         // terminate the function
//         return;
//     }

//     // Recursively call printInOrder
//     // for the left subtree
//     printInOrder(root->left);

//     // Print the value of the current node
//     cout << root->val << " ";

//     // Recursively call printInOrder
//     // for the right subtree
//     printInOrder(root->right);
// }

// int main() {
//     Solution solution;

//     // Constructing the BST
//     TreeNode* root = new TreeNode(5);
//     root->left = new TreeNode(3);
//     root->right = new TreeNode(6);
//     root->left->left = new TreeNode(2);
//     root->left->right = new TreeNode(4);
//     root->right->right = new TreeNode(7);
    
//     cout << "BST: ";
//     printInOrder(root);
//     cout << endl;
    
//     // Node for which we want to
//     // find the inorder successor
//     TreeNode* p = root->left->right;
    
//     // Find the inorder successor
//     TreeNode* successor = solution.inorderSuccessor(root, p);
    
//     // Print the inorder successor's value
//     if (successor != nullptr) {
//         cout << "Inorder Successor of " << p->val << " is: " << successor->val << endl;
//     } else {
//         cout << "Inorder Successor of " << p->val << " does not exist." << endl;
//     }
    
//     return 0;
// }
                                
                            

// 🧠 Approach (Explain to Interviewer):
// 1.	Do an inorder traversal of the BST and store all the node values in a vector (gives sorted order).
// 2.	Find the index of the given node’s value in that inorder array.
// 3.	The successor is the next value in that array, and the predecessor is the previous one (if available).
// ________________________________________
// 🧾 Time & Space Complexity:
// •	Time Complexity: O(N + log N)
// o	O(N) for inorder traversal
// o	O(log N) for binary search
// •	Space Complexity: O(N)
// o	Extra space for storing the inorder traversal.
// ________________________________________
// 💡 Steps Summary (Tell Interviewer):
// 1.	Perform an inorder traversal to get the sorted list of node values.
// 2.	Use binary search to find the index of the target node's value.
// 3.	Return:
// o	inorder[idx - 1] as predecessor (if exists)
// o	inorder[idx + 1] as successor (if exists)

