// Temperature Converter (Fahrenheit/Celsius)

#include<iostream>
#include<string>
#include<sstream>

using namespace std;

char knownType = '0';
int knownValue = 0;

string get_inputType();
bool test_inputTypeValidity(string);
void process_inputType();

string get_inputNumber();
bool test_inputNumberValidity(string);
void process_inputNumber();

void convert_temperature(char,int);

int main()
{
    cout << "\tTemperature Converter (Fahrenheit/Celsius)\n\n";

    process_inputType();

    return 0;
}

string get_inputType()
{
    cout << "temperature type (F/C): ";

    string inputType;
    getline(cin, inputType);

    return inputType;
}

bool test_inputTypeValidity(string it)
{
    // acceptable inputs include: "F f fahrenheit FAHRENHEIT Fahrenheit C c celsius CELSIUS Celsius"
    bool isValid = false;

    if(it == "F" || it == "f" || it == "FAHRENHEIT" || it == "fahrenheit" || it == "Fahrenheit")
    {
        isValid = true;
        knownType = 'F';
    }
    else if(it == "C" || it == "c" || it == "CELSIUS" || it == "celsius" || it == "Celsius")
    {
        isValid = true;
        knownType = 'C';
    }

    return isValid;
}

void process_inputType()
{
    if(!test_inputTypeValidity(get_inputType()))
    {
        cout << "\n\tInput not recognised.\n\tPlease use either \"F\" or \"C\".\n\n";
        process_inputType();
    }
    else
    {
        if(knownType == 'F' || knownType == 'C') process_inputNumber();
        else std::cout << "ERROR @ process_inputType(): knownType == " << knownType << std::endl;
    }
}

string get_inputNumber()
{
    cout << "input temperature [" << knownType << "]: ";

    string inputNum;
    getline(cin, inputNum);

    return inputNum;
}

bool test_inputNumberValidity(string in)
{
    bool isValid = false;

    int num;
    stringstream(in) >> num;

    // num will automatically default to "0" if the input is invalid
    if(num != 0 || in == "0") isValid = true;

    return isValid;
}

void process_inputNumber()
{
    if(!test_inputNumberValidity(get_inputNumber()))
    {
        cout << "\n\tInvalid input.\n\tPlease input an integer.\n\n";
        process_inputNumber();
    }
    else
    {
        convert_temperature(knownType, knownValue);
    }
}

void convert_temperature(char tType, int tValue)
{

}
