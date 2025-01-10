#include <iostream>
using namespace std;

class Shop
{
private:
    int itemId[100];
    int itemPrice[100];
    int counter;

public:
    void initial_counter();
    void setData(void);
    void display(void);
};
void Shop::initial_counter()
{
    counter = 0;
}
void Shop::setData(void)
{
    cout << "Enter the id of the item: " << counter + 1 << endl;
    cin >> itemId[counter];
    cout << "Enter the price of ur item: " << counter + 1 << endl;
    cin >> itemPrice[counter];
    counter++;
}
void Shop::display(void)
{
    for (int i = 0; i < counter; i++)
    {
        cout << "THE ID of ur iitem and price is: " << itemId[i] << " " << itemPrice[i] << endl;
    }
}
int main()
{
    Shop store1;
    cout << "Shop items details!!" << endl;
    store1.initial_counter();
    store1.setData();
    store1.display();
}
//***************************************************************************************** */
