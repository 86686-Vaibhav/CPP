#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Employee {
protected:
    string emp_id;
    string name;
    double salary;

public:
    Employee(string id, string n, double sal) : emp_id(id), name(n), salary(sal) {}

    virtual void display() const {
        cout << "Employee ID: " << emp_id << ", Name: " << name << ", Salary: $" << salary << endl;
    }

    virtual string getDesignation() const = 0; 
};

class Manager : public Employee {
public:
    Manager(string id, string n, double sal) : Employee(id, n, sal) {}

    void display() const override {
        cout << "Manager - ";
        Employee::display();
    }

    string getDesignation() const override {
        return "Manager";
    }
};

class Salesman : public Employee {
public:
    Salesman(string id, string n, double sal) : Employee(id, n, sal) {}

    void display() const override {
        cout << "Salesman - ";
        Employee::display();
    }

    string getDesignation() const override {
        return "Salesman";
    }
};

class SalesManager : public Employee {
public:
    SalesManager(string id, string n, double sal) : Employee(id, n, sal) {}

    void display() const override {
        cout << "Sales Manager - ";
        Employee::display();
    }

    string getDesignation() const override {
        return "SalesManager";
    }
};

int main() {
    vector<Employee*> employees;  // Vector to hold all employees
    int choice;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Accept Employee\n";
        cout << "2. Display count of employees by designation\n";
        cout << "3. Display all Managers\n";
        cout << "4. Display all Salesmen\n";
        cout << "5. Display all SalesManagers\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int empType;
            string id, name;
            double salary;

            cout << "Enter Employee ID: "; cin >> id;
            cout << "Enter Employee Name: "; cin >> name;
            cout << "Enter Employee Salary: "; cin >> salary;

            cout << "Enter 1 for Manager, 2 for Salesman, 3 for SalesManager: ";
            cin >> empType;

            if (empType == 1) {
                employees.push_back(new Manager(id, name, salary));
            } else if (empType == 2) {
                employees.push_back(new Salesman(id, name, salary));
            } else if (empType == 3) {
                employees.push_back(new SalesManager(id, name, salary));
            } else {
                cout << "Invalid employee type!" << endl;
            }

        } else if (choice == 2) {
            int managerCount = 0, salesmanCount = 0, salesManagerCount = 0;

            for (const auto& emp : employees) {
                if (emp->getDesignation() == "Manager") managerCount++;
                else if (emp->getDesignation() == "Salesman") salesmanCount++;
                else if (emp->getDesignation() == "SalesManager") salesManagerCount++;
            }

            cout << "Total Managers: " << managerCount << endl;
            cout << "Total Salesmen: " << salesmanCount << endl;
            cout << "Total SalesManagers: " << salesManagerCount << endl;

        } else if (choice == 3) {
            cout << "List of Managers:\n";
            for (const auto& emp : employees) {
                if (emp->getDesignation() == "Manager") {
                    emp->display();
                }
            }

        } else if (choice == 4) {
            cout << "List of Salesmen:\n";
            for (const auto& emp : employees) {
                if (emp->getDesignation() == "Salesman") {
                    emp->display();
                }
            }

        } else if (choice == 5) {
            cout << "List of SalesManagers:\n";
            for (const auto& emp : employees) {
                if (emp->getDesignation() == "SalesManager") {
                    emp->display();
                }
            }

        } else if (choice == 6) {
            for (auto emp : employees) {
                delete emp;  // Clean up dynamically allocated memory
            }
            employees.clear();
            cout << "Exiting program..." << endl;
            break;

        } else {
            cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}