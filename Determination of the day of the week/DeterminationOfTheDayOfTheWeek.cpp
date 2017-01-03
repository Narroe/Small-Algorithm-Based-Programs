// Determination of the day of the week (using Tomohiko Sakamoto's algorithm)

#include<iostream>
#include<sstream>
using namespace std;

// Global Variables
int gDay = 0;
int gMonth = 0;
int gYear = 0;
string gDayName = "";

string get_input(string);
bool test_inputValidity(string, string);
string process_dayOfWeek(int,int,int);
void display_results(int,int,int,string);
void input_loop(int);
void update_globalVariables(string,int);

int main()
{
    cout << "Determination of the day of the week using Tomohiko Sakamoto's algorithm\n\n";

    input_loop(1);

    return 0;
}

void input_loop(int stage)
{
    if(stage == 1)
    {
        if(!test_inputValidity("Day", get_input("Day"))) input_loop(1);
        else input_loop(2);
    }
    else if (stage == 2)
    {
        if(!test_inputValidity("Month", get_input("Month"))) input_loop(2);
        else input_loop(3);
    }
    else if (stage == 3)
    {
        if(!test_inputValidity("Year", get_input("Year"))) input_loop(3);
        else display_results(gDay, gMonth, gYear, process_dayOfWeek(gDay, gMonth, gYear));
    }
}

string get_input(string inputName)
{
    if(inputName == "Day") cout << "please input\n"; // show this statement on first iteration only.
    cout << '\t' << inputName << ": ";

    string str;
    getline(cin, str);

    return str;
}

bool test_inputValidity(string inputType, string input)
{
    bool isValid = false;

    int testNum;
    stringstream(input) >> testNum;

    if((testNum != 0 || input == "0") && (testNum >= 0))
    {
        // okay, now we know it is a number, now to check if it is in acceptable ranges.
        if((inputType == "Day") && ((testNum > 0) && (testNum < 32))) isValid = true;
        else if((inputType == "Month") && ((testNum > 0) && (testNum < 13))) isValid = true;
        else if((inputType == "Year") && ((testNum > 0) && (testNum < 2100))) isValid = true;
        else cout << "Error @ test_inputValidity():\ninputType: " << inputType << "\ntestNum: " << testNum << endl;
    }

    if(isValid) update_globalVariables(inputType, testNum);

    return isValid;
}

void update_globalVariables(string iType, int input)
{
    if(iType == "Day") gDay = input;
    else if (iType == "Month") gMonth = input;
    else if (iType == "Year") gYear = input;
}

string process_dayOfWeek(int day, int month, int year)
{
    static int t[] = {0,3,2,5,0,3,5,1,4,6,2,4};
    year -= month < 3;

    string dayNameArray[] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};

    int dayNum = (year + (year/4) - (year/100) + (year/400) + t[month-1] + day) % 7;

    return dayNameArray[dayNum];
}

void display_results(int d, int m, int y, string dName)
{
    string monthNameArray[] = {"January","February","March","April","May","June","July","August","September","October","November","December"};

    cout << "\n\tThe " << d << " of " << monthNameArray[m-1] << " " << y << " was a " << dName << endl;
}
