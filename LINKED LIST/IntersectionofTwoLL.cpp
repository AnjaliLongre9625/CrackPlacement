#include <bits/stdc++.h>
using namespace std;
class ListNode{
public:
    int data;
    ListNode *next;

    // CONSTRUCTORE
    ListNode(int data1){
        data = data1;
        next = nullptr;
    }
};


class Solution{
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        
        while (temp1 != temp2) {
            temp1 = temp1->next;
            temp2 = temp2->next;
            
            if(temp1==temp2) return temp1;
            if (temp1 == NULL)temp1 = headB;
            if (temp2 == NULL)temp2 = headA;
        }
        return temp1;
    }
};
    
ListNode* createLinkedList(vector<int> values) {
    if (values.empty()) return nullptr;
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    
    for (int i = 1; i < values.size(); i++) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

// Helper function to print a linked list
void printLinkedList(ListNode* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Create two linked lists
    vector<int> listA = {3, 1,4,6,2};
    vector<int> listB = {1,2,4,5,4,6,2};
    vector<int> common = {4,6,2};

    ListNode* headA = createLinkedList(listA);
    ListNode* headB = createLinkedList(listB);
    ListNode* commonNode = createLinkedList(common);

    // Attach the common part to both lists
    ListNode* temp = headA;
    while (temp->next != nullptr) temp = temp->next;
    temp->next = commonNode;

    temp = headB;
    while (temp->next != nullptr) temp = temp->next;
    temp->next = commonNode;

    // Print both lists
    cout << "List A: ";
    printLinkedList(headA);

    cout << "List B: ";
    printLinkedList(headB);

    // Find intersection
    Solution solution;
    ListNode* intersection = solution.getIntersectionNode(headA, headB);

    if (intersection != nullptr) {
        cout << "Intersection at node with value: " << intersection->data << endl;
    } else {
        cout << "No intersection found." << endl;
    }

    return 0;
}

