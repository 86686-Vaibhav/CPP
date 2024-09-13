#include <iostream>
using namespace std;
struct Date {
    int day;
    int month;
    int year;
};

class DateClass {
private:
    Date date;  

public:

    void initDate() {
        date.day = 1;
        date.month = 1;
        date.year = 1900;
    }

    void acceptDateFromConsole() {
        cout << "Enter day: ";
        cin >> date.day;
        cout << "Enter month: ";
        cin >> date.month;
        cout << "Enter year: ";
        cin >> date.year;
    }

    
    void printDateOnConsole() const {
        cout << "Date: " << date.day << "/" << date.month << "/" << date.year << endl;
    }

 
    bool isLeapYear() const {
        if ((date.year % 4 == 0 && date.year % 100 != 0) || (date.year % 400 == 0))
            return true;
        return false;
    }

    
    void menu() {
        int choice;
        do {
            cout << "\n--- Date Menu ---\n";
            cout << "1. Initialize Date\n";
            cout << "2. Enter Date\n";
            cout << "3. Print Date\n";
            cout << "4. Check Leap Year\n";
            cout << "5. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    initDate();
                    cout << "Date initialized to default values (1, 1, 1900).\n";
                    break;
                case 2:
                    acceptDateFromConsole();
                    break;
                case 3:
                    printDateOnConsole();
                    break;
                case 4:
                    if (isLeapYear())
                        cout << date.year << " is a leap year.\n";
                    else
                        cout << date.year << " is not a leap year.\n";
                    break;
                case 5:
                    cout << "Exiting program...\n";
                    break;
                default:
                    cout << "Invalid choice! Please try again.\n";
            }
        } while (choice != 5);
    }
};

int main() {
    DateClass dateObj;  
    dateObj.menu();     
    return 0;
}