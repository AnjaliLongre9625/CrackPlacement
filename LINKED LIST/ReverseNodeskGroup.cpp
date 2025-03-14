#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        // Step 1: Check if there are at least k nodes
        for (int i = 0; i < k; i++) {
            if (!temp) return head; // If fewer than k nodes, return as is
            temp = temp->next;
        }
        // Step 2: Reverse k nodes
        ListNode* prev = NULL;
        ListNode* curr = head;
        for (int i = 0; i < k; i++) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        // Step 3: Connect next part (recursive call)
        head->next = reverseKGroup(temp, k);
        return prev; // New head of the reversed group
    }
};

// Function to create a linked list from an array
ListNode* createLinkedList(int arr[], int n) {
    if (n == 0) return NULL;
    ListNode* head = new ListNode(arr[0]);
    ListNode* curr = head;
    for (int i = 1; i < n; i++) {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    return head;
}

// Function to print the linked list
void printLinkedList(ListNode* head) {
    while (head != NULL) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;
    
    // Create the linked list
    ListNode* head = createLinkedList(arr, n);
    cout << "Original List: ";
    printLinkedList(head);
    
    // Reverse k-group
    Solution sol;
    head = sol.reverseKGroup(head, k);
    
    // Print the result
    cout << "Reversed in k-Groups: ";
    printLinkedList(head);
    
    return 0;
}
