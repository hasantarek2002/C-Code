#include<bits/stdc++.h>
using namespace std;
int main()
{

    int arr[]={5,1,1,1,0,2,3,6,5,4,2,1};
    int n,max=arr[0];
    cin >> n;
    for(int i=0;i<(sizeof(arr)/sizeof(arr[0])); i++)
    {
        if(max<arr[i])
            max=arr[i];
    }
    vector<int>myVec[max];
    for(int i=0; i< (sizeof(myVec)/sizeof(myVec[0])); i++)
    {
        for(int j=0; j<(sizeof(arr)/sizeof(arr[0])); j++)
        {
            if(arr[j]==n)
            {
                myVec[i].push_back(arr[j]);
            }
        }
    }
    for(int i=0;i<myVec[n-1].size(); i++)
        cout << myVec[n-1].front()<< "   ";
}
