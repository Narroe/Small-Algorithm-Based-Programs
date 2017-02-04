// Palindrome detector

#include<iostream>

using namespace std;

string gWord = "";

void display_welcomeMsg(void);
string get_input();
bool test_string(string);
bool test_corChar(char,char);
void display_results(bool);

int main()
{
    display_welcomeMsg();
    display_results(test_string(get_input()));
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

bool test_string(string input)
{
    gWord = input;

    bool isPalindrome = true; // if it is disproved at least once it becomes false.

    //cout << "\n\t[character pairs: " << input.length()/2 << "]\n";

    for (unsigned int i=0; i<(input.length()/2); i++)
    {
        /*
        cout << "\n\ti:: " << i;
        cout << "\n\t1-> " << input[i];
        cout << "\n\t2-> " << input[(input.length()-i)-1];
        */
        if(isPalindrome) // if its still true, test next character pair
        {
            if(!test_corChar(input[i],input[(input.length()-i)-1])) isPalindrome = false;
        }
        else break; // break loop.
    }

    return isPalindrome;
}

bool test_corChar(char a, char b) // tests the Corresponding Characters in a word.
{
    if (a == b) return true;
    else return false;
}

void display_results(bool isPal)
{
    if(isPal) cout << "\n\n\t\"" << gWord << "\" IS a palindrome.\n\n";
    else cout << "\n\n\t\"" << gWord << "\" is NOT a palindrome.\n\n";
}
