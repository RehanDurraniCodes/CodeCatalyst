

/*  56. library managment using doubly linklist
   313. switch b/w stack and queue mode
   452. Orders store using BST
  */















/* library managment using doubly linklist
#include <iostream>
#include <string>
using namespace std;

struct Book {
    int bookID;
    string title;
    string author;
    Book* next;
    Book* prev;

    Book(int id, string t, string a) : bookID(id), title(t), author(a), next(NULL), prev(NULL) {}
};

class Library {
private:
    Book* head;
    Book* tail;

public:
    Library() : head(NULL), tail(NULL) {}

    // Add a new book at the beginning
    void addBookAtBeginning(int id, string title, string author) {
        Book* newBook = new Book(id, title, author);
        if (head == NULL) {
            head = tail = newBook;
        } else {
            newBook->next = head;
            head->prev = newBook;
            head = newBook;
        }
        cout << "Book added at the beginning.\n";
        
    }

    // Add a new book at the end
    void addBookAtEnd(int id, string title, string author) {
        Book* newBook = new Book(id, title, author);
        if (tail == NULL) {
            head = tail = newBook;
        } else {
            tail->next = newBook;
            newBook->prev = tail;
            tail = newBook;
        }
        cout << "Book added at the end.\n";
    }

    // Add a new book at a specific position
    void addBookAtPosition(int position, int id, string title, string author) {
        if (position <= 0) {
            cout << "Invalid position!\n";
            return;
        }

        if (position == 1) {
            addBookAtBeginning(id, title, author);
            return;
        }

        Book* newBook = new Book(id, title, author);
        Book* current = head;
        int index = 1;

        while (current != NULL && index < position - 1) {
            current = current->next;
            index++;
        }

        if (current == NULL) {
            cout << "Position out of bounds. Adding at the end.\n";
            addBookAtEnd(id, title, author);
        } else {
            newBook->next = current->next;
            if (current->next != NULL) {
                current->next->prev = newBook;
            } else {
                tail = newBook;
            }
            current->next = newBook;
            newBook->prev = current;
            cout << "Book added at position " << position << ".\n";
        }
    }

    // Delete a book by Book ID
    void deleteBookByID(int id) {
        if (head == NULL) {
            cout << "No books to delete.\n";
            return;
        }

        Book* current = head;

        while (current != NULL && current->bookID != id) {
            current = current->next;
        }

        if (current == NULL) {
            cout << "Book with ID " << id << " not found.\n";
            return;
        }

        if (current == head) {
            head = head->next;
            if (head != NULL) {
                head->prev = NULL;
            } else {
                tail = NULL;
            }
        } else if (current == tail) {
            tail = tail->prev;
            tail->next = NULL;
        } else {
            current->prev->next = current->next;
            current->next->prev = current->prev;
        }

        delete current;
        cout << "Book with ID " << id << " deleted.\n";
    }

    // Display books in forward order
    void displayBooksForward() {
        if (head == NULL) {
            cout << "No books in the library.\n";
            return;
        }

        Book* current = head;
        cout << "Books in forward order:\n";
        while (current != NULL) {
            cout << "ID: " << current->bookID << ", Title: " << current->title << ", Author: " << current->author << endl;
            current = current->next;
        }
    }

    // Display books in reverse order
    void displayBooksReverse() {
        if (tail == NULL) {
            cout << "No books in the library.\n";
            return;
        }

        Book* current = tail;
        cout << "Books in reverse order:\n";
        while (current != NULL) {
            cout << "ID: " << current->bookID << ", Title: " << current->title << ", Author: " << current->author << endl;
            current = current->prev;
        }
    }

    // Reverse the entire list
    void reverseList() {
        if (head == NULL) {
            cout << "No books to reverse.\n";
            return;
        }

        Book* current = head;
        Book* temp = NULL;

        while (current != NULL) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }

        temp = head;
        head = tail;
        tail = temp;

        cout << "List reversed.\n";
    }
};

int main() {
    Library library;
    int choice, id, position;
    string title, author;

    while (true) {
        cout << "\nLibrary Menu:\n";
        cout << "1. Add book at beginning\n";
        cout << "2. Add book at end\n";
        cout << "3. Add book at position\n";
        cout << "4. Delete book by ID\n";
        cout << "5. Display books (forward)\n";
        cout << "6. Display books (reverse)\n";
        cout << "7. Reverse the list\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Book ID, Title, and Author: ";
                cin >> id;
                cin.ignore();
                getline(cin, title);
                getline(cin, author);
                library.addBookAtBeginning(id, title, author);
                break;

            case 2:
                cout << "Enter Book ID, Title, and Author: ";
                cin >> id;
                cin.ignore();
                getline(cin, title);
                getline(cin, author);
                library.addBookAtEnd(id, title, author);
                break;

            case 3:
                cout << "Enter position, Book ID, Title, and Author: ";
                cin >> position >> id;
                cin.ignore();
                getline(cin, title);
                getline(cin, author);
                library.addBookAtPosition(position, id, title, author);
                break;

            case 4:
                cout << "Enter Book ID to delete: ";
                cin >> id;
                library.deleteBookByID(id);
                break;

            case 5:
                library.displayBooksForward();
                break;

            case 6:
                library.displayBooksReverse();
                break;

            case 7:
                library.reverseList();
                break;

            case 8:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}*/



