#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

// Account structure to store user details
struct Account {
    string name;
    int accountNumber;
    double balance;
};

// Function declarations
void displayMenu();
void createAccount(vector<Account>& accounts);
void depositMoney(vector<Account>& accounts);
void withdrawMoney(vector<Account>& accounts);
void checkBalance(const vector<Account>& accounts);
void displayAllAccounts(const vector<Account>& accounts);

int main() {
    vector<Account> accounts;
    int choice;

    cout << "===== SIMPLE BANKING SYSTEM =====" << endl;

    while (true) {
        displayMenu();
        cout << "Enter your choice (1-6): ";
        cin >> choice;

        // Clear input buffer to prevent infinite loops on invalid input
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1:
                createAccount(accounts);
                break;
            case 2:
                depositMoney(accounts);
                break;
            case 3:
                withdrawMoney(accounts);
                break;
            case 4:
                checkBalance(accounts);
                break;
            case 5:
                displayAllAccounts(accounts);
                break;
            case 6:
                cout << "Exiting the system. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
}

void displayMenu() {
    cout << "\n======= MENU =======" << endl;
    cout << "1. Create Account" << endl;
    cout << "2. Deposit Money" << endl;
    cout << "3. Withdraw Money" << endl;
    cout << "4. Check Balance" << endl;
    cout << "5. Display All Accounts" << endl;
    cout << "6. Exit" << endl;
    cout << "====================" << endl;
}

void createAccount(vector<Account>& accounts) {
    Account newAccount;
    cout << "\nEnter account holder name: ";
    getline(cin, newAccount.name);

    cout << "Enter account number: ";
    cin >> newAccount.accountNumber;

    cout << "Enter initial deposit: $";
    cin >> newAccount.balance;

    accounts.push_back(newAccount);
    cout << "Account created successfully!" << endl;
}

void depositMoney(vector<Account>& accounts) {
    int accountNum;
    double amount;

    cout << "\nEnter account number: ";
    cin >> accountNum;

    for (auto& acc : accounts) {
        if (acc.accountNumber == accountNum) {
            cout << "Enter amount to deposit: $";
            cin >> amount;
            acc.balance += amount;
            cout << "Deposit successful! New balance: $" << acc.balance << endl;
            return;
        }
    }
    cout << "Account not found!" << endl;
}

void withdrawMoney(vector<Account>& accounts) {
    int accountNum;
    double amount;

    cout << "\nEnter account number: ";
    cin >> accountNum;

    for (auto& acc : accounts) {
        if (acc.accountNumber == accountNum) {
            cout << "Enter amount to withdraw: $";
            cin >> amount;
            if (amount > acc.balance) {
                cout << "Insufficient funds!" << endl;
            } else {
                acc.balance -= amount;
                cout << "Withdrawal successful! New balance: $" << acc.balance << endl;
            }
            return;
        }
    }
    cout << "Account not found!" << endl;
}

void checkBalance(const vector<Account>& accounts) {
    int accountNum;
    cout << "\nEnter account number: ";
    cin >> accountNum;

    for (const auto& acc : accounts) {
        if (acc.accountNumber == accountNum) {
            cout << "Account Holder: " << acc.name << endl;
            cout << "Current Balance: $" << acc.balance << endl;
            return;
        }
    }
    cout << "Account not found!" << endl;
}

void displayAllAccounts(const vector<Account>& accounts) {
    if (accounts.empty()) {
        cout << "\nNo accounts found!" << endl;
        return;
    }

    cout << "\n====== ALL ACCOUNTS ======" << endl;
    for (const auto& acc : accounts) {
        cout << "Account Number: " << acc.accountNumber << endl;
        cout << "Account Holder: " << acc.name << endl;
        cout << "Balance: $" << acc.balance << endl;
        cout << "-------------------------" << endl;
    }
}