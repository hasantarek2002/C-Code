#include<bits/stdc++.h>

using namespace std;


int main ()
{
    long int a;
    long long int b,c,max;
    cin >> a;

    b=a+1;
    c=a+2;
    if((a>b) && (a>c))
    {
        max=a;
        if((max*max)==(b*b)+(c*c))
            cout << b << " " << c << endl;
        else cout << "-1" << endl;
    }

    else if((b>a) && (b>c))
    {
        max=b;
        if((max*max)==(a*a)+(c*c))
            cout << a << " " << c << endl;
        else cout << "-1" << endl;
    }

    else if((c>b) && (c>a))
    {
         max=c;
         if((max*max)==(b*b)+(a*a))
            cout << b << " " << a << endl;
        else cout << "-1" << endl;
    }



    return 0;
}
