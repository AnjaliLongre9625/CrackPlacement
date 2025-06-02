#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Function to sort the linked list
Node* sortList(Node *head) {
    if(head == NULL || head->next == NULL) return head;
    
    Node* zerohead = new Node(-1), *zero = zerohead;
    Node* onehead = new Node(-1), *one = onehead;
    Node* twohead = new Node(-1), *two = twohead;
    
    Node* temp = head;
    while(temp != NULL) {
        if(temp->data == 0) {
            zero->next = temp;
            zero = temp;
        }
        else if(temp->data == 1) {
            one->next = temp;
            one = temp;
        }

        else {
            two->next = temp;
            two = temp;
        }
        
        temp = temp->next;
    }

    // Link the lists together
    zero->next = onehead->next ? onehead->next : twohead->next;
    one->next = twohead->next;
    two->next = NULL; // Properly terminate the last node
    
    return zerohead->next;
}

// Function to insert a node at the end
Node* insert(Node* head, int val) {
    Node* newNode = new Node(val);
    if(head == NULL) {
        return newNode;
    }
    Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Main function
int main() {
    Node* head = NULL;

    // Create a linked list with 0, 1, and 2 values
    head = insert(head, 1);
    head = insert(head, 2);
    head = insert(head, 0);
    head = insert(head, 1);
    head = insert(head, 2);
    head = insert(head, 0);
    head = insert(head, 1);

    cout << "Original list: ";
    printList(head);

    // Sort the list
    head = sortList(head);

    cout << "Sorted list: ";
    printList(head);

    return 0;
}
