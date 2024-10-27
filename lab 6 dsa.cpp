#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

void insert(Node*& head, int value) {
    Node* newNode = new Node(value);
    
    if (head == NULL) {
        head = newNode;
        newNode->next = head; 
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode; 
        newNode->next = head;
    }
}


void deleteNode(Node*& head, int position) {
    if (head == nullptr) {
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }

    Node* temp = head;

   
    if (position == 1) {
        if (head->next == head) { 
            delete head;
            head = nullptr;
            return;
        }
        
      
        while (temp->next != head) {
            temp = temp->next;
        }

        Node* toDelete = head; 
        head = head->next;     
        temp->next = head;     
        delete toDelete;       
        return;
    }

   
    for (int i = 1; temp->next != head && i < position - 1; i++) {
        temp = temp->next;
    }

    
    if (temp->next == head) {
        cout << "Position does not exist." << endl;
        return;
    }

    Node* toDelete = temp->next;
    temp->next = toDelete->next; 
    delete toDelete;              
}


void display(Node* head) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    Node* temp = head;
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);
    cout << "(back to head)" << endl; 
}

int main() {
    Node* head = nullptr;

    
    insert(head, 10);
    insert(head, 20);
    insert(head, 30);
    insert(head, 40);
    insert(head, 50);

    cout << "Before deletion of any node:"<<endl;
    display(head);

    int position;
    cout << "Enter the position of the node you want to delete : ";
    cin >> position;

    deleteNode(head, position);

    cout << "Link list after deletion of one node : "<<endl;
    display(head);

    

    return 0;
}