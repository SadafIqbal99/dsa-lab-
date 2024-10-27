#include <iostream>

using namespace std;

const int MAX_PLATES = 3;

int plates[MAX_PLATES];
int top = -1;

void addPlate(int plateNumber) {
    if (top == MAX_PLATES - 1) {
        cout << "Stack is full. Cannot add more plates." << endl;
        return;
    }

    top++;
    plates[top] = plateNumber;
}

int removeTopPlate() {
    if (top == -1) {
        cout << "Stack is empty. Cannot remove plates." << endl;
        return -1; 
    }

    int topPlate = plates[top];
    top--;
    return topPlate;
}

int checkTopPlate() {
    if (top == -1) {
        cout << "Stack is empty. No top plate." << endl;
        return -1; 
    }

    return plates[top];
}

int main() {
    int choice;
    int plateNumber;

    do {
        cout << "Enter your choice:"<<endl;
        cout << "1. Add a plate"<<endl;
        cout << "2. Remove a plate"<<endl;
        cout << "3. Check top plate"<<endl;
        cout << "4. Exit"<<endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the plate number: ";
                cin >> plateNumber;
                addPlate(plateNumber);
                break;
            case 2:
                cout << "Removed plate: " << removeTopPlate() << endl;
                break;
            case 3:
                cout << "Top plate: " << checkTopPlate() << endl;
                break;
            case 4:
                cout << "Exiting..."<<endl;
                break;
            default:
                cout << "Invalid choice. Please try again."<<endl;
        }

    } while (choice != 4);

    return 0;
}