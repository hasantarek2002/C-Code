#include<iostream>
#include<string>

using namespace std;

int main ()
{
    string::iterator it;
    string s="hasan tarek";
    //string str;
    //cin >> str;

    size_t found=s.find("t");
    cout << "string found at " << found << endl;

    cout << s << endl;
    cout << "string size is " << s.size() << endl;

    return 0;
}

