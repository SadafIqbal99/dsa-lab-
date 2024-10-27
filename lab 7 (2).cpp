#include <iostream>

using namespace std;

struct Node {
    string item;
    Node* next;
};

Node* head = NULL;

void addToList(string item) {
    Node* newNode = new Node;
    newNode->item = item;
    newNode->next = head;
    head = newNode;
}

void removeFromList(string item) {
    Node* current = head;
    Node* previous = NULL;

    while (current != NULL && current->item != item) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        cout << "Item not found in the list." << endl;
        return;
    }

    if (previous == NULL) {
        head = current->next;
    } else {
        previous->next = current->next;
    }

    delete current;
    cout << "Item removed from the list." << endl;
}

void viewList() {
    Node* current = head;

    if (current == NULL) {
        cout << "List is empty." << endl;
        return;
    }

    cout << "Grocery Shopping List:\n";
    while (current != NULL) {
        cout << "- " << current->item << endl;
        current = current->next;
    }
}

int main() {
    int choice;
    string item;

    do {
        cout << "Enter your choice:"<<endl;
        cout << "1. Add an item"<<endl;
        cout << "2. Remove an item"<<endl;
        cout << "3. View the list"<<endl;
        cout << "4. Exit"<<endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the item: ";
                cin >> item;
                addToList(item);
                break;
            case 2:
                cout << "Enter the item to remove: ";
                cin >> item;
                removeFromList(item);
                break;
            case 3:
                viewList();
                break;
            case 5:
                cout << "Exiting..."<<endl;
                break;
            default:
                cout << "Invalid choice. Please try again."<<endl;
        }

    } while (choice != 4);

    return 0;
}