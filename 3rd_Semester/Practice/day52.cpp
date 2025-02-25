#include <iostream>
#include <cstring>

using namespace std;

class Book
{
protected:
    float price;

public:
    Book(float p)
    {
        price = p;
    }
    virtual void Display() const = 0;
    virtual ~Book()
    {
    }
};

class PrintedBook : public Book
{

protected:
    int pageCount;

public:
    PrintedBook(int pg, float p) : Book(p)
    {
        pageCount = pg;
    }
    void Display () const 
    {
        cout << "Printed book Pages: " << pageCount << " Price: " << price << endl;
    }
};

class AudioBook : public Book
{
protected:
    float time;

public:
    AudioBook(float t, int p) : Book(p)
    {
        time = t;
    }
    void Display() const
    {
        cout << "AudioBook Time: " << time << " Price: " << price << endl;
    }
};

int main (){

    Book *b;
    b=new PrintedBook(50,100.0);
    b->Display();

    delete b;

    // b->Display();

    b=new AudioBook(10.0,200);
    b->Display();
    delete b;
}