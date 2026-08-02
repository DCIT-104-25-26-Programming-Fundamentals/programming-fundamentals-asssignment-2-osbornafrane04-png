// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 9
// =============================================================================
//
// TASK: Console-Based Simple Calculator
//
// Build a calculator program that runs in the console and performs basic
// arithmetic operations based on the user's input.
//
// -----------------------------------------------------------------------------
// OPERATIONS YOUR CALCULATOR MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Addition          ( + )    e.g.  10 + 3  =  13
//   2. Subtraction       ( - )    e.g.  10 - 3  =  7
//   3. Multiplication    ( * )    e.g.  10 * 3  =  30
//   4. Division          ( / )    e.g.  10 / 3  =  3.33
//   5. Modulus           ( % )    e.g.  10 % 3  =  1  (remainder)
//   6. Exponentiation    ( ^ )    e.g.  2 ^ 8   =  256
//   7. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ============================
//        SIMPLE CALCULATOR
//   ============================
//   1. Addition
//   2. Subtraction
//   3. Multiplication
//   4. Division
//   5. Modulus
//   6. Exponentiation
//   7. Quit
//   Select an operation (1-7):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Select an operation (1-7): 4
//   Enter first number : 10
//   Enter second number: 3
//   Result: 10 / 3 = 3.33
//
//   Select an operation (1-7): 4
//   Enter first number : 5
//   Enter second number: 0
//   Error: Cannot divide by zero.
//
//   Select an operation (1-7): 7
//   Goodbye!
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Each arithmetic operation MUST be written as its own function.
// - Use a loop so the calculator keeps running until the user selects Quit.
// - Division by zero must be caught and handled with a clear error message
//   (do NOT let the program crash).
// - Use fixed and setprecision(2) to display results to 2 decimal places.
// - Handle invalid menu choices gracefully.
// - For exponentiation use a loop or the pow() function from <cmath>.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

void divide(double a, double b) {
    if (b == 0) {
        cout << "Error: Cannot divide by zero.\n\n";
    } else {
        cout << "Result: " << a << " / " << b << " = " << fixed << setprecision(2) << (a / b) << "\n\n";
    }
}

void modulus(double a, double b) {
    if (static_cast<int>(b) == 0) {
        cout << "Error: Cannot divide by zero.\n\n";
    } else {
        int ia = static_cast<int>(a);
        int ib = static_cast<int>(b);
        cout << "Result: " << ia << " % " << ib << " = " << (ia % ib) << "\n\n";
    }
}

double power(double a, double b) {
    return pow(a, b);
}

void getTwoNumbers(double& a, double& b) {
    cout << "Enter first number : ";
    while (!(cin >> a)) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input. Enter first number : ";
    }
    cout << "Enter second number: ";
    while (!(cin >> b)) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input. Enter second number: ";
    }
}

int main() {
    int choice = 0;

    while (choice != 7) {
        cout << "============================\n";
        cout << "      SIMPLE CALCULATOR     \n";
        cout << "============================\n";
        cout << "1. Addition\n";
        cout << "2. Subtraction\n";
        cout << "3. Multiplication\n";
        cout << "4. Division\n";
        cout << "5. Modulus\n";
        cout << "6. Exponentiation\n";
        cout << "7. Quit\n";
        cout << "Select an operation (1-7): ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid choice. Please enter a number from 1 to 7.\n\n";
            continue;
        }

        if (choice >= 1 && choice <= 6) {
            double num1, num2;
            getTwoNumbers(num1, num2);

            switch (choice) {
                case 1:
                    cout << "Result: " << num1 << " + " << num2 << " = " << fixed << setprecision(2) << add(num1, num2) << "\n\n";
                    break;
                case 2:
                    cout << "Result: " << num1 << " - " << num2 << " = " << fixed << setprecision(2) << subtract(num1, num2) << "\n\n";
                    break;
                case 3:
                    cout << "Result: " << num1 << " * " << num2 << " = " << fixed << setprecision(2) << multiply(num1, num2) << "\n\n";
                    break;
                case 4:
                    divide(num1, num2);
                    break;
                case 5:
                    modulus(num1, num2);
                    break;
                case 6:
                    cout << "Result: " << num1 << " ^ " << num2 << " = " << fixed << setprecision(2) << power(num1, num2) << "\n\n";
                    break;
            }
            cout << resetiosflags(ios_base::fixed);
        } else if (choice == 7) {
            cout << "Goodbye!\n";
        } else {
            cout << "Invalid choice. Please enter a number from 1 to 7.\n\n";
        }
    }

    return 0;
}