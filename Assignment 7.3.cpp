#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

enum AccountType { SAVINGS, CURRENT };

class InsufficientFundsException : public exception {
public:
    const char* what() const noexcept override {
        return "Transaction Failed: Insufficient funds or invalid deposit amount.";
    }
};

class Account {
private:
    string accountNumber;
    string accountHolder;
    double balance;
    AccountType accountType;

public:
    Account(string accNo, string accHolder, double bal, AccountType type)
        : accountNumber(accNo), accountHolder(accHolder), balance(bal), accountType(type) {}

    string getAccountNumber() const {
        return accountNumber;
    }

    double getBalance() const {
        return balance;
    }

    void deposit(double amount) {
        if (amount < 0) {
            throw InsufficientFundsException();
        }
        balance += amount;
        cout << "Deposit successful. New balance: $" << balance << endl;
    }

    void withdraw(double amount) {
        if (amount > balance || amount < 0) {
            throw InsufficientFundsException();
        }
        balance -= amount;
        cout << "Withdrawal successful. New balance: $" << balance << endl;
    }

    void display() const {
        cout << "Account Number: " << accountNumber << ", Account Holder: " << accountHolder
             << ", Balance: $" << balance << ", Account Type: " 
             << (accountType == SAVINGS ? "Savings" : "Current") << endl;
    }
};

int main() {
    Account* accounts[5];
    int choice;

    for (int i = 0; i < 5; i++) {
        string accNo, accHolder;
        double balance;
        int accType;

        cout << "Enter details for Account " << i + 1 << ":\n";
        cout << "Account Number: "; cin >> accNo;
        cout << "Account Holder: "; cin.ignore(); getline(cin, accHolder);
        cout << "Initial Balance: "; cin >> balance;
        cout << "Account Type (0 for Savings, 1 for Current): "; cin >> accType;

        accounts[i] = new Account(accNo, accHolder, balance, static_cast<AccountType>(accType));
    }

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Display Account Details\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 4) {
            cout << "Exiting the program..." << endl;
            break;
        }

        string accNo;
        cout << "Enter Account Number: "; cin >> accNo;

        Account* selectedAccount = nullptr;
        for (int i = 0; i < 5; i++) {
            if (accounts[i]->getAccountNumber() == accNo) {
                selectedAccount = accounts[i];
                break;
            }
        }

        if (!selectedAccount) {
            cout << "Invalid Account Number!" << endl;
            continue;
        }

        try {
            if (choice == 1) {
                double depositAmount;
                cout << "Enter amount to deposit: "; cin >> depositAmount;
                selectedAccount->deposit(depositAmount);
            } else if (choice == 2) {
                double withdrawAmount;
                cout << "Enter amount to withdraw: "; cin >> withdrawAmount;
                selectedAccount->withdraw(withdrawAmount);
            } else if (choice == 3) {
                selectedAccount->display();
            } else {
                cout << "Invalid choice!" << endl;
            }
        } catch (const InsufficientFundsException& e) {
            cout << e.what() << endl;
        }
    }

    for (int i = 0; i < 5; i++) {
        delete accounts[i];
    }

    return 0;
}