/* switch b/w stack and queue mode 
#include <iostream>
using namespace std;

class Warehouse {
private:
    struct Node {
        string data;
        Node* next;
        Node(const string& item) : data(item), next(NULL) {}
    };

    Node* head;  // Head of the list
    Node* tail;  // Tail of the list
    bool isStackMode; // true for stack mode, false for queue mode

public:
    Warehouse() : head(NULL), tail(NULL), isStackMode(true) {}

    void switchMode() {
        isStackMode = !isStackMode;
        cout << "Switched to " << (isStackMode ? "Stack Mode (LIFO)" : "Queue Mode (FIFO)") << ".\n";
    }

    void addItem(const string& item) {
        Node* newNode = new Node(item);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        cout << "Item \"" << item << "\" added to the inventory.\n";
    }

    void processItem() {
        if (head == NULL) {
            cout << "No items to process.\n";
            return;
        }

        if (isStackMode) {
            // Stack Mode: Remove from the end
            if (head == tail) {
                cout << "Processed item: \"" << head->data << "\".\n";
                delete head;
                head = tail = NULL;
            } else {
                Node* current = head;
                while (current->next != tail) {
                    current = current->next;
                }
                cout << "Processed item: \"" << tail->data << "\".\n";
                delete tail;
                tail = current;
                tail->next = NULL;
            }
        } else {
            // Queue Mode: Remove from the front
            Node* temp = head;
            cout << "Processed item: \"" << head->data << "\".\n";
            head = head->next;
            if (head == NULL) {
                tail = NULL;
            }
            delete temp;
        }
    }

    void displayInventory() const {
        if (head == NULL) {
            cout << "Inventory is empty.\n";
            return;
        }

        cout << "Current Inventory: ";
        Node* current = head;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    bool isEmpty() const {
        return head == NULL;
    }

    ~Warehouse() {
        while (head != NULL) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    Warehouse warehouse;

    // Simulate operations
    cout << "Simulating Warehouse Operations:\n";

    // Add 5 items (stack mode)
    warehouse.addItem("Item1");
    warehouse.addItem("Item2");
    warehouse.addItem("Item3");
    warehouse.addItem("Item4");
    warehouse.addItem("Item5");
    warehouse.displayInventory();

    // Switch to queue mode and process 2 items
    warehouse.switchMode();
    warehouse.processItem();
    warehouse.processItem();
    warehouse.displayInventory();

    // Switch back to stack mode and add 3 items
    warehouse.switchMode();
    warehouse.addItem("Item6");
    warehouse.addItem("Item7");
    warehouse.addItem("Item8");
    warehouse.displayInventory();

    // Switch to queue mode and process remaining items
    warehouse.switchMode();
    while (!warehouse.isEmpty()) {
        warehouse.processItem();
    }

    return 0;
}*/





