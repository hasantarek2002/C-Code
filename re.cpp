#include<iostream>
#include<string>

using namespace std;

int main(void)
{
    // Regular Expression 0* 1 (0 +1)*
    cout << "a is starting state, b is ending state." << endl;
    string s1;
    char a;

    cout << "Enter the string : ";
    cin >> s1;

    a='a';
    for(int i=0; i<s1.length(); i++)
    {
        if(s1[i]=='0')
        {
            if(a=='a')
            {
                a='a';
                cout << "a" << " --> " << a << endl;
            }
            else if(a=='b')
            {
                a='b';
                cout << a << " --> " << "b" << endl;
            }
        }
        else if(s1[i]=='1')
        {
            if(a=='a')
            {
                a='b';
                cout << "a" << " --> " << a << endl;
            }
            else if(a=='b')
            {
                a='b';
                cout << "b" << " --> " << a << endl;
            }
        }
    }
    cout << endl;
    if(a=='b')
        cout << "The input string is accepted by the regular expression." << endl;
    else
        cout << "The input string is not accepted by the regular expression." << endl;
    return 0;
}

