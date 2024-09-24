#include <iostream>
#include <string>

using namespace std;

class Employee {
public:
    string emp_id;
    string name;
    double salary;

    Employee(string id, string n, double sal) : emp_id(id), name(n), salary(sal) {}

    void displayEmployee() const {
        cout << "Employee ID: " << emp_id << ", Name: " << name << ", Salary: " << salary << endl;
    }
};

class Manager : public Employee {
public:
    string department;

    Manager(string id, string n, double sal, string dept) : Employee(id, n, sal), department(dept) {}

    void displayManager() const {
        displayEmployee();
        cout << "Department: " << department << endl;
    }
};

class Salesman : public Employee {
public:
    double commission;

    Salesman(string id, string n, double sal, double comm) : Employee(id, n, sal), commission(comm) {}

    void displaySalesman() const {
        displayEmployee();
        cout << "Commission: " << commission << endl;
    }
};

int main() {
    Employee emp("E001", "Nimra", 50000);
    emp.displayEmployee();

    Manager mgr("M002", "Omkar", 70000, "SDE");
    mgr.displayManager();

    Salesman sls("S003", "Priyanka", 45000, 3000);
    sls.displaySalesman();

    return 0;
}