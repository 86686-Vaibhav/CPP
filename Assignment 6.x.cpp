#include <iostream>
#include <string>

using namespace std;

class Product {
public:
    string id;
    string title;
    double price;

    Product(string i, string t, double p) : id(i), title(t), price(p) {}

    virtual double calculatePrice() = 0;

    virtual void display() const = 0;

    virtual ~Product() {}
};

class Book : public Product {
public:
    string author;

    Book(string i, string t, string a, double p) : Product(i, t, p), author(a) {}

    double calculatePrice() override {
        return price * 0.90;
    }

    void display() const override {
        cout << "Book - ID: " << id << ", Title: " << title << ", Author: " << author << ", Price: $" << price << endl;
    }
};

class Tape : public Product {
public:
    string artist;

    Tape(string i, string t, string ar, double p) : Product(i, t, p), artist(ar) {}

    double calculatePrice() override {
        return price * 0.95;
    }

    void display() const override {
        cout << "Tape - ID: " << id << ", Title: " << title << ", Artist: " << artist << ", Price: $" << price << endl;
    }
};

int main() {
    Product* arr[3];

    int choice;
    for (int i = 0; i < 3; i++) {
        cout << "Enter 1 to add Book or 2 to add Tape: ";
        cin >> choice;

        if (choice == 1) {
            string id, title, author;
            double price;
            cout << "Enter Book ID: "; cin >> id;
            cout << "Enter Book Title: "; cin >> title;
            cout << "Enter Book Author: "; cin >> author;
            cout << "Enter Book Price: "; cin >> price;
            arr[i] = new Book(id, title, author, price);
        } else if (choice == 2) {
            string id, title, artist;
            double price;
            cout << "Enter Tape ID: "; cin >> id;
            cout << "Enter Tape Title: "; cin >> title;
            cout << "Enter Tape Artist: "; cin >> artist;
            cout << "Enter Tape Price: "; cin >> price;
            arr[i] = new Tape(id, title, artist, price);
        } else {
            cout << "Invalid choice!" << endl;
            i--;
        }
    }

    double total = 0;
    cout << "\nPurchased Products: \n";
    for (int i = 0; i < 3; i++) {
        arr[i]->display();
        total += arr[i]->calculatePrice();
    }

    cout << "\nFinal Bill after discounts: $" << total << endl;

    for (int i = 0; i < 3; i++) {
        delete arr[i];
    }

    return 0;
}