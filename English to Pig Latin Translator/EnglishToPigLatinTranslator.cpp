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
    cout << " please enter a sentence for translation\n";
    cout << "(with no punctuation & in lowercase only)\n\n";
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
            if(i == str.length()-1) store_translatedString(translate_word(subStr, true));
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
    cout << "[iL:" << isLast << " " << input << "] "; // test

    string output = "";
    unsigned int index = 0;
    unsigned int strLength = 0;

    // work out string length
    if(isLast) strLength = input.length();
    else strLength = input.length()-1; // this is because the space (" ") at the end of a word, is counted as part of the word length at this stage.

    /* work out what character types the word starts with
        i.e. are there 1, 2, or 3 consonants in a row
        at the start of the word, or does it begin with
        a vowel.
        e.g. 1-"hello", 2-"there", 3-"school", 0-"apple" */

    // 1st first letter is a vowel
    if(isLetterVowel(input[0]) == true) index = 0;
    // 1st letter is a consonant (& second letter is a vowel)
    else if(!isLetterVowel(input[0]) && isLetterVowel(input[1])) index = 1;
    // 1st && 2nd letters are consonants (& 3rd letter is a vowel)
    else if (!isLetterVowel(input[0]) && !isLetterVowel(input[1]) && isLetterVowel(input[2])) index = 2;
    // 1st, 2nd, && 3rd letters are consonants
    else if (!isLetterVowel(input[0]) && !isLetterVowel(input[1]) && !isLetterVowel(input[2]) && isLetterVowel(input[3])) index = 3;

    // string population loop
    for(unsigned int i = 0; i<=strLength; i++) // the "=" (in "i<=strLength")is to add one extra iteration for the zero value index word to output properly.
    {
        // as long as (i+index) less than input.length();
        if((i+index)<strLength) output += input[i+index]; // <-- it is needed (the "=") because of this conditional statement, never being false within the above for-loop otherwise.
        else
        {
            // suffix appropriate end
            if(index == 0)
            {
                output += "-way";
            }
            else if(index == 1)
            {
                output += "-";
                output += input[0];
                output += "ay";
            }
            else if(index == 2)
            {
                output += "-";
                output += input[0];
                output += input[1];
                output += "ay";
            }
            else if(index == 3)
            {
                output += "-";
                output += input[0];
                output += input[1];
                output += input[2];
                output += "ay";
            }

            break; // break loop.
        }
    }

    return output;
}

bool isLetterVowel(char l)
{
    bool isVowel = false;
    if(l == 'a' || l == 'e' || l == 'i' || l == 'o' || l == 'u' || l == 'y'/*"Y" as a vowel*/) isVowel = true;
    cout << "[" << isVowel << "]\n";
    return isVowel;
}

void store_translatedString(string input)
{
    //cout << ": " << input;
    tStr += (input + " ");
}

void display_translatedString()
{
    cout << "\n\n> " << tStr << "\n\n";
}
