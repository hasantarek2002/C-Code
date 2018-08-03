#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>

using namespace std;
void replaceBracketSign(string &s)
{
    for(int i=0; i<s.length(); i++)
    {
        if(s[i]=='(')
            s[i]=')';
        else if(s[i]==')')
            s[i]='(';
    }
}
int main()
{
    string s="a+(b-c)";
    reverse(s.begin(),s.end());
    cout << s << endl;
    replaceBracketSign(s);
    cout << s << endl;
}
