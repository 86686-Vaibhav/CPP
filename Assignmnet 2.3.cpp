#include <iostream>
#include <string>
using namespace std;

namespace NStudent {
    class Student {
    private:
        int rollNo;
        string name;
        float marks;

    public:
        // Constructor to initialize with default values
        void initStudent() {
            rollNo = 0;
            name = "";
            marks = 0.0;
        }

        // Function to accept student details from the console
        void acceptStudentFromConsole() {
            cout << "Enter Roll No: ";
            cin >> rollNo;
            cin.ignore();  // To consume the newline character after rollNo input
            cout << "Enter Name: ";
            getline(cin, name);
            cout << "Enter Marks: ";
            cin >> marks;
        }

        // Function to print student details on the console
        void printStudentOnConsole() const {
            cout << "Roll No: " << rollNo << endl;
            cout << "Name: " << name << endl;
            cout << "Marks: " << marks << endl;
        }
    };
}

int main() {
    // Create an object of Student inside the NStudent namespace
    NStudent::Student student;

    // Perform student details acceptance
    student.acceptStudentFromConsole();

    // Display student details
    cout << "\nStudent Details:\n";
    student.printStudentOnConsole();

    return 0;
}