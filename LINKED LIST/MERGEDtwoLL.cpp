#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to merge two sorted linked lists
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
   
    // Create a dummy node to serve as the starting point of the merged list
    ListNode* dummyNode = new ListNode(-1);
    ListNode* temp = dummyNode;
    
   
    // Traverse both lists while both are not empty
    while (list1 != nullptr && list2 != nullptr) {
        if (list1->val <= list2->val) {
            temp->next = list1;
            list1 = list1->next;
        } else {
            temp->next = list2;
            list2 = list2->next;
        }
        // Move the pointer forward in the merged list
        temp = temp->next;
    }
    
    // Attach the remaining elements from either list1 or list2
    if (list1 != nullptr) {
        temp->next = list1;
    } else {
        temp->next = list2;
    }
    
    // Get the merged list starting from the first node
    ListNode* mergedList = dummyNode->next;
    delete dummyNode; // Free the memory of the dummy node
    
    return mergedList;
}

// Helper function to create a linked list from a vector of integers
ListNode* createList(const vector<int>& values) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for (int value : values) {
        ListNode* newNode = new ListNode(value);
        if (!head) {
            head = newNode;
        } else {
            tail->next = newNode;
        }
        tail = newNode;
    }
    return head;
}

// Helper function to print a linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Test case 1: Both lists are empty
    ListNode* list1 = nullptr;
    ListNode* list2 = nullptr;
    ListNode* mergedList = mergeTwoLists(list1, list2);
    cout << "Merged List (Both lists empty): ";
    printList(mergedList);  // Expected output: (empty)

    
    // Test case 2: Lists with different lengths
    list1 = createList({1, 2, 4, 5});
    list2 = createList({1, 3});
    mergedList = mergeTwoLists(list1, list2);
    cout << "Merged List (Different lengths): ";
    printList(mergedList);  // Expected output: 1 1 2 3 4 5

    return 0;
}
