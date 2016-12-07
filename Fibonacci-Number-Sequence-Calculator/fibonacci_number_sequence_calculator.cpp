#include<iostream>
#include<string>
#include<sstream>

using namespace std;

int main()
{
    cout << "A Fibonacci Number is equal to the sum of the previous two numbers in it's sequence.\n\n";
    cout << "Algorithm: Fn = Fn-1 + Fn-2\n\n";

    cout << "Enter the nth number: ";
    string input;
    getline(cin,input);

    int I;
    stringstream(input) >> I;

    if(I<0)
    {
        I = 1; // catches negative values.
        cout << "\n\tNegative values are disallowed.\n\tDefaulting to value \'1\'.\n\n";
    }

    float fNum[I];

    for(int i = 0; i<I; i++)
    {
        // logic
        if((i==0)||(i==1)) fNum[i] = 1;
        else fNum[i] = fNum[(i-1)] + fNum[(i-2)];

        // display
        if(i == 0) cout << "\tSequence: ";

        if (i == (I-1)) cout << fNum[i] << ".\n\n"; // end number format
        else cout << fNum[i] << ", ";               // middle number format
    }

    cout << "> " << fNum[I-1] << "\n\n";

    return 0;
}
