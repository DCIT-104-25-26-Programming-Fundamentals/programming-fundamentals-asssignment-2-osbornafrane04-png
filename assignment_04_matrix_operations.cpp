#include <iostream>
#include <iomanip>
using namespace std;

void displayMatrix(const int matrix[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(6) << matrix[i][j];
        }
        cout << endl;
    }
}

void inputMatrix(int matrix[10][10], int rows, int cols, const string& name) {
    cout << "Enter elements for Matrix " << name << ":" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

void transposeMatrix(const int input[10][10], int output[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            output[j][i] = input[i][j];
        }
    }
}

void addMatrices(const int A[10][10], const int B[10][10], int result[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

void multiplyMatrices(const int A[10][10], const int B[10][10], int result[10][10], int m, int n, int p) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            result[i][j] = 0;
            for (int k = 0; k < n; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int choice;
    cout << "--- Matrix Operations ---" << endl;
    cout << "1. Transpose a Matrix" << endl;
    cout << "2. Add Two Matrices" << endl;
    cout << "3. Multiply Two Matrices" << endl;
    cout << "Enter choice (1-3): ";
    cin >> choice;

    if (choice == 1) {
        int r, c;
        cout << "Enter number of rows: ";
        cin >> r;
        cout << "Enter number of columns: ";
        cin >> c;

        if (r <= 0 || r > 10 || c <= 0 || c > 10) {
            cout << "Error: Dimensions must be between 1 and 10." << endl;
            return 1;
        }

        int A[10][10], T[10][10];
        inputMatrix(A, r, c, "A");
        transposeMatrix(A, T, r, c);

        cout << "\nOriginal Matrix:" << endl;
        displayMatrix(A, r, c);
        cout << "\nTransposed Matrix:" << endl;
        displayMatrix(T, c, r);

    } else if (choice == 2) {
        int r, c;
        cout << "Enter number of rows: ";
        cin >> r;
        cout << "Enter number of columns: ";
        cin >> c;

        if (r <= 0 || r > 10 || c <= 0 || c > 10) {
            cout << "Error: Dimensions must be between 1 and 10." << endl;
            return 1;
        }

        int A[10][10], B[10][10], Sum[10][10];
        inputMatrix(A, r, c, "A");
        inputMatrix(B, r, c, "B");

        addMatrices(A, B, Sum, r, c);

        cout << "\nMatrix A:" << endl;
        displayMatrix(A, r, c);
        cout << "\nMatrix B:" << endl;
        displayMatrix(B, r, c);
        cout << "\nSum (A + B):" << endl;
        displayMatrix(Sum, r, c);

    } else if (choice == 3) {
        int m, n, p_cols;
        cout << "Enter rows for Matrix A: ";
        cin >> m;
        cout << "Enter columns for Matrix A (and rows for Matrix B): ";
        cin >> n;
        cout << "Enter columns for Matrix B: ";
        cin >> p_cols;

        if (m <= 0 || m > 10 || n <= 0 || n > 10 || p_cols <= 0 || p_cols > 10) {
            cout << "Error: Dimensions must be between 1 and 10." << endl;
            return 1;
        }

        int A[10][10], B[10][10], Product[10][10];
        inputMatrix(A, m, n, "A");
        inputMatrix(B, n, p_cols, "B");

        multiplyMatrices(A, B, Product, m, n, p_cols);

        cout << "\nMatrix A:" << endl;
        displayMatrix(A, m, n);
        cout << "\nMatrix B:" << endl;
        displayMatrix(B, n, p_cols);
        cout << "\nProduct (A x B):" << endl;
        displayMatrix(Product, m, p_cols);

    } else {
        cout << "Invalid choice." << endl;
    }

    return 0;
}