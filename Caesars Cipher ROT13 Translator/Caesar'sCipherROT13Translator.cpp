// Caesar's cipher ROT13 (rotate by 13 places) translator

#include<iostream>
using namespace std;

string gStr = ""; // global/translated string

string get_input();
string process_inputString(string);
char indentify_char(char);
char ROT13(char,char,int,bool);
void update_gStr(char);
void display_gStr();

int main()
{
    cout << "\tCaesar's Cipher ROT13 (rotate by 13) Translator\n\n";
    cout << "please input sentence:\n\n";
    cout << "> ";

    process_inputString(get_input());
    display_gStr();
    return 0;
}

string get_input()
{
    string input;

    getline(cin, input);

    return input;
}

string process_inputString(string input)
{
    for(unsigned int i=0; i<input.length(); i++)
    {
        update_gStr(indentify_char(input[i]));
    }
}

char indentify_char(char input)
{
    char fontCase = ' ';
    int arrayIndex = 0;
    bool isValid = true; // is the character valid for translation (a-z or A-Z)

    switch(input)
    {
        case 'A':
            fontCase = 'u';
            arrayIndex = 0;
            break;
        case 'B':
            fontCase = 'u';
            arrayIndex = 1;
            break;
        case 'C':
            fontCase = 'u';
            arrayIndex = 2;
            break;
        case 'D':
            fontCase = 'u';
            arrayIndex = 3;
            break;
        case 'E':
            fontCase = 'u';
            arrayIndex = 4;
            break;
        case 'F':
            fontCase = 'u';
            arrayIndex = 5;
            break;
        case 'G':
            fontCase = 'u';
            arrayIndex = 6;
            break;
        case 'H':
            fontCase = 'u';
            arrayIndex = 7;
            break;
        case 'I':
            fontCase = 'u';
            arrayIndex = 8;
            break;
        case 'J':
            fontCase = 'u';
            arrayIndex = 9;
            break;
        case 'K':
            fontCase = 'u';
            arrayIndex = 10;
            break;
        case 'L':
            fontCase = 'u';
            arrayIndex = 11;
            break;
        case 'M':
            fontCase = 'u';
            arrayIndex = 12;
            break;
        case 'N':
            fontCase = 'u';
            arrayIndex = 13;
            break;
        case 'O':
            fontCase = 'u';
            arrayIndex = 14;
            break;
        case 'P':
            fontCase = 'u';
            arrayIndex = 15;
            break;
        case 'Q':
            fontCase = 'u';
            arrayIndex = 16;
            break;
        case 'R':
            fontCase = 'u';
            arrayIndex = 17;
            break;
        case 'S':
            fontCase = 'u';
            arrayIndex = 18;
            break;
        case 'T':
            fontCase = 'u';
            arrayIndex = 19;
            break;
        case 'U':
            fontCase = 'u';
            arrayIndex = 20;
            break;
        case 'V':
            fontCase = 'u';
            arrayIndex = 21;
            break;
        case 'W':
            fontCase = 'u';
            arrayIndex = 22;
            break;
        case 'X':
            fontCase = 'u';
            arrayIndex = 23;
            break;
        case 'Y':
            fontCase = 'u';
            arrayIndex = 24;
            break;
        case 'Z':
            fontCase = 'u';
            arrayIndex = 25;
            break;

        case 'a':
            fontCase = 'l';
            arrayIndex = 0;
            break;
        case 'b':
            fontCase = 'l';
            arrayIndex = 1;
            break;
        case 'c':
            fontCase = 'l';
            arrayIndex = 2;
            break;
        case 'd':
            fontCase = 'l';
            arrayIndex = 3;
            break;
        case 'e':
            fontCase = 'l';
            arrayIndex = 4;
            break;
        case 'f':
            fontCase = 'l';
            arrayIndex = 5;
            break;
        case 'g':
            fontCase = 'l';
            arrayIndex = 6;
            break;
        case 'h':
            fontCase = 'l';
            arrayIndex = 7;
            break;
        case 'i':
            fontCase = 'l';
            arrayIndex = 8;
            break;
        case 'j':
            fontCase = 'l';
            arrayIndex = 9;
            break;
        case 'k':
            fontCase = 'l';
            arrayIndex = 10;
            break;
        case 'l':
            fontCase = 'l';
            arrayIndex = 11;
            break;
        case 'm':
            fontCase = 'l';
            arrayIndex = 12;
            break;
        case 'n':
            fontCase = 'l';
            arrayIndex = 13;
            break;
        case 'o':
            fontCase = 'l';
            arrayIndex = 14;
            break;
        case 'p':
            fontCase = 'l';
            arrayIndex = 15;
            break;
        case 'q':
            fontCase = 'l';
            arrayIndex = 16;
            break;
        case 'r':
            fontCase = 'l';
            arrayIndex = 17;
            break;
        case 's':
            fontCase = 'l';
            arrayIndex = 18;
            break;
        case 't':
            fontCase = 'l';
            arrayIndex = 19;
            break;
        case 'u':
            fontCase = 'l';
            arrayIndex = 20;
            break;
        case 'v':
            fontCase = 'l';
            arrayIndex = 21;
            break;
        case 'w':
            fontCase = 'l';
            arrayIndex = 22;
            break;
        case 'x':
            fontCase = 'l';
            arrayIndex = 23;
            break;
        case 'y':
            fontCase = 'l';
            arrayIndex = 24;
            break;
        case 'z':
            fontCase = 'l';
            arrayIndex = 25;
            break;

        default:
            //cout << "input == " << input << "\n\n";
            isValid = false;
    }

    return ROT13(input,fontCase,arrayIndex,isValid);
}

char ROT13(char input, char fontCase, int arrayIndex, bool isValid)
{
    unsigned const int rot13 = 13;
    char uca[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'}; // Upper Case Array
    char lca[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'}; // Lower Case Array
    unsigned int newIndex = 0;

    if(!isValid) return input; // not valid for translation? -> return value as is.
    else
    {
        if((arrayIndex + rot13) > 25)
        {
           // loop round to the start of the alphabet
           newIndex = (arrayIndex + rot13) - 26;
        }
        else newIndex = arrayIndex + rot13;


        if(fontCase == 'u') return uca[newIndex];
        else if(fontCase == 'l') return lca[newIndex];
        else cout << "\n\tERROR @ ROT13(), fontCase == " << fontCase << "\n\n";
    }
}

void update_gStr(char input)
{
    gStr += input;
}

void display_gStr()
{
    cout << "\n> " << gStr << "\n\n";
}
