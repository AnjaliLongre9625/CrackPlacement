#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = nullptr;
    }

};
/* Multiply contents of two linked lists */
class solution {
  public:
    long long multiplyTwoLists(Node *first, Node *second) {
        long long num1=0,num2=0;
        int MOD=1000000007;
        struct Node *p1,*p2;
        p1=first,p2=second;
        while(p1!=NULL){
            num1=(num1*10+p1->data)%MOD;
            p1=p1->next;
        }
        while(p2!=NULL){
            num2=(num2*10+p2->data)%MOD;
            p2=p2->next;
        }

        return(num1*num2)%MOD;
    }
};void printList(Node* node) {
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

// Function to push a new node to the front of the list
void push(Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

int main() {
    // Creating first linked list: 3 -> 2 -> 1 which represents the number 321
    Node* first = nullptr;
    push(&first, 1);
    push(&first, 2);
    push(&first, 3);

    // Creating second linked list: 4 -> 5 -> 6 which represents the number 654
    Node* second = nullptr;
    push(&second, 6);
    push(&second, 5);
    push(&second, 4);

    // Print the two linked lists
    cout << "First list: ";
    printList(first);
    cout << "Second list: ";
    printList(second);

    // Create an instance of the solution class
    solution sol;
    // Call the multiplyTwoLists function and get the result
    long long result = sol.multiplyTwoLists(first, second);

    // Print the result
    cout << "Product of two numbers: " << result << endl;

    return 0;
}