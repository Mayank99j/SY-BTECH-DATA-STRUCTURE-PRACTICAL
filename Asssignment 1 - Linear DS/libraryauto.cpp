#include <iostream>
#include <string>
using namespace std;

// Structure for a Book Node 
struct BookNode {
    int id;
    string title;
    BookNode* next;  // Pointer to next book in the category

    // Constructor for easy creation
    BookNode(int bookId, string bookTitle) {
        id = bookId;
        title = bookTitle;
        next = NULL;
    }
};
// Structure for a Category (each category has its own linked list)
struct Category {
    string name;
    BookNode* head;  
    BookNode* tail;  

    Category(string catName) {
        name = catName;
        head = NULL;
        tail = NULL;
    }
};
class LibrarySystem {
private:
    Category* categories[10]; 
    int categoryCount;
    // Removed nextBookID as user now provides ID

public:
    LibrarySystem() {
        categoryCount = 3;
        categories[0] = new Category("Fiction");
        categories[1] = new Category("Computer Science");
        categories[2] = new Category("History");
    }
    // Display all categories
    void showCategories() {
        cout << "\nAvailable Categories:\n";
        for (int i = 0; i < categoryCount; i++) {
            cout << i + 1 << ". " << categories[i]->name << endl;
        }
    }
    // Add a new book 
    void addBook() {
        cout << "\n--- Add New Book ---\n";
        showCategories();

        int catChoice;
        cout << "Select category (1-" << categoryCount << "): ";
        cin >> catChoice;
        cin.ignore();

        if (catChoice < 1 || catChoice > categoryCount) {
            cout << "Invalid category!\n";
            return;
        }

        Category* selectedCat = categories[catChoice - 1];

        int bookId;
        string title;
        cout << "Enter Book ID (unique): ";
        cin >> bookId;
        cin.ignore(); 
        cout << "Enter Book Title: ";
        getline(cin, title);
       
        // Create new book node
        BookNode* newBook = new BookNode(bookId, title);
        // Add to linked list
        if (selectedCat->head == NULL) {
            selectedCat->head = newBook;
            selectedCat->tail = newBook;
        } else {
            selectedCat->tail->next = newBook;
            selectedCat->tail = newBook;
        }
        cout << "Book added successfully!\n";
        cout << "   ID: " << newBook->id << " | Title: " << newBook->title << endl;
        cout << "   Category: " << selectedCat->name << endl;
    }
    // Issue a  book by ID
    void issueBook() {
        cout << "\n--- Issue Book ---\n";
        if (categories[0]->head == NULL && categories[1]->head == NULL && categories[2]->head == NULL) {
            cout << "Library is empty! No books to issue.\n";
            return;
        }

        int bookID;
        cout << "Enter Book ID to issue: ";
        cin >> bookID;

    // Search in each category 
        for (int i = 0; i < categoryCount; i++) {
            Category* cat = categories[i];
            BookNode* current = cat->head;
            BookNode* prev = NULL;

            while (current != NULL) {
                if (current->id == bookID) {
                    cout << "\nBook Found!\n";
                    cout << "   ID: " << current->id << endl;
                    cout << "   Title: " << current->title << endl;
                    cout << "   Category: " << cat->name << endl;

                    if (prev == NULL) {
                        cat->head = current->next;
                        if (cat->head == NULL) {
                            cat->tail = NULL; 
                        }
                    } else {
                        prev->next = current->next;
                        if (current->next == NULL) {
                            cat->tail = prev; 
                        }
                    }
                    delete current; 
                    cout << "Book issued successfully!\n";
                    return;
                }
                prev = current;
                current = current->next;
            }
        }

        cout << "Book ID " << bookID << " not found in library!\n";
    }

    // Display all books (Traverse)
    void displayAllBooks() {
        cout << "\nLIBRARY CATALOG \n";
        cout << "=====================\n";

        bool anyBook = false;

        for (int i = 0; i < categoryCount; i++) {
            Category* cat = categories[i];
            cout << "\nCategory: " << cat->name << endl;
            cout << "   ";
            for (int j = 0; j < 40; j++) cout << "-";
            cout << endl;

            BookNode* current = cat->head;
            if (current == NULL) {
                cout << " [No books in this category]\n";
            } else {
                anyBook = true;
                int count = 1;
                while (current != NULL) {
                    cout << "   " << count++ << ". ";
                    cout << "ID: " << current->id << " | ";
                    cout << "Title: " << current->title << endl;
                    current = current->next;
                }
            }
        }

        if (!anyBook) {
            cout << "\n The library is completely empty!\n";
        }
        cout << "\n=====================\n";
    }

    // Search for a book by ID (without issuing)
    void searchBook() {
        cout << "\n--- Search Book ---\n";

        int bookID;
        cout << "Enter Book ID to search: ";
        cin >> bookID;

        for (int i = 0; i < categoryCount; i++) {
            Category* cat = categories[i];
            BookNode* current = cat->head;

            while (current != NULL) {
                if (current->id == bookID) {
                    cout << "\n Book Found!\n";
                    cout << "   ID: " << current->id << endl;
                    cout << "   Title: " << current->title << endl;
                    cout << "   Category: " << cat->name << endl;
                    cout << "   Status: Available on shelf\n";
                    return;
                }
                current = current->next;
            }
        }

        cout << "Book ID " << bookID << " not found in library!\n";
    }
    // Destructor to free memory
    ~LibrarySystem() {
        for (int i = 0; i < categoryCount; i++) {
            BookNode* current = categories[i]->head;
            while (current != NULL) {
                BookNode* temp = current;
                current = current->next;
                delete temp;
            }
            delete categories[i];
        }
    }
};

int main() {
    LibrarySystem library;
    int choice;

    cout << "\n========================================\n";
    cout << "   UNIVERSITY LIBRARY MANAGEMENT SYSTEM\n";
    cout << "========================================\n";

    do {
        cout << "\n MENU:\n";
        cout << "   1. Add a New Book\n";
        cout << "   2. Issue a Specific Book (by ID)\n";
        cout << "   3. Display All Books\n";
        cout << "   4. Search for a Book\n";
        cout << "   5. Exit\n";
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        switch(choice) {
            case 1:
                library.addBook();
                break;

            case 2:
                library.issueBook();
                break;

            case 3:
                library.displayAllBooks();
                break;

            case 4:
                library.searchBook();
                break;

            case 5:
                cout << "\n Thank you for using the Library System!\n";
                cout << "   Goodbye!\n";
                break;

            default:
                cout << "\n Invalid choice! Please enter 1-5.\n";
        }
    } while (choice != 5);

    return 0;
}