// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 8
// =============================================================================
//
// TASK: Student Record Management System
//
// Build a console-based program that stores and manages student information.
// Use a struct to represent each student record containing:
//
//   - name   : the student's full name  (string)
//   - id     : a unique student ID number (int, e.g. 20240001)
//   - scores : a list of scores from multiple assessments (vector<double>)
//
// -----------------------------------------------------------------------------
// FEATURES YOUR PROGRAM MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Add a Student
//      - Ask the user to enter the student's name and ID.
//      - Ask how many scores to enter, then collect each score one by one.
//      - Save the student record and confirm it was added.
//
//   2. Display All Students
//      - Print a formatted table showing every student's:
//          Name, ID, individual scores, and their average score.
//      - If no students have been added yet, print a message saying so.
//
//   3. Calculate Average Score for a Specific Student
//      - Ask the user to enter a student ID.
//      - Find the student and print their average score.
//      - If the ID is not found, print an error message.
//
//   4. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ================================
//      STUDENT RECORD SYSTEM MENU
//   ================================
//   1. Add student
//   2. Display all students
//   3. Calculate average score
//   4. Quit
//   Enter your choice (1-4):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Enter your choice (1-4): 1
//   Student name: Alice Mensah
//   Student ID: 20240001
//   How many scores? 3
//   Enter score 1: 78
//   Enter score 2: 85
//   Enter score 3: 90
//   Student "Alice Mensah" added successfully.
//
//   Enter your choice (1-4): 3
//   Enter student ID: 20240001
//   Alice Mensah's average score: 84.33
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Define a struct called Student (see scaffold below).
// - Store all records in a vector<Student>.
// - Average scores must be rounded to 2 decimal places (use setprecision(2)).
// - Each feature MUST be in its own function.
// - Handle invalid menu choices and missing student IDs gracefully.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

struct Student {
    string name;
    int id;
    vector<double> scores;
};

double calculateAverage(const vector<double>& scores) {
    if (scores.empty()) return 0.0;
    double sum = 0.0;
    for (double score : scores) {
        sum += score;
    }
    return sum / scores.size();
}

void addStudent(vector<Student>& students) {
    Student s;
    cout << "Student name: ";
    getline(cin >> ws, s.name);
    
    cout << "Student ID: ";
    while (!(cin >> s.id)) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid ID. Please enter a valid number: ";
    }

    int count;
    cout << "How many scores? ";
    while (!(cin >> count) || count < 0) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Please enter a valid positive number: ";
    }

    for (int i = 1; i <= count; ++i) {
        double score;
        cout << "Enter score " << i << ": ";
        while (!(cin >> score)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid score. Enter score " << i << ": ";
        }
        s.scores.push_back(score);
    }

    students.push_back(s);
    cout << "Student \"" << s.name << "\" added successfully.\n\n";
}

void displayAllStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No student records available.\n\n";
        return;
    }

    cout << "\n------------------------------------------------------------------\n";
    cout << left << setw(20) << "Name" 
         << setw(12) << "ID" 
         << setw(20) << "Scores" 
         << setw(10) << "Average" << "\n";
    cout << "------------------------------------------------------------------\n";

    for (const auto& s : students) {
        cout << left << setw(20) << s.name 
             << setw(12) << s.id;

        string scoreList = "";
        for (size_t i = 0; i < s.scores.size(); ++i) {
            scoreList += to_string((int)s.scores[i]);
            if (i < s.scores.size() - 1) scoreList += ", ";
        }
        
        cout << setw(20) << scoreList 
             << fixed << setprecision(2) << calculateAverage(s.scores) << "\n";
    }
    cout << "------------------------------------------------------------------\n\n";
}

void calculateStudentAverage(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No student records available.\n\n";
        return;
    }

    int searchId;
    cout << "Enter student ID: ";
    while (!(cin >> searchId)) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid ID. Please enter a number: ";
    }

    bool found = false;
    for (const auto& s : students) {
        if (s.id == searchId) {
            double avg = calculateAverage(s.scores);
            cout << s.name << "'s average score: " 
                 << fixed << setprecision(2) << avg << "\n\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Error: Student with ID " << searchId << " not found.\n\n";
    }
}

int main() {
    vector<Student> students;
    int choice = 0;

    while (choice != 4) {
        cout << "================================\n";
        cout << "   STUDENT RECORD SYSTEM MENU   \n";
        cout << "================================\n";
        cout << "1. Add student\n";
        cout << "2. Display all students\n";
        cout << "3. Calculate average score\n";
        cout << "4. Quit\n";
        cout << "Enter your choice (1-4): ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid choice. Please enter a number from 1 to 4.\n\n";
            continue;
        }

        switch (choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                displayAllStudents(students);
                break;
            case 3:
                calculateStudentAverage(students);
                break;
            case 4:
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please enter a number from 1 to 4.\n\n";
                break;
        }
    }

    return 0;
}