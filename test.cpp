#include<bits/stdc++.h>
#define PI 3.14159

using namespace std;

int main()
{
    int a,b,r;
    double circle,rectangle;
    cin >> a >> b >> r;
    r=r*2;
    circle=r*r;
    rectangle=a*b;
    int count=0;
    while((r<=a && r <=b))
    {
        count++;
        r+=r;

    }
    /*
    for(double i=circle; i<=rectangle; i=i+circle)
    {
        if(r<=a && r <=b)
        count++;
        r+=r;

    }
    */
    if(count %2==1)  cout << "First" << endl;
    else   cout << "Second" << endl;



    return 0;
}
