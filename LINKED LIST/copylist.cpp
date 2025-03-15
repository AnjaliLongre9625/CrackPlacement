#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node*temp=head;
        unordered_map<Node*,Node*>mpp;
        //create copy of nodes assignned to map
        while (temp!=NULL)
        {
            Node*newNode=new Node(temp->val);
            mpp[temp]=newNode;
            temp=temp->next;
        }
        //assigned random and copy pointer
        temp=head;
        while (temp!=NULL)
        {
            Node*copyNode=mpp[temp];
            copyNode->next=mpp[temp->next];
            copyNode->random=mpp[temp->random];
            temp=temp->next;
        }
        return mpp[head];
    }
};

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << "Value: " << temp->val;
        if (temp->random != NULL) {
            cout << ", Random: " << temp->random->val;
        } else {
            cout << ", Random: NULL";
        }
        cout << endl;
        temp = temp->next;
    }
}

int main() {
    // Creating the list: 7 -> 13 -> 11 -> 10 -> 1
    Node* head = new Node(7);
    head->next = new Node(13);
    head->next->next = new Node(11);
    head->next->next->next = new Node(10);
    head->next->next->next->next = new Node(1);

    // Setting up random pointers
    head->random = NULL;
    head->next->random = head;
    head->next->next->random = head->next->next->next->next;
    head->next->next->next->random = head->next->next;
    head->next->next->next->next->random = head;

    cout << "Original list:\n";
    printList(head);

    Solution obj;
    Node* copiedList = obj.copyRandomList(head);

    cout << "\nCopied list:\n";
    printList(copiedList);

    return 0;
}
