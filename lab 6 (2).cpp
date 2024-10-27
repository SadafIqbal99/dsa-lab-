#include <iostream>
using namespace std;
struct node{
	int data;
	node *next;
	node *pre;
	node(int value)
	{
		data=value;
		next=NULL;
		pre=NULL;
		
	}
};
void insertAtPosition(node*& head, int value, int position) {
    node* n = new node(value);

    
    if (position == 1) {
        if (head == NULL) {
            head = n;
            n->next = head; // Link to itself (circular)
            n->pre = head;  // Link to itself (circular)
        } 
            node* temp = head;

            
            while (temp->next != head) {
                temp = temp->next;
            }

            
            n->next = head;
            n->pre = temp;
            temp->next = n;
            head->pre = n;
            head = n;
        return;
    }

    node* temp = head;
    int i=1;

    while ( i < position - 1 && temp->next != head) {
        temp = temp->next;
        i++;
    }

    
    if (temp->next == head && i < position - 1) {
        cout << "Position is out of bounds." << endl;
        delete n;
        return;
    }

    // Case 2: Insert in the middle or at the end
    n->next = temp->next;
    n->pre = temp;

    
    if (temp->next != head) {
        temp->next->pre = n;
    } else {
        // If inserting at the end, update the last node to point to the new node
        head->pre = n;
    }

    temp->next = n;
}

// Function to display the circular doubly linked list without using a do-while loop
void display(node* head) {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }

    node* temp = head;

    // Print the first node
    cout << temp->data << " <-> ";
    temp = temp->next;

    while (temp != head) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }

    cout << "(back to head)" << endl;
}

int main() {
    node* head = NULL;
    int value, position;

    insertAtPosition(head, 10, 1);
    insertAtPosition(head, 20, 2);
    insertAtPosition(head, 30, 3);
    
    
    display(head);

    cout << "Enter value to insert: ";
    cin >> value;
    cout << "Enter position to insert at: ";
    cin >> position;

    
    insertAtPosition(head, value, position);

   
    display(head);

    return 0;}