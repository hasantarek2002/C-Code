#include<iostream>
#include<string>

using namespace std;

int main ()
{
    string::iterator it;
    string s="has";

    for(int i=0; i<s.length(); i++)
    {
        for(int j=1; j<=s.length(); j++)
        {
            cout << s.substr(i,j) << "   ";
        }
        cout << endl;
    }


    //cout << s.substr(1,2) << endl;
    //cout << "string size is " << s.size() << endl;

    return 0;
}



