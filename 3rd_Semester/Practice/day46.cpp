
// Classes:
// Book (Base Class)

// bookID (int) – Unique ID for each book.
// title (char*) – Title of the book.
// author (char*) – Name of the author.
// Constructor, displayBook() function.

// Library class
// books[] – Array of Book pointers.
// bookCount – Number of books added.

// Functions:
// addBook(): Adds a book to the library.
// displayLibrary(): Displays all books.
// checkDuplicateBooks(): Finds books that appear multiple times and prints the most repeated book.

#include <iostream>
#include <cstring>
using namespace std;

class Book
{
protected:
    char *title;
    char *author;
    int bookID;

public:
    Book()
    {
        cout << "Default constrcutor Book" << endl;
        bookID = 0;
        title = new char[1];
        strcpy(title, "");

        author = new char[1];
        strcpy(author, "");
    }
    Book(int id, const char *titlee,const char* authorr)
    {

        // cout << "Parametrized Constrcutor Book" << endl;
        title = new char[strlen(titlee) + 1];
        strcpy(title, titlee);

        author = new char[strlen(authorr) + 1];
        strcpy(author, authorr);

        bookID = id;
    }
    void Display()
    {
        // cout << "Book Details" << endl;
        cout << "Title of the Book: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Book id: " << bookID << endl;
    }

    ~Book()
    {
        delete[] title;
        delete[] author;
    }
};

// Library class
// books[] – Array of Book pointers.
// bookCount – Number of books added.

// Functions:
// addBook(): Adds a book to the library.
// displayLibrary(): Displays all books.
// checkDuplicateBooks(): Finds books that appear multiple times and prints the most repeated book.

class Library
{

protected:
    Book *books[10];
    int bookCount;

public:
    Library()
    {
        bookCount = 0;
    }
    ~Library()
    {
        for (int i = 0; i < bookCount; i++)
        {
            delete books[i];
        }
    }

    void addBooks(int id, const char *title,const char* authorr)
    {
        if (bookCount < 10)
        {
            books[bookCount] = new Book(id, title,authorr);
            bookCount++;
        }
        else
        {
            cout << "Library is full. " << endl;
        }
    }
    void DisplayLibrary()
    {

        if (bookCount == 0)
        {
            cout << "No book is in Library" << endl;
        }
        else
        {

            for (int i = 0; i < bookCount; i++)
            {
                books[i]->Display();
            }
        }
    }
    // void checkDuplicateBook()
    // {
    //     if (bookCount == 0)
    //     {
    //         cout << "No book is in Library" << endl;
    //     }
    //     int maxCount = 0;
    //     Book *mostRepeated = nullptr;

    //     if(maxCount>1){
    //         cout<<"Most repeated Book"<<endl;
    //         mostRepeated->Display();
    //     }
    //     else{
    //         cout<<"No Duplicate Book found"<<endl;
    //     }
    // }
};

int main (){

    Library l1;
    l1.addBooks(101,"Atomic Habits","James");
    l1.addBooks(102,"My Personality","Shumas");
    cout<<"Book Details"<<endl;
    l1.DisplayLibrary();

}