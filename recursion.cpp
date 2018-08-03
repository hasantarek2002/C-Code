#include<bits/stdc++.h>

using namespace std;

int fac(int n)
{
    if(n==0) return 1;
    int res=n*fac(n-1);
    return res;

}
int fib(int n)
{
    if(n<2)
        return n;
    int res=fib(n-1)+fib(n-2);
    return res;

}

int fibPrint(int n)
{
    if(n<2)
    {
        //cout << 0 << " ";
        cout << n << " ";
        return n;
    }
    /*
    else if(n==1)
    {
        cout << 1 << " ";
    }
    */

    else
    {
        int res=fibPrint(n-1)+fibPrint(n-2);
        cout <<res<< " ";
        //cout <<  fibPrint(n-1)+fibPrint(n-2) << " ";
        //cout << fibPrint(n-1) << " ";
        //cout << fibPrint(n-2) << " ";//+fibPrint(n-2) << " ";
        //cout << res << " " << endl;
        //cout <<
    }


}
int main()
{
    //cout << fac(5) << endl;
    //cout << fib(5) << endl;
    fibPrint(5);

    return 0;
}
