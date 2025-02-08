//---------------------------------------------------------------------------------------------------------------------

// Name: Muhammad Shumas Mazhar
// Registration: l1f23bscs1097
// Lab 15 OOPS
// Task 2

//---------------------------------------------------------------------------------------------------------------------


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
    BankAccount(const char *t, int No, float bal)
    {
        title = new char[strlen(t) + 1];
        strcpy(title, t);
        accountNumber = No;
        balance = bal;
    }

    virtual void Deposit(float amount) = 0;
    virtual void Withdraw(float amount) = 0;

    virtual void displayAccountInfo() const
    {
        cout << "Title: " << title << ", Account Number: " << accountNumber
             << ", Balance: " << balance << endl;
    }

    virtual ~BankAccount()
    {
        delete[] title;
    }
};

//---------------------------------------------------------------------------------------------------------------------

class SavingsAccount : public BankAccount
{
private:
    int bonus;

public:
    SavingsAccount(const char *t, int accNo, float bal, int b)
        : BankAccount(t, accNo, bal), bonus(b) {}

    void Deposit(float amount) override
    {
        balance += amount;
        if (balance > 50000)
        {
            balance += bonus;
        }
    }

    void Withdraw(float amount)override
    {
        if (amount <= balance)
        {
            balance -= amount;
        }
        else
        {
            cout << "Insufficient balance for withdrawal." << endl;
        }
    }
};

//---------------------------------------------------------------------------------------------------------------------

class CheckingAccount : public BankAccount
{
private:
    float transactionFee;

public:
    CheckingAccount(const char *t, int accNo, float bal, float fee)
        : BankAccount(t, accNo, bal), transactionFee(fee) {}

    void Deposit(float amount)override
    {
        balance += (amount - transactionFee);
    }

    void Withdraw(float amount) override
    {
        if (amount + transactionFee <= balance)
        {
            balance -= (amount + transactionFee);
        }
        else
        {
            cout << "Insufficient balance for withdrawal." << endl;
        }
    }
};

//---------------------------------------------------------------------------------------------------------------------

int main()
{
    BankAccount *accounts[2];
    cout <<endl<< "Welcome to Bank Management System";
    accounts[0] = new SavingsAccount("Alice", 101, 30000, 500);
    accounts[1] = new CheckingAccount("Bob", 102, 20000, 50);

    accounts[0]->Deposit(25000);
    accounts[0]->Withdraw(10000);

    accounts[1]->Deposit(1000);
    accounts[1]->Withdraw(500);
    cout << endl;
    cout << "Final Account Balances: " << endl;
    for (int i = 0; i < 2; i++)
    {
        accounts[i]->displayAccountInfo();
        delete accounts[i];
    }

    
}
//---------------------------------------------------------------------------------------------------------------------


