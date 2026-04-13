//Direct Addressing 

#include <stdio.h>

#define SIZE 100   // Maximum key value

int table[SIZE];   // Direct address table

// Initialize table with -1 (means empty)
void initialize() {
    for (int i = 0; i < SIZE; i++) {
        table[i] = -1;
    }
}

// Insert element
void insert(int key) {
    table[key] = key;
    printf("Inserted %d\n", key);
}

// Search element
void search(int key) {
    if (table[key] != -1)
        printf("Element %d found\n", key);
    else
        printf("Element %d not found\n", key);
}

// Delete element
void deleteKey(int key) {
    if (table[key] != -1) {
        table[key] = -1;
        printf("Element %d deleted\n", key);
    } else {
        printf("Element not present\n");
    }
}

int main() {
    initialize();

    insert(10);
    insert(25);
    insert(50);

    search(25);
    search(30);

    deleteKey(25);
    search(25);

    return 0;
}