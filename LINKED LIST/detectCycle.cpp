#include <iostream>
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
public:
     bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        return false;
    }
};
int main() {
    Solution solution;
    // Creating a linked list without a cycle
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);
    // Test hasCycle function
    std::cout << "Test 1 - Without Cycle: " << (solution.hasCycle(head1) ? "Cycle detected" : "No cycle") << std::endl;
    // Creating a linked list with a cycle
    ListNode* head2 = new ListNode(5);
    head2->next = new ListNode(6);
    head2->next->next = new ListNode(7);
    head2->next->next->next = head2->next; // Creating a cycle (points back to the second node)

    // Test hasCycle function
    std::cout << "Test 2 - With Cycle: " << (solution.hasCycle(head2) ? "Cycle detected" : "No cycle") << std::endl;
    // Cleanup
    delete head1->next->next->next; // Deleting last node in the first list
    delete head1->next->next;        // Deleting third node
    delete head1->next;              // Deleting second node
    delete head1;                    // Deleting head node

    // Since head2 has a cycle, we don't need to delete the list manually
    // Just to avoid memory leak, normally we'd handle this in a destructor

    return 0;
}