/*Orders store using BST
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

struct Order {
    int orderID;
    string customerName;
    double totalAmount;
    Order* left;
    Order* right;

    Order(int id, string name, double amount) : orderID(id), customerName(name), totalAmount(amount), left(NULL), right(NULL) {}
};

class BST {
private:
    Order* root;

    // Helper function to insert a new order
    Order* insert(Order* node, int id, string name, double amount) {
        if (node == NULL) {
            return new Order(id, name, amount);
        }
        if (id < node->orderID) {
            node->left = insert(node->left, id, name, amount);
        } else {
            node->right = insert(node->right, id, name, amount);
        }
        return node;
    }

    // Helper function to find the minimum value node
    Order* findMin(Order* node) {
        while (node->left != NULL) {
            node = node->left;
        }
        return node;
    }

    // Helper function to delete a node
    Order* deleteOrder(Order* node, int id) {
        if (node == NULL) return NULL;

        if (id < node->orderID) {
            node->left = deleteOrder(node->left, id);
        } else if (id > node->orderID) {
            node->right = deleteOrder(node->right, id);
        } else {
            // Node with one or no child
            if (node->left == NULL) {
                Order* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == NULL) {
                Order* temp = node->left;
                delete node;
                return temp;
            }
            // Node with two children
            Order* temp = findMin(node->right);
            node->orderID = temp->orderID;
            node->customerName = temp->customerName;
            node->totalAmount = temp->totalAmount;
            node->right = deleteOrder(node->right, temp->orderID);
        }
        return node;
    }

    // Helper function to calculate the height of the BST
    int calculateHeight(Order* node) {
        if (node == NULL) return 0;
        return 1 + max(calculateHeight(node->left), calculateHeight(node->right));
    }

public:
    BST() : root(NULL) {}

    void insert(int id, string name, double amount) {
        root = insert(root, id, name, amount);
    }

    void deleteOrder(int id) {
        root = deleteOrder(root, id);
    }

    void searchOrder(int id) {
        Order* parent = NULL;
        Order* current = root;

        while (current != NULL && current->orderID != id) {
            parent = current;
            if (id < current->orderID) {
                current = current->left;
            } else {
                current = current->right;
            }
        }

        if (current == NULL) {
            cout << "Order ID " << id << " not found.\n";
        } else if (parent == NULL) {
            cout << "Order ID " << id << " is the root.\n";
        } else {
            cout << "Order ID " << id << " is found, parent Order ID: " << parent->orderID << ".\n";
        }
    }

    void iterativeInOrderTraversal() {
        if (root == NULL) {
            cout << "No orders available.\n";
            return;
        }

        stack<Order*> s;
        Order* current = root;

        cout << "Orders in ascending order of Order IDs:\n";
        while (current != NULL || !s.empty()) {
            while (current != NULL) {
                s.push(current);
                current = current->left;
            }
            current = s.top();
            s.pop();
            cout << "Order ID: " << current->orderID
                 << ", Customer Name: " << current->customerName
                 << ", Total Amount: $" << current->totalAmount << "\n";
            current = current->right;
        }
    }

    void calculateHeight() {
        cout << "Height of the BST: " << calculateHeight(root) << "\n";
    }
};

int main() {
    BST bst;

    // Insert 10 orders
    bst.insert(50, "Ali", 120.5);
    bst.insert(30, "Bilal", 75.0);
    bst.insert(70, "sajid", 200.0);
    bst.insert(20, "Danial", 50.0);
    bst.insert(40, "ahmed", 90.0);
    bst.insert(60, "Fatima", 150.0);
    bst.insert(80, "jigra", 300.0);
    bst.insert(10, "Hina", 30.0);
    bst.insert(35, "Imran", 85.0);
    bst.insert(45, "Junaid", 100.0);

    // Search for a specific order
    bst.searchOrder(40);

    // Delete 2 orders
    bst.deleteOrder(20);
    bst.deleteOrder(70);

    // Display all remaining orders
    bst.iterativeInOrderTraversal();

    // Calculate the height of the BST
    bst.calculateHeight();

    return 0;
}
*/



