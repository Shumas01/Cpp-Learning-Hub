#include <iostream>
using namespace std;

class Deposit
{
    int amount;
    int years;
    float interestRate;
    float returnValue;

public:
    Deposit() : amount(0), years(0), interestRate(0.0), returnValue(0) {}
    Deposit(int amt, int y, float rate)
    {
        amount = amt;
        years = y;
        interestRate = rate;
        returnValue = amount;
        for (int i = 0; i < years; i++)
        {
            returnValue = returnValue * (1 + interestRate);
        }
    }
    Deposit(int amt, int y, int Rate)
    {
        amount = amt;
        years = y;
        interestRate = float(Rate) / 100;
        returnValue = amount;
        for (int i = 0; i < years; i++)
        {
            returnValue = returnValue * (1 + interestRate);
        }
    }
    void Show(void)
    {
        cout << "The amount was: " << amount
             << " and the interest Rate was: "<<interestRate
             << " and the return Value after " << years
             << " years is: " << returnValue << endl;
    }
};

int main()
{

    cout << "Hello main" << endl;
    Deposit d1, d2;
    d1.Show();
    d2 = Deposit(200, 10, 05);
    d2.Show();
    Deposit d3(100,1,10);
    d3.Show();
}