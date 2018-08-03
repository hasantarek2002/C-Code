#include<iostream>
using namespace std;
int i,j,l1,l2,arr[2000][2000];
int main()
{
    string s1,s2;

    while(getline(cin,s1))
    {
        getline(cin,s2);
        l1=s1.size();
        l2=s2.size();
        for(i=1;i<=l1;i++)
            for(j=1;j<=l2;j++)
            {
                if(s1[i-1]==s2[j-1])
                arr[i][j]=arr[i-1][j-1]+1;
                else
                arr[i][j]=max(arr[i][j-1],arr[i-1][j]);
            }
        cout<<arr[l1][l2]<<endl;
    }
return 0;
}
