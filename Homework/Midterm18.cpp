#include <iostream>
using namespace std;

struct ListNode {
    int val; // Value in the node 
    ListNode* next; // Pointer to the next node in the list
    ListNode(int x) : val(x), next(nullptr) {} //Constructor for the nodes value and first pointer
};

void reversePrint(ListNode* head) {
    if (head == nullptr) return; // If the list is empty, do nothing
    reversePrint(head->next);     // Recursive call to reach the end of the list
    cout << head->val << endl;    // Print each element as the stack unwinds
}

int main() {
    int n;
    cout << "Enter the number of elements in the linked list: ";
    cin >> n; // Users input to list size

    // Checking if theres not enough space to make a list
    if (n <= 0) {
        cout << "The linked list is empty." << endl;
        return 0;
    }

    // Initialize the pointer to the head and tail as null
    cout << "Enter the elements of the linked list:" << endl;
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    // Loop to read n elements
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        ListNode* newNode = new ListNode(value); // Creates a new node for the input value 

        if (head == nullptr) { // Just for the first node
            // Sets both the head and tail to point to the new node
            head = newNode; 
            tail = newNode;
        } else { // Any node after first
            tail->next = newNode; // Links the new node to the end of the list
            tail = newNode; // Sets the tail to point to the new node
        }
    }

    cout << "Elements in reverse order:" << endl;
    reversePrint(head);

    return 0;
}