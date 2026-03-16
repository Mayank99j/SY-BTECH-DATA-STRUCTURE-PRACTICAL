#include <iostream>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

Node* head = NULL;

// Insert at Beginning
void insertBeginning(int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

// Insert at End
void insertEnd(int value) {
    Node* newNode = new Node(value);

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Insert at Any Position
void insertAtPosition(int value, int position) {
    Node* newNode = new Node(value);

    if (position == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;

    for (int i = 1; i < position - 1; i++) {
        if (temp == NULL) {
            cout << "Position out of range\n";
            return;
        }
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Display List
void display() {
    Node* temp = head;
    cout << "Linked List: ";

    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL\n";
}

// Main Function
int main() {
    insertBeginning(10);
    insertBeginning(5);

    insertEnd(20);
    insertEnd(30);

    insertAtPosition(15, 3); // Insert at position 3

    display();

    return 0;
}