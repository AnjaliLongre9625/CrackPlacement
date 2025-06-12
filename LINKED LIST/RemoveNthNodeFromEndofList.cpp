#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
ListNode *removeNthFromEnd(ListNode *head, int n){
    ListNode *fast = head;
    ListNode *slow = head;
    
    for (int i = 0; i < n; i++)
        fast = fast->next;

    if (fast == nullptr) return head->next;

    while (fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next;
    }
    ListNode *temp = slow->next;
    slow->next = slow->next->next;
    delete temp;
    return head;
}

void printList(ListNode *head){
    while (head != nullptr)
    {
        cout << head->val;
        head = head->next;
    }
    cout << endl;
}

int main()
{
    ListNode *head = new ListNode(1);
    ListNode *first = new ListNode(2);
    ListNode *second = new ListNode(3);
    ListNode *third = new ListNode(4);
    ListNode *fourth = new ListNode(5);

    // Link nodes to form the list 1 -> 1 -> 2 -> 3 -> 3
    head->next = first;
    first->next = second;
    second->next = third;
    third->next = fourth;

    int n = 2;
    head = removeNthFromEnd(head, n);

    cout << "removing n nodes: ";
    printList(head);

    while (head != NULL){
        ListNode *temp = head;
        head = head->next;
        delete temp;
    }
    return 0;
}