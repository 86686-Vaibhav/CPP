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
        void initStudent() {
            rollNo = 0;
            name = "";
            marks = 0.0;
        }
        void acceptStudentFromConsole() {
            cout << "Enter Roll No: ";
            cin >> rollNo;
            cin.ignore();  
            cout << "Enter Name: ";
            getline(cin, name);
            cout << "Enter Marks: ";
            cin >> marks;
        }

        void printStudentOnConsole() const {
            cout << "Roll No: " << rollNo << endl;
            cout << "Name: " << name << endl;
            cout << "Marks: " << marks << endl;
        }
    };
}

int main() {
    NStudent::Student student;

    student.acceptStudentFromConsole();

    cout << "\nStudent Details:\n";
    student.printStudentOnConsole();

    return 0;
}