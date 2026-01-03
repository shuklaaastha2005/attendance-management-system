#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    int choice;
    string name;
    int roll;

    do {
        cout << "\n--- Attendance Management System ---\n";
        cout << "1. Add Student\n";
        cout << "2. View Students\n";
        cout << "3. Exit\n";
        cout << "4. Attendance Summary\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            ofstream file("students.txt", ios::app);

            cout << "Enter student name: ";
            cin.ignore();
            getline(cin, name);

            cout << "Enter roll number: ";
            cin >> roll;

            file << roll << " " << name << endl;
            file.close();

            cout << "Student added successfully!\n";
        }

        else if (choice == 2) {
            ifstream file("students.txt");

            cout << "\nRoll No  Name\n";
            while (file >> roll) {
                file.ignore();
                getline(file, name);
                cout << roll << "      " << name << endl;
            }

            file.close();
        }

        else if (choice == 4) {
            ifstream file("students.txt");
            int count = 0;

            while (file >> roll) {
                file.ignore();
                getline(file, name);
                count++;
            }

            file.close();

            cout << "\n--- Attendance Summary ---\n";
            cout << "Total Students Recorded: " << count << endl;
        }

        else if (choice == 3) {
            cout << "Exiting program...\n";
        }

        else {
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 3);

    return 0;
}
