#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    char gender;
    int rollNumber;
    int marks[3];
    static int nextRollNumber;
    
public:
    Student() {
        rollNumber = nextRollNumber++;
    }

    void accept() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter gender (M/F): ";
        cin >> gender;
        cout << "Enter marks for 3 subjects: ";
        for (int i = 0; i < 3; i++) {
            cin >> marks[i];
        }
    }

    void print() const {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Gender: " << gender << endl;
        cout << "Percentage: " << calculatePercentage() << "%" << endl;
    }

    int getRollNumber() const {
        return rollNumber;
    }

    float calculatePercentage() const {
        int total = 0;
        for (int i = 0; i < 3; i++) {
            total += marks[i];
        }
        return (total / 3.0);
    }

    string getName() const {
        return name;
    }
};

int Student::nextRollNumber = 1;

int searchStudent(Student* arr[], int size, int rollNumber) {
    for (int i = 0; i < size; i++) {
        if (arr[i] != nullptr && arr[i]->getRollNumber() == rollNumber) {
            return i;
        }
    }
    return -1;
}

int main() {
    Student* arr[5] = { nullptr };
    int choice, index, rollNumber;

    while (true) {
        cout << "\n1. Accept Student\n2. Print Student\n3. Search Student\n4. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                for (int i = 0; i < 5; i++) {
                    if (arr[i] == nullptr) {
                        arr[i] = new Student();
                        arr[i]->accept();
                        break;
                    }
                }
                break;

            case 2:
                for (int i = 0; i < 5; i++) {
                    if (arr[i] != nullptr) {
                        arr[i]->print();
                    }
                }
                break;

            case 3:
                cout << "Enter roll number to search: ";
                cin >> rollNumber;
                index = searchStudent(arr, 5, rollNumber);
                if (index != -1) {
                    cout << "Student found at index " << index << endl;
                    arr[index]->print();
                } else {
                    cout << "Student not found!" << endl;
                }
                break;

            case 4:
                return 0;

            default:
                cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}