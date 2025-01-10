//***************************************************************************************** */
//***************************************************************************************** */
// Constructors overloading
// Bankdeposit management 
// gives value after applying interest rate
//***************************************************************************************** */

#include <iostream>
using namespace std;

class BankDesposit
{
    int amount;
    int years;
    float interestRate;
    float returnValue;

public:
    BankDesposit() {}
    BankDesposit(int amt, int y, float r);
    BankDesposit(int amt, int y, int r);
    void show(void);
};

BankDesposit::BankDesposit(int amt, int y, float r)
{
    amount = amt;
    years = y;
    interestRate = r;
    returnValue = amount;
    for (int i = 0; i < y; i++)
    {
        returnValue = returnValue * (1 + interestRate);
    }
}
BankDesposit::BankDesposit(int amt, int y, int r)
{
    amount = amt;
    years = y;
    interestRate = float(r) / 100;
    returnValue = amount;
    for (int i = 0; i < y; i++)
    {
        returnValue = returnValue * (1 + interestRate);
    }
}
void BankDesposit::show(void)
{
    cout << "The amount was: " << amount
         << "  Return value after " << years
         << " years is: " << returnValue << endl;
}

int main()
{

    cout << "Inside the main body " << endl;
    BankDesposit bd1, bd2, bd3;
    int amount, years;
    float rate;
    int R;
    cout << "Enter the value: ";
    cin >> amount;
    cout << "Enter the years: ";
    cin >> years;
    cout << "Enter the interest rate: ";
    cin >> rate;
    bd1 = BankDesposit(amount, years, rate);
    bd1.show();
    cout << "Enter the value: ";
    cin >> amount;
    cout << "Enter the years: ";
    cin >> years;
    cout << "Enter the interest rate: ";
    cin >> R;
    bd2 = BankDesposit(amount, years, R);
    bd2.show();
}