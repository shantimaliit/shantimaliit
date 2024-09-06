#include <iostream>
#include <fstream>
#include <limits>
#include <string>
using namespace std;

// Structure to represent a student
struct Student {
    string name; 
    bool attendance;
};

// Function declaration
void registerStudents(Student* students, int numStudents);
void markAttendance(Student* students, int numStudents);
void displayAttendance(Student* students, int numStudents);
void saveStudentsAttendance(Student* students, int numStudents);

int main() {
    int numStudents;

    cout << "Attendance Checking\n";
    cout << "---------------------";

    // Input validation loop to get the number of students
    while (true) {
        cout << "\nEnter the number of students: ";

        if (cin >> numStudents) {
            // Check if there are any remaining characters in the input buffer
            if (cin.peek() == '\n') {
                break;  // Input is valid, exit loop
            }
        }
        // Invalid input, clear the error flag and discard the remaining characters
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter an integer.\n";
    }

    // Dynamically allocate an array of Student structures based on the number of students
    Student* students = new Student[numStudents];
    int choice;
    do {
        // Display the menu and get the user's choice
        cout << "\n1. Register Students\n2. Mark Attendance\n3. Display Attendance\n4. Save students attendance to a file\n5. Exit\n\nEnter your choice (1-5): ";
        // Validate the choice input
        if (cin >> choice && choice >= 1 && choice <= 5) {
            // Input is valid, execute the corresponding function
            switch (choice) {
                case 1:
                    registerStudents(students, numStudents);
                    break;
                case 2:
                    markAttendance(students, numStudents);
                    break;
                case 3:
                    displayAttendance(students, numStudents);
                    break;
                case 4:
                    saveStudentsAttendance(students, numStudents);
                    break;
                case 5:
                    cout << "Exiting program...\n";
                    break;
            }
        } else {
            // Invalid input, clear the error flag and discard the remaining characters
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number between 1 and 5.\n";
        }
    } while (choice != 5);

    // Deallocate the memory for the students array
    delete[] students;

    return 0;
}

// Function to register students' names
void registerStudents(Student* students, int numStudents) {
    cin.ignore();  // Ignore any remaining newline character from previous input

    // Prompt the user to enter the name for each student
    for (int i = 0; i < numStudents; i++) {
        cout << "\nEnter the name of student " << i+1 << ": ";
        getline(cin, students[i].name);
        students[i].attendance = false;  // Initialize attendance as false for each student
    }
}

// Function to mark attendance for each student
void markAttendance(Student* students, int numStudents) {
    // Prompt the user to mark attendance for each student
    for (int i = 0; i < numStudents; i++) {
        cout << "\nDid " << students[i].name << " attend today's class? (y or Y (yes) / n or N (no)): ";
        char choice;
        bool validInput = false;
        while (!validInput) {
            cin >> choice;

            if (cin.fail() || !(choice)) {
                // Invalid input, clear the error flag and discard the remaining characters
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter 'y or Y' for Yes or 'n or N' for No.\n";
            } else if (choice == 'y' || choice == 'Y' || choice == 'n' || choice == 'N') {
                validInput = true;
            } else {
                cout << "Invalid input. Please enter 'y or Y' for Yes or 'n or N' for No.\n";
            }
        }

        students[i].attendance = (choice == 'y' || choice == 'Y');  // Update attendance based on the user's choice
    }
}

// Function to save students' attendance to a file
void saveStudentsAttendance(Student* students, int numStudents) {
    ofstream file;
    file.open("attendance1.txt");
    if (!file) { //If the file is not saved
        cout << "Failed to open file for writing.\n";
        return;
    }
    // Write the attendance record for each student to the file
    file << "Attendance Record:\n";
    for (int i = 0; i < numStudents; i++) {
        file << "Name: " << students[i].name << endl;
        file << "Attendance: " << students[i].attendance << endl;

        if (students[i].attendance) {
            file << "Present\n";
        } else {
            file << "Absent\n";
        }
    }

    file.close();
    cout << "Students' attendance saved to a file." << endl;
}

// Function to display the attendance record
void displayAttendance(Student* students, int numStudents) {
    cout << "\nAttendance Record:\n\n";

    // Print the attendance record for each student
    for (int i = 0; i < numStudents; i++) {
        cout << students[i].name << ": ";
        if (students[i].attendance) {
            cout << "Present\n";
        } else {
            cout << "Absent\n";
        }
    }
}

