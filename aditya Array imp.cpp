#include <iostream>
#include <vector>

using namespace std;

// Structure to represent non-zero elements in the sparse matrix
struct Element {
    int row;
    int col;
    int value;
};

// Function to compute 1D index from 2D coordinates
int getLinearIndex(int row, int col, int cols) {
    return row * cols + col;
}

int main() {
    int m, n, numNonZero = 0;
    
    // Input the matrix dimensions
    cout << "Enter number of rows in the matrix: ";
    cin >> m;
    cout << "Enter number of columns in the matrix: ";
    cin >> n;

    vector<Element> nonZeroElements; // Vector to store non-zero elements

    // Input the matrix elements
    cout << "Enter the matrix elements row by row:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int value;
            cout << "Enter element at Row " << i << " Column " << j << ": ";
            cin >> value;

            // Store only non-zero elements
            if (value != 0) {
                nonZeroElements.push_back({i, j, value});
                numNonZero++;
            }
        }
    }

    // Display the non-zero elements in tabular format
    cout << "\nSparse Matrix Representation (Non-zero elements only):\n";
    cout << "| Row | Column | Value |\n";
    cout << "|-----|--------|-------|\n";
    for (const auto& element : nonZeroElements) {
        cout << "|  " << element.row << "  |   " << element.col << "    |   " << element.value << "   |\n";
    }

    return 0;
}


