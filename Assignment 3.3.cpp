#include <iostream>
#include <string>
using namespace std;

class Address {
private:
    string building;
    string street;
    string city;
    int pin;

public:
    Address() : building(""), street(""), city(""), pin(0) {}

    
    Address(string bldg, string strt, string cty, int p) : building(bldg), street(strt), city(cty), pin(p) {}

    string getBuilding() const {
        return building;
    }

    string getStreet() const {
        return street;
    }

    string getCity() const {
        return city;
    }

    int getPin() const {
        return pin;
    }

    void setBuilding(const string& bldg) {
        building = bldg;
    }

    void setStreet(const string& strt) {
        street = strt;
    }

    void setCity(const string& cty) {
        city = cty;
    }

    void setPin(int p) {
        pin = p;
    }

    void accept() {
        cout << "Enter building: ";
        getline(cin, building);
        cout << "Enter street: ";
        getline(cin, street);
        cout << "Enter city: ";
        getline(cin, city);
        cout << "Enter pin: ";
        cin >> pin;
        cin.ignore(); 
    }

    
    void display() const {
        cout << "Building: " << building << endl;
        cout << "Street: " << street << endl;
        cout << "City: " << city << endl;
        cout << "PIN: " << pin << endl;
    }
};

int main() {
    Address addr1;

    cout << "Enter details for Address 1:" << endl;
    addr1.accept();

    cout << "\nAddress 1 details:" << endl;
    addr1.display();

    Address addr2("Sunshine Apartments", "MG Road", "Mumbai", 400001);

    cout << "\nAddress 2 details (using parameterized constructor):" << endl;
    addr2.display();

    addr2.setBuilding("Reddison Blue");
    addr2.setStreet("Bhanwarkuwa");
    addr2.setCity("Indore");
    addr2.setPin(452001);

    cout << "\nModified Address 2 details:" << endl;
    addr2.display();

    return 0;
}