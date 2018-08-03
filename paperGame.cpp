#include<iostream>

using namespace std;

int main ()
{
    int t;
    cin >> t;
    for(int i=0; i<t; i++)
    {
        int w,h,r;
        cin >> w >> h;
        r=w*h;
        if((r%2)==0) cout << "Hasan" << endl;
        else cout << "Hussain" << endl;
    }


    return 0;
}
