// linked list code 
#include <iostream>
using namespace std;

// define structure of the node
struct Node{
    int data;
    Node* next;
};

Node* head = NULL;

// Function to insert at end 
void insert(int value){
    Node* newnode = new Node();
    newnode ->data = value;
    newnode ->next - NULL;
    if (head == NULL){
        head = newnode;
        return;
    }
    else {
        Node* temp = head; 
        while(temp ->next !=NULL){
            temp=temp->next;
        }
        temp->next = newnode;
    }
}

// function to display linked list
void display(){
    Node* temp = head;
    while(temp !=NULL){
        cout << temp->data << " -> ";
        temp = temp-> next;
    }
    cout << "NULL" << endl; 
}

int main(){
    insert(10);
    insert(20);
    insert(30);
    cout << "Linked list";
    display();
    return 0;
}