#include <bits/stdc++.h>
using namespace std;
struct ListNode{
    int val;
    ListNode*next;
    ListNode(int x) : val(x), next(nullptr) {}
};
ListNode* deleteDuplicates(ListNode* head) {
        ListNode*curr=head;
        while(curr!=NULL && curr->next!=NULL){
            if(curr->val==curr->next->val ){
                   ListNode*ans= curr->next ;
                   curr->next=curr->next->next;
                   delete(ans);  
            }
            else{
                    curr=curr->next;
            }
        }
        return head;
    }
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Create nodes
    ListNode* head = new ListNode(1);
    ListNode* first = new ListNode(1);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(3);
    ListNode* fourth = new ListNode(3);

    // Link nodes to form the list 1 -> 1 -> 2 -> 3 -> 3
    head->next = first;
    first->next = second;
    second->next = third;
    third->next = fourth;

    
    head = deleteDuplicates(head);

    cout << "List after removing duplicates: ";
    printList(head);

    // Cleanup remaining nodes
    while (head != NULL) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}