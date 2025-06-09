#include <iostream>
#include <vector>
#include <queue>
using namespace std;


// Definition of ListNode (LeetCode style)
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Merge k sorted lists using min-heap of (val, ListNode*)
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;

        for (int i = 0; i < lists.size(); ++i) {
            if (lists[i]) {
                pq.push({lists[i]->val, lists[i]});
            }
        }

        
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            temp->next = it.second;
            temp = temp->next;

            if (it.second->next) {
                pq.push({it.second->next->val, it.second->next});
            }
        }

        return dummy->next;
    }
};

// Helper function to create a linked list from a vector
ListNode* createList(const vector<int>& vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* curr = head;
    for (int i = 1; i < vals.size(); ++i) {
        curr->next = new ListNode(vals[i]);
        curr = curr->next;
    }
    return head;
}

// Helper function to print a linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Main function to test
int main() {
    vector<vector<int>> input = {
        {1, 4, 5},
        {1, 3, 4},
        {2, 6}
    };

    vector<ListNode*> lists;
    for (const auto& v : input) {
        lists.push_back(createList(v));
    }

    Solution sol;
    ListNode* result = sol.mergeKLists(lists);

    cout << "Merged List: ";
    printList(result);

    return 0;
}