// Uptime Counter

#include<iostream>
#include<ctime>
#include<sstream>
#include<string>
using namespace std;

int get_seconds(int);
int get_minutes(int);
int get_hours(int);
string format_time(int);
void display_clock(int,int,int);

int main()
{
    const int SECOND = 1000;

    for (unsigned int i = 0; true; i=clock())
    {
        display_clock(get_hours(i),get_minutes(i),get_seconds(i));
    }

    return 0;
}

int get_seconds(int input)
{
    return input/1000;
}

int get_minutes(int input)
{
    return input/100000;
}

int get_hours(int input)
{
    return input/10000000;
}

string format_time(int input)
{
    stringstream ss;
    string output;

    ss << input;

    if (input < 10) output = "0" + ss.str();
    else output = ss.str();

    return output;
}

void display_clock(int h, int m, int s) // hours,minutes,seconds
{
    cout << "\t[" << format_time(h) << ':' << format_time(m) << ':' << format_time(s) << "]\n";
}
