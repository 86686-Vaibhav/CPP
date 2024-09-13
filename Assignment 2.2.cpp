#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    int rollNo;
    string name;
    float marks;

public:
    void initStudent() {
        rollNo = 0;
        name = "";
        marks = 0.0;
    }

    void printStudentOnConsole() {
        cout << "\nStudent Details:\n";
        cout << "Roll No: " << rollNo << endl;
        cout << "Name: " << name << endl;
        cout << "Marks: " << marks << endl;
    }
    void acceptStudentFromConsole() {
        cout << "\nEnter Roll No: ";
        cin >> rollNo;
        cin.ignore(); 
        
        cout << "Enter Name: ";
        getline(cin, name);
        
        cout << "Enter Marks: ";
        cin >> marks;
    }
};

int main() {
    Student student;
    int choice;

    do {
      
        cout << "\nMenu:\n";
        cout << "1. Initialize Student\n";
        cout << "2. Enter Student Details\n";
        cout << "3. Display Student Details\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            student.initStudent();
            cout << "Student initialized with default values.\n";
            break;
        case 2:
            student.acceptStudentFromConsole();
            break;
        case 3:
            student.printStudentOnConsole();
            break;
        case 4:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
