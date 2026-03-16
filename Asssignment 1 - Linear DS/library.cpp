#include <iostream>
using namespace std;

// Book Structure
struct Book {
    string id;
    string title;
    bool isIssued;
    Book* next;
};

// Category Structure
struct Category {
    string name;
    Book* bookHead;
    Category* next;
};

// Global Head Pointer
Category* categoryHead = NULL;

// --------------------------------------------------
// Helper Function to Find Category
// --------------------------------------------------
Category* getCategory(string categoryName) {
    Category* temp = categoryHead;
    while (temp != NULL) {
        if (temp->name == categoryName)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

// --------------------------------------------------
// Create Category (Insert at Beginning)
// --------------------------------------------------
void addCategory(string categoryName) {
    if (getCategory(categoryName) != NULL) {
        cout << "Category already exists!\n";
        return;
    }

    Category* newCategory = new Category();
    newCategory->name = categoryName;
    newCategory->bookHead = NULL;
    newCategory->next = categoryHead;
    categoryHead = newCategory;

    cout << "Category created successfully.\n";
}

// --------------------------------------------------
// Add Book (Insert at End)
// --------------------------------------------------
void addBook(string categoryName, string bookID, string bookTitle) {

    Category* cat = getCategory(categoryName);

    if (cat == NULL) {
        cout << "Category does not exist!\n";
        return;
    }

    // Check Duplicate Book ID
    Book* check = cat->bookHead;
    while (check != NULL) {
        if (check->id == bookID) {
            cout << "Book ID already exists!\n";
            return;
        }
        check = check->next;
    }

    Book* newBook = new Book();
    newBook->id = bookID;
    newBook->title = bookTitle;
    newBook->isIssued = false;
    newBook->next = NULL;

    if (cat->bookHead == NULL) {
        cat->bookHead = newBook;
    } else {
        Book* temp = cat->bookHead;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newBook;
    }

    cout << "Book added successfully.\n";
}

// --------------------------------------------------
// Search Book
// --------------------------------------------------
void searchBook(string categoryName, string bookID) {

    Category* cat = getCategory(categoryName);

    if (cat == NULL) {
        cout << "Category not found!\n";
        return;
    }

    Book* temp = cat->bookHead;

    while (temp != NULL) {
        if (temp->id == bookID) {
            cout << "\nBook Details:\n";
            cout << "ID: " << temp->id << endl;
            cout << "Title: " << temp->title << endl;
            cout << "Status: " 
                 << (temp->isIssued ? "Issued" : "Available") << endl;
            return;
        }
        temp = temp->next;
    }

    cout << "Book not found.\n";
}

// --------------------------------------------------
// Issue Book
// --------------------------------------------------
void issueBook(string categoryName, string bookID) {

    Category* cat = getCategory(categoryName);

    if (cat == NULL) {
        cout << "Category not found!\n";
        return;
    }

    Book* temp = cat->bookHead;

    while (temp != NULL) {
        if (temp->id == bookID) {

            if (temp->isIssued) {
                cout << "Book is already issued.\n";
            } else {
                temp->isIssued = true;
                cout << "Book issued successfully.\n";
            }
            return;
        }
        temp = temp->next;
    }

    cout << "Book not found.\n";
}

// --------------------------------------------------
// Display Complete Library
// --------------------------------------------------
void displayLibrary() {

    if (categoryHead == NULL) {
        cout << "Library is empty.\n";
        return;
    }

    Category* cat = categoryHead;

    while (cat != NULL) {

        cout << "\n=== Category: " << cat->name << " ===\n";

        if (cat->bookHead == NULL) {
            cout << "No books in this category.\n";
        } else {
            Book* temp = cat->bookHead;

            while (temp != NULL) {
                cout << "[" << temp->id << "] "
                     << temp->title << " -> "
                     << (temp->isIssued ? "Issued" : "Available")
                     << endl;

                temp = temp->next;
            }
        }

        cat = cat->next;
    }
}

// --------------------------------------------------
// Main Function
// --------------------------------------------------
int main() {

    int choice;
    string categoryName, bookID, bookTitle;

    do {
        cout << "\n----- LIBRARY SYSTEM -----\n";
        cout << "1. Add Category\n";
        cout << "2. Add Book\n";
        cout << "3. Search Book\n";
        cout << "4. Issue Book\n";
        cout << "5. Display Library\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter category name: ";
            cin >> categoryName;
            addCategory(categoryName);
            break;

        case 2:
            cout << "Enter category name: ";
            cin >> categoryName;
            cout << "Enter Book ID: ";
            cin >> bookID;
            cout << "Enter Book Title: ";
            cin >> bookTitle;
            addBook(categoryName, bookID, bookTitle);
            break;

        case 3:
            cout << "Enter category name: ";
            cin >> categoryName;
            cout << "Enter Book ID: ";
            cin >> bookID;
            searchBook(categoryName, bookID);
            break;

        case 4:
            cout << "Enter category name: ";
            cin >> categoryName;
            cout << "Enter Book ID: ";
            cin >> bookID;
            issueBook(categoryName, bookID);
            break;

        case 5:
            displayLibrary();
            break;

        case 6:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 6);

    return 0;
}