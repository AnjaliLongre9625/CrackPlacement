#include <bits/stdc++.h>
using namespace std;
class ListNode{
    public:
    int data;
    ListNode*next;

    //CONSTRUCTORE
    ListNode(int data1){
        data=data1;
        next=nullptr;
    }
};
bool hasCycle(ListNode *head) {
        ListNode*slow=head;
        ListNode*fast=head;
        
        while(fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast) return true;
        }
        return false;
    }
 
int main(){
    ListNode*head= new ListNode(3);
    ListNode*first= new ListNode(2);
    ListNode*second= new ListNode(0);
    ListNode*third= new ListNode(-4);
     head->next = first;
    first->next = second;
    second->next = third;

    // Introducing the cycle: -4 -> 0
    int pos = 2; // We want to create a cycle such that -4 points to node with value 0
    if (pos >= 0) {
        ListNode *cycleStart = head;
        for (int i = 0; i < pos; ++i) {
            cycleStart = cycleStart->next;
        }
        third->next = cycleStart; // Creating the cycle
    }

    // Checking for a cycle
    if (hasCycle(head)) {
        cout << "Loop detected in the linked list." << endl;
    } else {
        cout << "No loop detected in the linked list." << endl;
    }
    return 0;
}