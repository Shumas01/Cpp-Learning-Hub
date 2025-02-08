#include <iostream>
#include <cstring>
using namespace std;

// Base Class: Product Attributes:
// 	•	productID (int) – Unique identifier for the product.
// 	•	name (char*) – Name of the product..
// 	•	price (double) – Price of the product.
// Functions:
// 	•	Constructor: Parameterized constructor to initialize productID, name and price.
// 	•	display(): Function that displays product details.
// 	•	Getters and Setters if required.

class Product
{

protected:
    int productId;
    char *name;
    double price;

public:
    Product()
    {
        productId = 0;
        price = 0;
        name = new char[1];
        strcpy(name, "");
    }

    Product(int id, const char *namee, double pricee)
    {
        productId = id;
        price = pricee;
        name = new char[strlen(namee) + 1];
        strcpy(name, namee);
    }

    void Display()
    {

        cout << "Product id: " << productId
             << "Price: " << price
             << "Name: " << name << endl;
    }
    int getId()
    {
        return productId;
    }
    double getPrice()
    {
        return price;
    }
    const char *getName()
    {
        return name;
    }
    ~Product()
    {
        delete[] name;
    }
};

// class: ShoppingCart Attributes:
// 	•	products[] – Array of Product pointers (with a predefined maximum).
// 	•	itemCount (int) – Count of current items in the cart.
// Functions:
// 	•	Constructor: Initializes itemCount.
// 	•	addItem(): Adds a Product to the shopping cart.
// 	•	displayCart(): Displays all items in the cart along with their details.

class ShoppingCart
{
protected:
    Product *products[10];
    int itemCount;

public:
    ShoppingCart()
    {
        itemCount = 0;
    }
    void addItem(Product *product)
    {
        if (itemCount < 10)
        {
            products[itemCount++] = product;
        }
        else
        {
            cout << "Cart is full " << endl;
        }
    }
    void DisplayCart() const
    {
        for (int i = 0; i < itemCount; i++)
        {
            products[i]->Display();
        }
    }

    // •	Functions to check most occurrences of an object:
    // •	checkDuplicateProducts():
    //     This function should:
    // •	Loop through the Product array.
    // •	Identify and print the products that were added more than once, along with their counts.
    // •	Determine and print which Product has been added the most times, along with the count of their additions.

    void checkDuplicateProducts() const
    {
        int maxCount = 0;
        Product *mostFrequent = nullptr;
        for (int i = 0; i < itemCount; i++)
        {
            int count = 1;
            for (int j = i + 1; j < itemCount; j++)
            {
                if (products[i]->getId() == products[j]->getId())
                {
                    count++;
                }
            }
            if (count > 1)
            {
                cout<<"Duplicate Product: ";
                products[i]->Display();
                cout<<"Count: "<<count<<endl;
            }
        }
    }
};


int main (){
    ShoppingCart S1;

}