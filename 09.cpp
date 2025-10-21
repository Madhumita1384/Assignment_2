#include<iostream>
#include<string>

using namespace std;

class MyBankAcct {
private:
    // These members are 'private' (data hiding) 
    // and can only be accessed/modified by methods inside this class.
    string theName; 
    int theNumber;
    double theMoney;

public:
    // Constructor: Used to create and properly initialize the account.
    MyBankAcct(string name, int accNum, double startMoney) {
        theName = name;
        theNumber = accNum;
        
        // Safety check: Ensure the initial balance is not negative.
        if (startMoney > 0) {
            theMoney = startMoney;
        } else {
            theMoney = 0.0;
        }
        
        cout << "New account opened for: " << theName << endl;
    }

    // Method to put money in, includes a check for positive amounts.
    void deposit(double amount) {
        if (amount > 0) {
            theMoney = theMoney + amount;
            cout << "DEPOSIT successful. New balance: " << theMoney << endl;
        } else {
            cout << "Error: You must deposit a positive amount." << endl;
        }
    }

    // Method to take money out, includes checks for positive amount and sufficient balance.
    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "Error: You must withdraw a positive amount." << endl;
        } 
        else if (amount > theMoney) {
            cout << "Withdrawal FAILED. Not enough money in the account." << endl;
        } 
        else {
            theMoney = theMoney - amount;
            cout << "WITHDRAWAL successful. New balance: " << theMoney << endl;
        }
    }

    void showDetails() {
        cout << "\n--- Account Info ---" << endl;
        cout << "Holder: " << theName << endl;
        cout << "Number: " << theNumber << endl;
        cout << "Balance: " << theMoney << endl;
        cout << "--------------------" << endl;
    }
};
int main() {
    MyBankAcct myAcct("Leo Messi", 1000, 750.50);
    myAcct.showDetails();

    cout << "\n--- Trying Transactions ---" << endl;

    myAcct.deposit(100.0);
    myAcct.withdraw(50.0);
    myAcct.withdraw(1000.0); // This one should fail.

    myAcct.showDetails();

    cout << "\n Trying to break the rules! (Encapsulation Demo)" << endl;
    
    // // myAcct.theMoney = 999999.0; <--- This line is FORBIDDEN!
    // The private variable 'theMoney' cannot be touched directly.
    // You MUST use the safe public methods like deposit() and withdraw().

    return 0;
}
