#include <iostream>
#include <fstream>
#include <string>
#include <limits>

using namespace std;

int main() {
    int choice;
    string name;
    int roll;

    while (true) {
        cout << "\n--- Attendance Management System ---\n";
        cout << "1. Add Student\n";
        cout << "2. View Students\n";
        cout << "3. Exit\n";
        cout << "4. Attendance Summary\n";
        cout << "Enter your choice (number only): ";

        // 🔴 INPUT VALIDATION FOR MENU
        if (!(cin >> choice)) {
            cout << "❌ Invalid input. Enter numbers only.\n";
            cin.clear(); // reset cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue; // restart loop safely
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // ➤ ADD STUDENT
        if (choice == 1) {
            ofstream file("students.txt", ios::app);

            cout << "Enter student name: ";
            getline(cin, name);

            cout << "Enter roll number: ";
            while (!(cin >> roll)) {
                cout << "❌ Enter a valid roll number: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            file << roll << " " << name << endl;
            file.close();

            cout << "✅ Student added successfully!\n";
        }

        // ➤ VIEW STUDENTS
        else if (choice == 2) {
            ifstream file("students.txt");

            if (!file) {
                cout << "No students found.\n";
            } else {
                cout << "\nRoll No   Name\n";
                while (file >> roll) {
                    file.ignore();
                    getline(file, name);
                    cout << roll << "       " << name << endl;
                }
                file.close();
            }
        }

        // ➤ SUMMARY
        else if (choice == 4) {
            ifstream file("students.txt");
            int count = 0;

            while (file >> roll) {
                file.ignore();
                getline(file, name);
                count++;
            }
            file.close();

            cout << "Total students recorded: " << count << endl;
        }

        // ➤ EXIT
        else if (choice == 3) {
            cout << "Exiting program...\n";
            break;
        }

        else {
            cout << "❌ Invalid option. Choose 1–4 only.\n";
        }
    }

    return 0;
}
