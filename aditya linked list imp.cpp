#include <iostream>
using namespace std;

// Node structure to store row, column, value, and next node pointer
struct Node {
    int row, col, value;
    Node* next;
};

// Function to create a new node
Node* createNode(int row, int col, int value) {
    Node* newNode = new Node();
    newNode->row = row;
    newNode->col = col;
    newNode->value = value;
    newNode->next = nullptr;
    return newNode;
}

// Function to insert a node into the linked list
void insertNode(Node*& head, int row, int col, int value) {
    Node* newNode = createNode(row, col, value);
    if (!head) {
        head = newNode;  // Insert as the first node if the list is empty
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;  // Traverse to the end of the list
        }
        temp->next = newNode;  // Insert new node at the end
    }
}

// Function to display the linked list
void displayList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << "Row: " << temp->row 
             << ", Column: " << temp->col 
             << ", Value: " << temp->value 
             << ", Next Node Address: " << temp->next << endl;
        temp = temp->next;  // Move to the next node
    }
}

int main() {
    Node* head = nullptr;
    int rows, cols, val;

    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    cout << "Enter the matrix values :\n";
    
    // Loop through the matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Value at (" << i << ", " << j << "): ";
            cin >> val;

            if (val != 0) {  // Only insert non-zero values
                insertNode(head, i, j, val);
            }
        }
    }

    // Display the linked list
    cout << "\nSparse Matrix in Linked List Representation:\n";
    if (head == nullptr) {
        cout << "The matrix has no non-zero elements." << endl;
    } else {
        displayList(head);
    }

    return 0;
}



