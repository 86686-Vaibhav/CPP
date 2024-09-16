#include <iostream>
using namespace std;

class Box {
private:
    double length, width, height;

public:
    Box() {
        length = 1;
        width = 1;
        height = 1;
    }


    Box(double side) {
        length = side;
        width = side;
        height = side;
    }

    Box(double l, double w, double h) {
        length = l;
        width = w;
        height = h;
    }
    double calculateVolume() {
        return length * width * height;
    }
};

void menu() {
    int choice;
    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Calculate Volume with default values\n";
        cout << "2. Calculate Volume with length, breadth, and height with the same value\n";
        cout << "3. Calculate Volume with different length, breadth, and height values\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            Box box;
            cout << "Volume of the box with default values: " << box.calculateVolume() << endl;

        } else if (choice == 2) {
            double value;
            cout << "Enter the value for length, width, and height: ";
            cin >> value;
            Box box(value);
            cout << "Volume of the box with same values for all dimensions: " << box.calculateVolume() << endl;

        } else if (choice == 3) {
            double length, width, height;
            cout << "Enter the length of the box: ";
            cin >> length;
            cout << "Enter the width of the box: ";
            cin >> width;
            cout << "Enter the height of the box: ";
            cin >> height;
            Box box(length, width, height);
            cout << "Volume of the box with different values: " << box.calculateVolume() << endl;

        } else if (choice == 4) {
            cout << "Exiting the program...\n";
            break;

        } else {
            cout << "Invalid choice, please try again.\n";
        }
    }
}

int main() {
    menu();
    return 0;
}