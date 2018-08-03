
#include<bits/stdc++.h>

using namespace std;
long long int arr[1000000];
int main ()
{
    int t;
    cin >> t;
    for(int I=0; I<t; I++)
    {
        int n;
        cin >> n;
        memset(arr,0,sizeof(arr));
        for(int i=0; i<n; i++)
        {
            cin >> arr[i];
        }
        sort(arr,arr+n);
        long long int sum=0,sum1=0;
        int count=0;
        for(int i=0; i<n; i++)
        {
            if((sum1+arr[i])>300)
                break;
            count++;
            sum1=sum1+arr[i];
            sum=sum+sum1;


        }

        cout << "Case " << I+1 << ": " << count << " " << sum << endl;


    }

    return 0;
}
