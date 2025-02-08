// Abstract Class and Polymorphism in Banking System
// Base Class: BankAccount
// Attributes:
// 	•	title (char *) – Title of the bank account holder.
// 	•	accountNumber (int) – Unique account number.
// 	•	balance (float) – Current balance of the account.
// Functions:
// 	•	Constructor: Implement a parameterized constructor to initialize title, account number, and balance.
// 	•	Pure Virtual Functions:
// 	•	Deposit(float amount) – A pure virtual function to deposit an amount into the account.
// 	•	Withdraw(float amount) – A pure virtual function to withdraw an amount from the account.
// 	•	Virtual Destructor: Implement a virtual destructor to ensure proper cleanup of derived class objects.

#include <iostream>
#include <cstring>
using namespace std;

class BankAccount
{
protected:
    char *title;
    int accountNumber;
    float balance;

public:
    BankAccount()
    {
        title = new char[1];
        strcpy(title, "");

        accountNumber = 0;
        balance = 0;
    }
    BankAccount(char *t, int no, float bal)
    {
        accountNumber = no;
        balance = bal;
        title = new char[strlen(t) + 1];
        strcpy(title, t);
    }
    virtual void Deposit(float amount) = 0;
    virtual void WithDraw(float amount) = 0;

    virtual void Display()
    {
        cout << "Title of the Account: " << title << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance in the Account: " << balance << endl;
    }
    virtual ~BankAccount()
    {
        delete[] title;
    }
};

// Derived Class: SavingsAccount
// Attributes:
// 	•	bonus (int) – bonus amount, if applicable to the savings account.
// Functions:
// 	•	Constructor: Implement a parameterized constructor to initialize title, account number, balance, and bonus.
// 	•	Override Deposit: Implement the Deposit(float amount) method to increase the balance by the deposited amount.
//      Add bonus as well if the balance exceeds 50,000 each time.
// 	•	Override Withdraw: Implement the Withdraw(float amount) method to decrease the balance by the withdrawn amount, if sufficient funds are available.

class SavingsAccount : public BankAccount
{
    int bonus;

public:
    SavingsAccount() { bonus = 0; }
    SavingsAccount(char *t, int no, float bal, int bonusAmt) : BankAccount(t, no, bal)
    {

        bonus = bonusAmt;
    }
    void Deposit(float amount)
    {
        balance += amount;
        if (balance > 50000)
        {
            balance += bonus;
        }
    }
    void WithDraw(float amount)
    {
        if (amount <= balance)
        {
            balance -= amount;
        }
        else
        {
            cout << "Insuffient funds are available" << endl;
        }
    }
};

// Derived Class: CheckingAccount
// Attributes:
// 	•	transactionFee (float) – Fee charged for each transaction.
// Functions:
// 	•	Constructor: Implement a parameterized constructor to initialize title, account number, balance, and transaction fee.
// 	•	Override Deposit: Implement the Deposit(float amount) method to increase the balance by the deposited amount minus the transaction fee.
// 	•	Override Withdraw: Implement the Withdraw(float amount) method to decrease the balance by the withdrawn amount plus the transaction fee,
//      if sufficient funds are available.

class CheckingAccount : public BankAccount
{

    float transactionFee;

public:
    CheckingAccount(char *t, int no, float bal, float fee) : BankAccount(t, no, bal)
    {

        transactionFee = fee;
    }
    void Deposit(float amount)
    {
        balance += amount - (transactionFee);
    }
    void WithDraw(float amount)
    {
        if (amount + transactionFee <= balance)
        {
            balance -= (amount + transactionFee);
        }
        else
        {
            cout << "Insuffienct Balance for Withdrawl" << endl;
        }
    }
};

//  Main Function
// •	Create an array of pointers to BankAccount.
// •	Add objects of both classes SavingsAccount and CheckingAccount in the array.
// •	Simulate transactions for each account type by calling the Deposit() and Withdraw() methods on each object in the array.
// •	Display the final balances of each account after the transactions.

int main()
{

    BankAccount *acc[2];
    acc[0] = new SavingsAccount("Shumas", 1002, 500000, 50);
    acc[1] = new CheckingAccount("Mazhar", 1004, 100000, 5);
    acc[0]->Display();
    acc[1]->Display();

    acc[1]->WithDraw(5000);
    acc[1]->Display();
}