#include<iostream>
#include<string>

using namespace std;

int main ()
{
    string::iterator it;
    string s1="hasan tarek";

    string s2=s1.substr(2,6);

    cout << s2 << endl;
    cout << "string size is " << s2.size() << endl;

    return 0;
}


