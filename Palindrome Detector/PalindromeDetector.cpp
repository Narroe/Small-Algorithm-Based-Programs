// Palindrome detector

#include<iostream>

using namespace std;

string gWord = "";
void display_welcomeMsg(void);
string get_input();


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

bool test_string(string input)
{
    gWord = input;

    bool isPalindrome = false;

    return isPalindrome;
}

void display_results(bool isPal)
{
    if(isPal) cout << "\n\n\t\"" << gWord << "\" IS a palindrome.\n\n";
    else cout << "\n\n\t\"" << gWord << "\" is NOT a palindrome.\n\n";
}

int main()
{
    display_welcomeMsg();
    display_results(test_string(get_input()));
    return 0;
}
