#include <iostream>
using namespace std;

class String
{
    char *data;
    int size;

public:
    String();                                    // default constructor
    String(const String &obj);                   // copy constructor
    String(const String &obj, int pos, int len); // overloaded constructor
    String(const char *s);                       // overloaded constructor for substring
    String(const char *s, int n);                // overloaded constructor from sequence
    String(int n, char c);                       // overloaded constructor for fill
    ~String();                                   // destructor
    int lenght();                                // returning lenght if the string
    char at(int i);                              // getting a character in string
    String substr(int pos, int len) const;       // substring
    // String substr(int pos,int len)
    friend ostream &operator<<(ostream &ob, const String &obj);
};

String::String() // 1
{
    size = 0;
    data = new char[1];
    data[0] = '\0';
}
String::String(const String &obj) // 2
{
    size = obj.size;
    data = new char[size + 1];
    for (int i = 0; i <= size; i++)
    {
        data[i] = obj.data[i];
    }
}
String::String(const String &obj, int pos, int len) // 3
{
    size = len;
    data = new char[size + 1];
    for (int i = 0; i <= size; i++)
    {
        data[i] = obj.data[pos + i];
    }
    data[size] = '\0';
}
String::String(const char *s) // 4
{
    size = 0;
    while (s[size] != '\0')
    {
        ++size;
    }
    data = new char[size + 1];
    for (int i = 0; i <= size; i++)
    {
        data[i] = s[i];
    }
}
String::String(const char *s, int n) // 5
{
    size = n;
    data = new char[size + 1];
    for (int i = 0; i <= size; i++)
    {
        data[i] = s[i];
    }
    data[size] = '\0';
}
String::String(int n, char c)
{
    size = n;
    data = new char[size + 1];
    for (int i = 0; i <= size; i++)
    {
        data[i] = c;
    }
    data[size] = '\0';
}
String::~String()
{
    delete[] data;
}
int String::lenght()
{
    return size;
}
char String::at(int i)
{
    if (i < 0 || i >= size)
    {
        return '\0';
    }
    return data[i];
}
ostream &operator<<(ostream &ob, const String &obj)
{
    ob << obj.data;
    return ob;
}
int main()
{
    cout << "Inside main body" << endl;
    String s0("Initial String");
    String s1;
    String s2(s0);
    String s3(s0, 8, 5);
    String s4("A character Sequence");
    String s5("Another character sequence");
    String s6a(10, '*');
    String s6b(10, 'x');
    cout << "s0: " << s0 << endl
         << "s1: " << s1 << endl
         << "s2: " << s2 << endl
         << "s3: " << s3 << endl
         << "s4: " << s4 << endl
         << "s5: " << s5 << endl
         << "s6a: " << s6a << endl
         << "s6b: " << s6b << endl;
    
}
