// English to Pig-Latin Translator [INCOMPLETE]

/*  Note: compound words are not supported:
    e.g. "classroom" would produce "assroom-clay",
    instead: "class room" would produce "ass-clay oom-ray",
    which is more correct.*/

#include<iostream>
#include<string>

using namespace std;

string tStr = ""; // translated string

void welcomeMsg();
string get_input();
void separate_string(string);
bool isLetterVowel(char);
string translate_word(string,bool);
void store_translatedString(string);
void display_translatedString(void);

int main()
{
    welcomeMsg();
    separate_string(get_input());
    display_translatedString();
    return 0;
}

void welcomeMsg()
{
    cout << "\tEnglish to Pig Latin translator\n\n";
    cout << "please enter a sentence for translation (no punctuation)\n\n";
    cout << "> ";
}

string get_input()
{
    string input;

    getline(cin, input);

    return input;
}

void separate_string(string str)
{
    unsigned int pos = 0;

    for(unsigned int i=0; i<str.length(); i++)
    {
        if((str[i] == ' ') || (i == (str.length()-1))) // true, if the is a space after a word OR to catch the end word.
        {
            string subStr = "";
            do
            {
                subStr += str[pos];
                pos++;
            }
            while(pos<=i);

            // checks if current word is the last word
            if(i == str.length()) store_translatedString(translate_word(subStr, true));
            else store_translatedString(translate_word(subStr, false));
        }
    }
}

/*  Note: the purpose of the "isLast" boolean is to determine
    whether or not to remove the last character in a sequence/word.
    This is important b/c all words except the last, are succeeded by
    a space (" "). */

string translate_word(string input, bool isLast)
{
    string output = "";
    unsigned int index = 0;

    // is the first letter a consonant
    if(!isLetterVowel(input[0]))
    {
        // is the second letter a consonant
        if(!isLetterVowel(input[1])) index = 2;
        else index = 1;

    }
    // if first letter is a vowel, add "-yay" to the end of the word
    else
    {
        index = 0;
    }

    // string population loop
    for(unsigned int i = index; i<input.length(); i++)
    {
        output += input[i+index];
    }

    return output;
}

bool isLetterVowel(char l)
{
    bool isVowel = false;
    if(l == 'a' || l == 'e' || l == 'i' || l == 'o' || l == 'u') isVowel = true;
    return isVowel;
}

void store_translatedString(string input)
{
    tStr += (input + " ");
}

void display_translatedString()
{
    cout << "\n\n> " << tStr << "\n\n";
}
