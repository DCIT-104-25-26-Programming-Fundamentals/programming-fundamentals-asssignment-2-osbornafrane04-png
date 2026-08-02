#include <iostream>
using namespace std;

// Function to check if a number is prime
bool isPrime(int n) {
    // Requirement: Numbers less than 2 are not prime
    if (n < 2) {
        return false;
    }

    // Check divisors from 2 up to sqrt(n)
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false; // Found a factor, so it's composite
        }
    }

    return true; // No factors found, it's prime
}

int main() {
    int number;

    cout << "Enter a number: ";
    cin >> number;

    if (isPrime(number)) {
        cout << number << " is a prime number." << endl;
    } else {
        cout << number << " is NOT a prime number." << endl;
    }

    return 0;
}