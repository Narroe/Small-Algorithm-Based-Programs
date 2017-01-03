/*NOT CURRENTLY WORKING*/
// Day Name Finder (using Tomohiko Sakamoto's algorithm) 

#include<iostream>
#include<sstream>
using namespace std;

// user inputs
int iDay = 0;
int iMonth = 0;
int iYear = 0;

string get_input(string);
bool test_inputValidity(string);
string process_dayOfWeek(int,int,int);
void display_results(int,int,int,string);

int main()
{

    return 0;
}

string get_input(string inputName)
{
    cout << "please input\n";
    cout << inputName << ": ";

    string str;
    getline(cin, str);

    return str;
}

bool test_inputValidity(string input)
{
    bool isValid = false;

    int testNum;
    stringstream(input) >> testNum;

    if(testNum != 0 || input == "0") isValid = true;
    cout << testNum;

    return isValid;
}

string process_dayOfWeek(int day, int month, int year)
{
    static int t[] = {0,3,2,5,0,3,5,1,4,6,2,4};
    year -= month < 3;

    int dayNum = (year + (year/4) - (year/100) + (year/400) + t[month-1] + day) % 7;

    const char* dayName[] = {"sunday","monday","tuesday","wednesday","thursday","friday","saturday"};

    return dayName[dayNum];
}

void display_results(int d, int m, int y, string dName)
{
    string monthName[] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
    cout << "The " << d << " of " << monthName[m] << " " << y << " was a " << dName << endl;
}
