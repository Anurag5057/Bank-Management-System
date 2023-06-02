#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Account {
private:
    string accountNumber;
    string accountHolderName;
    double balance;

public:
    Account(string number, string name, double initialBalance)
        : accountNumber(number), accountHolderName(name), balance(initialBalance) {}

    string getAccountNumber() const {
        return accountNumber;
    }

    string getAccountHolderName() const {
        return accountHolderName;
    }

    double getBalance() const {
        return balance;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited " << amount << " into account " << accountNumber << endl;
    }

    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient balance in account " << accountNumber << endl;
        } else {
            balance -= amount;
            cout << "Withdrawn " << amount << " from account " << accountNumber << endl;
        }
    }
};

class Bank {
private:
    vector<Account> accounts;

public:
    void addAccount(const Account& account) {
        accounts.push_back(account);
        cout << "Account added: " << account.getAccountNumber() << endl;
    }

    void removeAccount(const string& accountNumber) {
        auto it = find_if(accounts.begin(), accounts.end(), [&](const Account& acc) {
            return acc.getAccountNumber() == accountNumber;
        });

        if (it != accounts.end()) {
            accounts.erase(it);
            cout << "Account removed: " << accountNumber << endl;
        } else {
            cout << "Account not found: " << accountNumber << endl;
        }
    }

    void depositToAccount(const string& accountNumber, double amount) {
        auto it = find_if(accounts.begin(), accounts.end(), [&](const Account& acc) {
            return acc.getAccountNumber() == accountNumber;
        });

        if (it != accounts.end()) {
            it->deposit(amount);
        } else {
            cout << "Account not found: " << accountNumber << endl;
        }
    }

    void withdrawFromAccount(const string& accountNumber, double amount) {
        auto it = find_if(accounts.begin(), accounts.end(), [&](const Account& acc) {
            return acc.getAccountNumber() == accountNumber;
        });

        if (it != accounts.end()) {
            it->withdraw(amount);
        } else {
            cout << "Account not found: " << accountNumber << endl;
        }
    }

    void displayAllAccounts() const {
        cout << "Accounts:" << endl;
        for (const auto& account : accounts) {
            cout << "Account Number: " << account.getAccountNumber() << endl;
            cout << "Account Holder: " << account.getAccountHolderName() << endl;
            cout << "Balance: " << account.getBalance() << endl;
            cout << "----------------------" << endl;
        }
    }
};

int main() {
    Bank bank;

    while (true) {
        cout << "Bank Management System" << endl;
        cout << "1. Add Account" << endl;
        cout << "2. Remove Account" << endl;
        cout << "3. Deposit to Account" << endl;
        cout << "4. Withdraw from Account" << endl;
        cout << "5. Display All Accounts" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Enter account number: ";
                string accountNumber;
                cin >> accountNumber;
                cout << "Enter account holder name: ";
                string accountHolderName;
                cin.ignore();
                getline(cin, accountHolderName);
                cout << "Enter initial balance: ";
                double initialBalance;
                cin >> initialBalance;

                Account account(accountNumber, accountHolderName, initialBalance);
                bank.addAccount(account);
                break;
            }
            case 2: {
                cout << "Enter account number to remove: ";
                string accountNumber;
                cin >> accountNumber;

                bank.removeAccount(accountNumber);
                break;
            }
            case 3: {
                cout << "Enter account number to deposit: ";
                string accountNumber;
                cin >> accountNumber;
                cout << "Enter amount to deposit: ";
                double amount;
                cin >> amount;

                bank.depositToAccount(accountNumber, amount);
                break;
            }
            case 4: {
                cout << "Enter account number to withdraw: ";
                string accountNumber;
                cin >> accountNumber;
                cout << "Enter amount to withdraw: ";
                double amount;
                cin >> amount;

                bank.withdrawFromAccount(accountNumber, amount);
                break;
            }
            case 5:
                bank.displayAllAccounts();
                break;
            case 6:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }

        cout << endl;
    }

    return 0;
}
