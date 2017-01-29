// Palindrome detector

#include<iostream>

using namespace std;

void display_welcomeMsg(void);
string get_input();


int main()
{
    display_welcomeMsg();
    return 0;
}

void display_welcomeMsg()
{
    cout << "\tPalindrome detector\n\n";
    cout << "please input word (no puctuation):\n\n";
    cout << "> ";
}

string get_input()
{
    string input;
    getline(cin,input);
    return input;
}

