#include <iostream>
#include <cstring>
using namespace std;

class Time
{

private:
    int hour;
    int minute;
    int second;

public:
    Time()
    {
        hour = 0;
        minute = 0;
        second = 0;
    }
    void setHour(int h)
    {

        if (h > 0 && h < 24)
        {
            hour = h;
        }
        else
        {
            hour = 0;
        }
    }
    void setMinute(int m)
    {
        if (m > 0 && m < 60)
        {
            minute = m;
        }
        else
        {
            minute = 0;
        }
    }
    void setSecond(int s)
    {
        if (s > 0 && s < 60)
        {
            second = s;
        }
        else
        {
            second = 0;
        }
    }
    void setTime(int h, int m, int s)
    {
        setHour(h);
        setMinute(m);
        setSecond(s);
    }
    void Display()
    {
        cout << "Time: " << endl;
        // cout<<"Hour: "<<hour<<" Minute: "<<minute<< "Seconds: "<<second<<endl;
        cout << hour << " Hour " << minute << " Minute " << second << " Second" << endl;
    }
    void StandardDisplay()
    {
        cout << hour << ":" << minute << ":" << second << " PM" << endl;
    }
};

int main()
{
    Time t1;
    t1.setTime(11, 14, 20);
    t1.Display();
    t1.StandardDisplay();
}