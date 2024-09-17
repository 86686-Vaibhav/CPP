#include <iostream>
#include <string>
using namespace std;

class Date {
public:
    int day, month, year;

    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    void display() const {
        printf("%02d/%02d/%04d\n", day, month, year);
    }
};

class Person {
public:
    string name;
    string address;
    Date birthdate;

    Person(string n, string a, Date b) : name(n), address(a), birthdate(b) {}

    void display() const {
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Birthdate: ";
        birthdate.display();
    }
};

int main() {
    Date birthdate(11, 12, 2001);
    Person person("Vaibhav ", "Indore", birthdate);

    person.display();

    return 0;
}